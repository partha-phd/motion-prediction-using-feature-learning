% Function to estimate the Time To Collision (TTC) for the ego vehicle
function [humanTTC, plannerTTC] = computeTTC(scenario, plannedTrajectory)
% Initialisation
humanTTC = ones(75, 1)*100;
plannerTTC = ones(75, 1)*100;
numTargets = size(scenario.Target, 2);

% Simulation settings
timeSteps = 0.04;
predictionTime = 8.0;
% Estimate the TTC for upto 3 seconds from the scenario start
numTimeSteps = 75;

idForPlanner = 1:40:3000;

for idTime = 1:numTimeSteps
    % Estimate the future position of the ego driven by humans
    % for the next five seconds
    minDistHuman = scenario.EGO.v_New(idTime)*predictionTime + ...
        0.5*scenario.EGO.ax_New(idTime)*predictionTime^2;
    m = predictionTime / timeSteps;
    sHuman = linspace(0, minDistHuman, m);
    exHuman = cosd(scenario.EGO.psi_New(idTime));
    eyHuman = sind(scenario.EGO.psi_New(idTime));
    t_x_human = sHuman.*exHuman;
    t_y_human = sHuman.*eyHuman;

    % Estimate the future position of the ego planned by the planner for
    % the next five seconds
    minDistPlanner = plannedTrajectory.v(idForPlanner(idTime))*...
        predictionTime + ...
        0.5*plannedTrajectory.ax(idForPlanner(idTime))*predictionTime^2;
    sPlanner = linspace(0, minDistPlanner, m);
    exPlanner = cos(plannedTrajectory.psi(idForPlanner(idTime)));
    eyPlanner = sin(plannedTrajectory.psi(idForPlanner(idTime)));
    t_x_planner = sPlanner.*exPlanner;
    t_y_planner = sPlanner.*eyPlanner;


    for idSimTime = 1:m
        % Upates of ego position with human driving
        pos_human(1) = scenario.EGO.xCG_New(idTime)+t_x_human(idSimTime);
        pos_human(2) = scenario.EGO.yCG_New(idTime)+t_y_human(idSimTime);
        % Bounding box of ego with human driving
        [xEGOHuman, yEGOHuman] = calcBoundingBox(pos_human(1),...
            pos_human(2),...
            deg2rad(scenario.EGO.psi_New(idTime)), ...
            scenario.EGO.bbox(1, 3), scenario.EGO.bbox(1, 4));

        % Updates of ego position with planner
        pos_planner(1) = plannedTrajectory.x(idForPlanner(idTime)) + ...
            t_x_planner(idSimTime);
        pos_planner(2) = plannedTrajectory.y(idForPlanner(idTime)) + ...
            t_y_planner(idSimTime);
        % Bounding box of ego with planner
        [xEGOPlanner, yEGOPlanner] = calcBoundingBox(pos_planner(1),...
            pos_planner(2), plannedTrajectory.psi(idForPlanner(idTime)), ...
            scenario.EGO.bbox(1, 3), scenario.EGO.bbox(1, 4));

        % Target position and its corresponding bounding box
        for idTarget = 1:numTargets
            [xTarget, yTarget] = ...
                calcBoundingBox(...
                scenario.Target(idTarget).xCG_New(idTime+idSimTime),...
                scenario.Target(idTarget).yCG_New(idTime+idSimTime),...
                deg2rad(scenario.Target(idTarget).psi_New(idTime+idSimTime)),...
                scenario.Target(idTarget).bbox(1, 3),...
                scenario.Target(idTarget).bbox(1, 4));
            
            % Check for collision between targets and human driven path
            in = inpolygon([xEGOHuman xEGOHuman(1)], ...
                [yEGOHuman yEGOHuman(1)],...
                [xTarget xTarget(1)], [yTarget yTarget(1)]);
            in1 = inpolygon([xTarget xTarget(1)], [yTarget yTarget(1)],...
                [xEGOHuman xEGOHuman(1)], [yEGOHuman yEGOHuman(1)]);

            % Check for collision between targets and planned path
            in2 = inpolygon([xEGOPlanner xEGOPlanner(1)], ...
                [yEGOPlanner yEGOPlanner(1)],...
                [xTarget xTarget(1)], [yTarget yTarget(1)]);
            in3 = inpolygon([xTarget xTarget(1)], [yTarget yTarget(1)],...
                [xEGOPlanner xEGOPlanner(1)], [yEGOPlanner yEGOPlanner(1)]);

            % Compute TTC
            if (any(in) || any(in1)) && ...
                    (humanTTC(idTime) > (idSimTime * 0.04))
                humanTTC(idTime) = idSimTime * 0.04;
            end

            if (any(in2) || any(in3)) && ...
                    (plannerTTC(idTime) > (idSimTime * 0.04))
                plannerTTC(idTime) = idSimTime * 0.04;
            end
        end
    end
end
end