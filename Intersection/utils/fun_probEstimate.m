% Function to estimate probabilities for the main hypotheses
function [Target, assignIssues] = fun_probEstimate(Target, pos, leftVehicle,...
    rightVehicle, bottomVehicle)

% Number of targets
noOfTarget = size(Target,2);
assignIssues = false;

% Possible hypotheses
for i = 1:noOfTarget
    Target(i).FL = 0; % follow lane
    Target(i).TR = 0; % turn right
    Target(i).TL = 0; % turn left
    Target(i).xDesired.Straight = [];
    Target(i).yDesired.Straight = [];
    Target(i).xDesired.Left = [];
    Target(i).yDesired.Left = [];
    Target(i).xDesired.Right = [];
    Target(i).yDesired.Right = [];
end

% Determining the main hypotheses
for i = 1:noOfTarget
    % Rules for vehicle approaching from left
    if (inpolygon(Target(i).xPos, Target(i).yPos, pos.x1, pos.y1))
        if (Target(i).psi <= 0.34 || Target(i).psi >= 5.93)...
                && (abs(Target(i).ay)<0.2)% --> check if AND necessary
            if Target(i).vel > 10
                Target(i).FL = 1;
            else
                Target(i).FL = 0.8;
                Target(i).TR = 0.2;
            end
        else
            Target(i).FL = 0.3;
            Target(i).TR = 0.7;
        end
        if Target(i).FL == 1
            Target(i).xDesired.Straight = leftVehicle.xDesired.Straight;
            Target(i).yDesired.Straight = leftVehicle.yDesired.Straight;
        else
            Target(i).xDesired.Straight = leftVehicle.xDesired.Straight;
            Target(i).yDesired.Straight = leftVehicle.yDesired.Straight;
            Target(i).xDesired.Right = leftVehicle.xDesired.Right;
            Target(i).yDesired.Right = leftVehicle.yDesired.Right;
        end
        Target(i).direction = 'left';
        
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x2,...
            pos.y2) && (Target(i).psi <= 0.34 || Target(i).psi >= 5.93))
        Target(i).FL = 1;
        Target(i).xDesired.Straight = leftVehicle.xDesired.Straight;
        Target(i).yDesired.Straight = leftVehicle.yDesired.Straight;
        Target(i).direction = 'left';
        
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x3,...
            pos.y3) && (Target(i).psi < 5.4 && Target(i).psi < 4)...
            && Target(i).ay <= 0)
        Target(i).TR = 1;
        Target(i).xDesired.Right = leftVehicle.xDesired.Right;
        Target(i).yDesired.Right = leftVehicle.yDesired.Right;
        Target(i).direction = 'left';
        
        % Rules for vehicle approaching from right
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x4, pos.y4))
        if  ((Target(i).psi >= 2.8 && Target(i).psi <= 3.5) &&...
                (abs(Target(i).ay)<0.2)) % --> check if AND necessary
            if Target(i).vel > 10
                Target(i).FL = 1;
            else
                Target(i).FL = 0.8;
                Target(i).TL = 0.2;
            end
        else
            Target(i).FL = 0.3;
            Target(i).TL = 0.7;
        end
        if Target(i).FL == 1
            Target(i).xDesired.Straight = rightVehicle.xDesired.Straight;
            Target(i).yDesired.Straight = rightVehicle.yDesired.Straight;
        else
            Target(i).xDesired.Straight = rightVehicle.xDesired.Straight;
            Target(i).yDesired.Straight = rightVehicle.yDesired.Straight;
            Target(i).xDesired.Left = rightVehicle.xDesired.Left;
            Target(i).yDesired.Left = rightVehicle.yDesired.Left;
        end
        
        Target(i).direction = 'right';
        
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x5,...
            pos.y5) && (Target(i).psi >= 2.8 && Target(i).psi <= 3.5))
        Target(i).FL = 1;
        Target(i).xDesired.Straight = rightVehicle.xDesired.Straight;
        Target(i).yDesired.Straight = rightVehicle.yDesired.Straight;
        Target(i).direction = 'right';
        
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x6,...
            pos.y6) && (Target(i).psi >= 3.5 &&...
            Target(i).psi <= 5.0) && Target(i).ay >= 0)
        Target(i).TL = 1;
        Target(i).xDesired.Left = rightVehicle.xDesired.Left;
        Target(i).yDesired.Left = rightVehicle.yDesired.Left;
        Target(i).direction = 'right';
        
        % Rules for vehicle approaching from bottom
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x7, pos.y7))
        if ((Target(i).psi >= 1.4 && Target(i).psi <= 2.3) &&...
                abs(Target(i).ay)<0.4)
            Target(i).TR = 0.5;
            Target(i).TL = 0.5;
        elseif Target(i).ay >= 0.4
            Target(i).TL = 1;
        elseif Target(i).ay <= -0.4
            Target(i).TR = 1;
        end
        Target(i).xDesired.Left = bottomVehicle.xDesired.Left;
        Target(i).yDesired.Left = bottomVehicle.yDesired.Left;
        Target(i).xDesired.Right = bottomVehicle.xDesired.Right;
        Target(i).yDesired.Right = bottomVehicle.yDesired.Right;
        Target(i).direction = 'bottom';
        
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x8,...
            pos.y8) && Target(i).ay <=-0.4)
        Target(i).TR = 1;
        Target(i).xDesired.Right = bottomVehicle.xDesired.Right;
        Target(i).yDesired.Right = bottomVehicle.yDesired.Right;
        Target(i).direction = 'bottom';
        
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x9,...
            pos.y9) && Target(i).ay >=0.4)
        Target(i).TL = 1;
        Target(i).xDesired.Left = bottomVehicle.xDesired.Left;
        Target(i).yDesired.Left = bottomVehicle.yDesired.Left;
        Target(i).direction = 'bottom';
    end
    if (Target(i).FL == 0 && Target(i).TR == 0 && Target(i).TL == 0)
        disp(['Could not assign probability for ' num2str(i)]);
        assignIssues = true;
    end
end
end
