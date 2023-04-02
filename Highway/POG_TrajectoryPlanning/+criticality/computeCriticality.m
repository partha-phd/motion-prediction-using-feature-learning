function [humanTTCResult, humanTHWResult,...
    plannerTTCResult, plannerTHWResult, humanRP, plannerRP] = ...
    computeCriticality(scenario, plannedTrajectory)

% Initialisation
numTargets = size(scenario.Target, 2);
numTimeSteps = 75;
humanTTC = nan(numTimeSteps, numTargets);
humanTHW = nan(numTimeSteps, numTargets);
plannerTTC = nan(numTimeSteps, numTargets);
plannerTHW = nan(numTimeSteps, numTargets);

idForPlanner = 1:40:3000;

% Identification of the leading vehicle with ego being follower at each
% time instance and compute the corresponding TTC
for idTime = 1:numTimeSteps
    for idTarget = 1:numTargets
        yPosDiffHuman = scenario.EGO.yCG_New(idTime) - ...
            scenario.Target(idTarget).yCG_New(idTime);
        xPosDiffHuman = scenario.Target(idTarget).xCG_New(idTime) - ...
            scenario.EGO.xCG_New(idTime);
        xPosDiffPlanner = scenario.Target(idTarget).xCG_New(idTime) - ...
            plannedTrajectory.x(idForPlanner(idTime));
        yPosDiffPlanner = scenario.Target(idTarget).yCG_New(idTime) - ...
            plannedTrajectory.y(idForPlanner(idTime));
        % Compute metrics for human driven trajectories
        if abs(yPosDiffHuman) <= 2 && xPosDiffHuman > 0
            humanTTC(idTime, idTarget) = xPosDiffHuman / ...
                (scenario.EGO.v_New(idTime) - ...
                scenario.Target(idTarget).v_New(idTime));
            humanTHW(idTime, idTarget) = xPosDiffHuman / ...
                scenario.EGO.v_New(idTime);
        end
        % Compute metrics for planner driven trajectories
        if abs(yPosDiffPlanner) <= 2 && xPosDiffPlanner > 0
            plannerTTC(idTime, idTarget) = xPosDiffPlanner / ...
                (plannedTrajectory.v(idForPlanner(idTime)) - ...
                scenario.Target(idTarget).v_New(idTime));
            plannerTHW(idTime, idTarget) = xPosDiffPlanner / ...
                plannedTrajectory.v(idForPlanner(idTime));
        end
    end
end
% Obtain the end results from multiple target vehicles
humanTTCResult = min(humanTTC, [],  2);
humanTHWResult = min(humanTHW, [],  2);
plannerTTCResult = min(plannerTTC, [],  2);
plannerTHWResult = min(plannerTHW, [],  2);
% Compute the risk perception (RP) indicator
% Values of 1 and 4 are taken from literature
humanRP = (1 ./ humanTHWResult) + (4 ./ humanTTCResult);
plannerRP = (1 ./ plannerTHWResult) + (4 ./ plannerTTCResult);
end


