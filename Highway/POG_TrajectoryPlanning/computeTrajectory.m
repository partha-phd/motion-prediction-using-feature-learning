% Planning of safe trajectory for the ego vehicle based on the estimated
% Predicted Occupancy Grids
clc; clearvars; close all;

% Load a scenario
cd ..
load([pwd '/POG_DataGeneration/generatedData_220315/9.mat']);

% Visualisation of the initial constellation
predictedGrid = flip(POGForScenario, 2);
[row, col] = find(squeeze(predictedGrid(1,:,:))>0.01);
figure(1);
axis([1 400 1 30])
s1 = scatter(col, row, 'k', 's', 'filled');
hold on
axis equal
title('Grid based view of traffic participants');
figure(2);
axis([1 200 1 15])
s2 = scatter(col*0.5, row*0.5, 'k', 's', 'filled');
hold on
axis equal
xlabel('X in [m]');
ylabel('Y in [m]');
title('Cartesian based view of traffic participants');

% Ego vehicle data at the start
scenarioInfo.EGO.lf = scenarioInfo.EGO.bbox(1,3) / 2;
scenarioInfo.EGO.lr = scenarioInfo.EGO.lf;
scenarioInfo.EGO.w = scenarioInfo.EGO.bbox(1,4);
scenarioInfo.EGO.steerMax = 0.5;
egoStartVel = scenarioInfo.EGO.v_New(1);
egoStartAccelX = scenarioInfo.EGO.ax_New(1);
egoStartAccelY = scenarioInfo.EGO.ay_New(1);
egoStartPsi = scenarioInfo.EGO.psi_New(1);
pathFound = false;
egoStopVel = egoStartVel;

% Parameters of RRT algorithm (subject to tuning)
param.maxIter = 3000;
param.minThresh = 0.1; % minimum probability of occupancy
param.RRTSampleTime = 0.04;
param.stopThresh = 4.0; % distance around the goal to stop simulation
param.plotGraph = false;
param.planningTime = 3.0;
param.gridResolutionX = 0.5;
param.gridResolutionY = 0.5;
param.sampleValueX = [10 400];
param.sampleValueY = [5 25];
param.sampleBias = 100; % for every sampleBias iteration, goal point will be sampled
param.reduceVelValue = 1;

% Define the start position for the planner
p_pos_start(1) = scenarioInfo.EGO.xCG_New(1);
p_pos_start(2) = scenarioInfo.EGO.yCG_New(1);
p_start(1) = p_pos_start(1) / param.gridResolutionX;
p_start(2) = p_pos_start(2) / param.gridResolutionY;


% Iterative approach to derive a safe trajectory
while ~pathFound

    param.minDist = ((egoStartVel + egoStopVel) / 2) * param.RRTSampleTime; % distance constraint

    % Ego vehicle data at the goal
    distMoved = ((egoStartVel + egoStopVel) / 2) * param.planningTime;
    tx_pos = distMoved*cosd(0);
    ty_pos = distMoved*sind(0);
    p_pos_goal(1) = p_pos_start(1) + tx_pos;
    p_pos_goal(2) = p_pos_start(2) + ty_pos;
    p_goal(1) = round(p_pos_goal(1) / param.gridResolutionX);
    p_goal(2) = round(p_pos_goal(2) / param.gridResolutionY); % grid position

    % Plot the start and the goal point
    figure(1)
    scatter(p_start(1), p_start(2), 'r', 'filled', 'd');
    scatter(p_goal(1), p_goal(2), 'b', 'filled', 'd');
    legend('Occupied', 'Start', 'Goal');
    legend('AutoUpdate', 'off')
    figure(2);
    scatter(p_pos_start(1), p_pos_start(2), 'r', 'filled', 'd');
    scatter(p_pos_goal(1), p_pos_goal(2), 'b', 'filled', 'd');
    legend('Occupied', 'Start', 'Goal');
    legend('AutoUpdate', 'off')
    delete(s1)
    delete(s2)

    % Initialise the tree
    tree = {};
    tree = rrt.AddNode(tree, p_start, p_pos_start, 0, egoStartPsi, 1, 1);

    % Path planner
    tic
    [tree, iter] = rrt.PathPlanner(p_goal, p_pos_goal, predictedGrid,...
        tree, scenarioInfo.EGO, param);
    timeTaken = toc;

    % Extracting the path from tree
    i = length(tree);
    % Select the node that is closest to the goal as well as a terminal node
    for j = 1:i
        dist = sqrt((tree{j}.p(1) -p_goal(1))^2 + (tree{j}.p(2)-p_goal(2))^2);
        if (j == 1) || (dist < mindist) && (tree{j}.terminalNode == 1)
            mindist = dist;
            imin = j;
        end
    end

    figure(1);
    scatter(tree{imin}.p(1), tree{imin}.p(2),...
        'g', 'filled', 'd', 'LineWidth', 2);
    P = tree{imin}.p';
    P_pos = tree{imin}.p_pos';
    P_angle = tree{imin}.angPrev;
    j = imin;
    while 1
        j = tree{j}.iPrev;
        if j == 0
            break
        end
        P = [tree{j}.p' P];
        P_pos = [tree{j}.p_pos' P_pos];
        P_angle = [tree{j}.angPrev P_angle];
    end

    % Reduce the goal velocity for the next iteration
    if size(P,2) <= 70
        egoStopVel = egoStopVel - param.reduceVelValue;
    else
        pathFound = true;
    end
    if ~pathFound
        disp('Could not find valid path');
    else
        fprintf('Time taken for the RRT algorithm to find a path is %d \n',...
            timeTaken);
        fprintf('The number of iterations taken is %d \n', iter-1);
    end
end
% Computation of the smooth trajectory based on vehicle dynamics
plannedTrajectory = rrt.Controller(P_pos(1,:), P_pos(2,:),...
    egoStartVel, egoStopVel, param.planningTime, scenarioInfo.EGO);

idForPlanner = 1:40:3000;

% Plot the trajectories
for idTime = 1:size(P,2)
    figure(2);
    % Plot the ego vehicle
    [xBox, yBox] = ...
        calcBoundingBox(scenarioInfo.EGO.xCG_New(idTime),...
        scenarioInfo.EGO.yCG_New(idTime),...
        deg2rad(scenarioInfo.EGO.psi_New(idTime)),...
        scenarioInfo.EGO.bbox(idTime, 3),...
        scenarioInfo.EGO.bbox(idTime, 4));  
    plotH(1) = patch(xBox, yBox, 'r', 'facealpha', 0.2);
    
    [xBox, yBox] = ...
        calcBoundingBox(plannedTrajectory.x(idForPlanner(idTime)),...
        plannedTrajectory.y(idForPlanner(idTime)),...
        plannedTrajectory.psi(idForPlanner(idTime)),...
        scenarioInfo.EGO.bbox(idTime, 3), ...
        scenarioInfo.EGO.bbox(idTime, 4));
    plotH(end+1) = patch(xBox, yBox, 'b', 'facealpha', 0.2);

    for idTarget = 1:size(scenarioInfo.Target,2)
        [xBox, yBox] = ...
            calcBoundingBox(scenarioInfo.Target(idTarget).xCG_New(idTime),...
            scenarioInfo.Target(idTarget).yCG_New(idTime),...
            deg2rad(scenarioInfo.Target(idTarget).psi_New(idTime)),...
            scenarioInfo.Target(idTarget).bbox(idTime, 3),...
            scenarioInfo.Target(idTarget).bbox(idTime, 4));
        plotH(end + 1) = patch(xBox, yBox, 'g', 'facealpha', 0.2);
    end
end

% Computation of the criticality metrics for both human driven and planned
% trajectory
[humanTTC, humanTHW, plannerTTC, plannerTHW, humanRP, plannerRP] = ...
    criticality.computeCriticality(scenarioInfo, plannedTrajectory);

% Plot the criticality metrics 
xAxis = (1:75).*0.04;
figure;
subplot(3,1,1);
plot(xAxis, humanTTC, 'r', 'LineWidth', 2);
hold on
plot(xAxis, plannerTTC, 'b', 'LineWidth', 2);
title('Time To Collision (TTC)');
xlabel('Time in [s]')

subplot(3,1,2);
plot(xAxis, humanTHW, 'r', 'LineWidth', 2);
hold on
plot(xAxis, plannerTHW, 'b', 'LineWidth', 2);
title('Time Headway (THW)');
xlabel('Time in [s]')

subplot(3,1,3);
plot(xAxis, humanRP, 'r', 'LineWidth', 2);
hold on
plot(xAxis, plannerRP, 'b', 'LineWidth', 2);
title('Risk Perception Indicator (RP)');
xlabel('Time in [s]')
