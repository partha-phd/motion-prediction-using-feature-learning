% Function - Path planner-------------------------------------------------
function [tree, iter] = PathPlanner(p_goal, p_pos_goal, occGrid,...
    tree, EGO, param)

% Initialisation
iter = 1;
sampleTime = 1;

while iter <= param.maxIter
    % Choose a random point and sometime biased based on the goal
    if rem(iter, param.sampleBias) == 0
        p_rand(2) = p_goal(2);
        p_rand(1) = p_goal(1);
    else
        p_rand(2) = randsample(param.sampleValueY, 1);
        p_rand(1) = randsample(param.sampleValueX, 1);
    end

    % Conversion from grid to position
    p_pos_rand(2) = p_rand(2) * param.gridResolutionY;
    p_pos_rand(1) = p_rand(1) * param.gridResolutionX;

    % Plot the selected random node
    if param.plotGraph
        figure(1)
        plotObject(1) = scatter(p_rand(1), p_rand(2), 'ro');
        figure(2)
        plotObject(3) = scatter(p_pos_rand(1), p_pos_rand(2), 'ro');
    end

    % Select the nearest vertex to the chosen random vertex
    for i = 1:length(tree)

        % Heuristic 1 - Calculate the distance between the vertices
        dist =sqrt((tree{i}.p(1) -p_rand(1))^2 + (tree{i}.p(2)-p_rand(2))^2);
        % Heuristic 2 - Angle deviation required
        p_angle = atan2d(p_pos_rand(2)-tree{i}.p(2)*0.5,...
            p_pos_rand(1)-tree{i}.p(1)*0.5) + ...
            360*(p_pos_rand(2)-tree{i}.p(2)*0.5<0);
        l_angle = tree{i}.angPrev;

        if (p_angle >=0 && p_angle <=90 && l_angle >= 270 && l_angle <=360)
            angle_diff = p_angle + (360-l_angle);
        elseif (l_angle >=0 && l_angle <=90 && p_angle >= 270 && p_angle <=360)
            angle_diff = l_angle + (360-p_angle);
        else
            angle_diff = l_angle-p_angle;
        end

        % Cost
        if (angle_diff > 0)
            cost = dist + abs(angle_diff)*1.5;
        else
            cost = dist + abs(angle_diff);
        end
        if (i == 1) || (cost < mincost)
            mincost = cost;
            imin = i;
            l = tree{i}.p;
            l_pos = tree{i}.p_pos;
            l_angle = tree{i}.angPrev;
            sampleTime = tree{i}.sampleTime;
        end
    end

    % Convert grid to position
    p_pos(2) = l_pos(2);
    p_pos(1) = l_pos(1);

    % Plot the selected nearest vertex
    if param.plotGraph
        figure(1)
        plotObject(5) = scatter(l(1), l(2), 'b*');
        figure(2)
        plotObject(6) = scatter(p_pos(1), p_pos(2), 'b*');
    end

    % Find a path from the selected nearest vertex to chosen random vertex
    [collision, p_step, p_pos_step, p_angle_update] = ...
        rrt.CollisionCheck(p_pos,...
        p_angle, l_angle, occGrid, EGO, param, sampleTime);

    % Skip to next iteration if it is not valid edge
    if collision == 1
        iter = iter+1;
        if param.plotGraph
            delete(plotObject);
        end
        continue
    end

    % Plot the selected nearest node
    if param.plotGraph
        figure(1);
        plotObject(7) = scatter(p_step(1), p_step(2), 'k', 'filled');
        figure(2);
        plotObject(8) = scatter(p_pos_step(1), p_pos_step(2), 'k', 'filled');
    end

    % Increment the sample time by 1 when a valid vertex is found
    sampleTime = sampleTime+1;

    % Add the valid vertex to the tree
    tree = rrt.AddNode(tree, p_step, p_pos_step, imin,...
        p_angle_update, sampleTime, 1);

    % Calculating the distance to the goal
    dist = norm(p_pos_step-p_pos_goal);

    % Considering the distance to the goal
    if (dist <= param.stopThresh) || (iter >= param.maxIter) ||...
            (param.RRTSampleTime * sampleTime == param.planningTime)
        break
    end
    iter = iter+1;
    if param.plotGraph
        delete(plotObject)
    end
end
end