% Function to estimate probabilities for the main hypotheses
function [Target, assignIssues] = fun_probEstimate(Target, pos, left,...
    right, bottom, top)

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
    % Rules for vehicle approaching from bottom
    if (inpolygon(Target(i).xPos, Target(i).yPos, pos.x1, pos.y1))
        Target(i).FL = 0.33;
        Target(i).TR = 0.33;
        Target(i).TL = 0.33;
        if Target(i).psi < 0.5 && Target(i).psi > 5.7
            Target(i).xDesired.Straight = left.left.xDesired;
            Target(i).yDesired.Straight = left.left.yDesired;
            Target(i).xDesired.Right = left.straight.xDesired;
            Target(i).yDesired.Right = left.straight.yDesired;
            Target(i).xDesired.Left = left.left.xDesired;
            Target(i).yDesired.Left = left.left.yDesired;
        else
            Target(i).xDesired.Straight = bottom.straight.xDesired;
            Target(i).yDesired.Straight = bottom.straight.yDesired;
            Target(i).xDesired.Right = bottom.right.xDesired;
            Target(i).yDesired.Right = bottom.right.yDesired;
            Target(i).xDesired.Left = bottom.left.xDesired;
            Target(i).yDesired.Left = bottom.left.yDesired;
        end
        Target(i).direction = 'bottom';
        
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x2, pos.y2))
        Target(i).TR = 1;
        Target(i).xDesired.Right = bottom.right.xDesired;
        Target(i).yDesired.Right = bottom.right.yDesired;
        Target(i).direction = 'bottom';
        
        % Rules for vehicle approaching from right
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x3, pos.y3))
        Target(i).TR = 0.33;
        Target(i).FL = 0.33;
        Target(i).TL = 0.33;
        if Target(i).psi > 1.22 && Target(i).psi < 1.91
            Target(i).xDesired.Straight = bottom.left.xDesired;
            Target(i).yDesired.Straight = bottom.left.yDesired;
            Target(i).xDesired.Right = bottom.straight.xDesired;
            Target(i).yDesired.Right = bottom.straight.yDesired;
            Target(i).xDesired.Left = bottom.left.xDesired;
            Target(i).yDesired.Left = bottom.left.yDesired;
        else
            Target(i).xDesired.Straight = right.straight.xDesired;
            Target(i).yDesired.Straight = right.straight.yDesired;
            Target(i).xDesired.Right = right.right.xDesired;
            Target(i).yDesired.Right = right.right.yDesired;
            Target(i).xDesired.Left = right.left.xDesired;
            Target(i).yDesired.Left = right.left.yDesired;
        end
        Target(i).direction = 'right';
        
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x4, pos.y4))
        Target(i).TR = 1;
        Target(i).xDesired.Right = right.right.xDesired;
        Target(i).yDesired.Right = right.right.yDesired;
        Target(i).direction = 'right';
        
        % Rules for vehicle approaching from top
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x5,pos.y5))
        Target(i).FL = 0.33;
        Target(i).TR = 0.33;
        Target(i).TL = 0.33;
        if Target(i).psi > 2.79 && Target(i).psi < 3.5
            Target(i).xDesired.Straight = right.left.xDesired;
            Target(i).yDesired.Straight = right.left.yDesired;
            Target(i).xDesired.Right = right.straight.xDesired;
            Target(i).yDesired.Right = right.straight.yDesired;
            Target(i).xDesired.Left = right.left.xDesired;
            Target(i).yDesired.Left = right.left.yDesired;
            
        else
            Target(i).xDesired.Straight = top.straight.xDesired;
            Target(i).yDesired.Straight = top.straight.yDesired;
            Target(i).xDesired.Right = top.right.xDesired;
            Target(i).yDesired.Right = top.right.yDesired;
            Target(i).xDesired.Left = top.left.xDesired;
            Target(i).yDesired.Left = top.left.yDesired;
        end
        Target(i).direction = 'top';
        
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x6, pos.y6))
        Target(i).TR = 1;
        Target(i).xDesired.Right = top.right.xDesired;
        Target(i).yDesired.Right = top.right.yDesired;
        Target(i).direction = 'top';
        
        % Rules for vehicle approaching from left
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x7, pos.y7))
        Target(i).TR = 0.33;
        Target(i).TL = 0.33;
        Target(i).FL = 0.33;
        if Target(i).psi > 4.36 && Target(i).psi < 5.06
            Target(i).xDesired.Left = top.left.xDesired;
            Target(i).yDesired.Left = top.left.yDesired;
            Target(i).xDesired.Right = top.straight.xDesired;
            Target(i).yDesired.Right = top.straight.yDesired;
            Target(i).xDesired.Straight = top.left.xDesired;
            Target(i).yDesired.Straight = top.left.yDesired;
        else
            Target(i).xDesired.Left = left.left.xDesired;
            Target(i).yDesired.Left = left.left.yDesired;
            Target(i).xDesired.Right = left.right.xDesired;
            Target(i).yDesired.Right = left.right.yDesired;
            Target(i).xDesired.Straight = left.straight.xDesired;
            Target(i).yDesired.Straight = left.straight.yDesired;
        end
        Target(i).direction = 'left';
        
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x8,pos.y8))
        Target(i).TR = 1;
        Target(i).xDesired.Right = left.right.xDesired;
        Target(i).yDesired.Right = left.right.yDesired;
        Target(i).direction = 'left';
    end
    if (inpolygon(Target(i).xPos, Target(i).yPos, pos.x9, pos.y9))
        if Target(i).ay < -0.5 || Target(i).psi < 0.52
            Target(i).TR = 1;
            Target(i).xDesired.Right = bottom.right.xDesired;
            Target(i).yDesired.Right = bottom.right.yDesired;
            Target(i).xDesired.Straight = [];
            Target(i).yDesired.Straight = [];
            Target(i).xDesired.Left = [];
            Target(i).yDesired.Left = [];
        else
            Target(i).FL = 0.5;
            Target(i).TL = 0.5;
            Target(i).xDesired.Right = [];
            Target(i).yDesired.Right = [];
            Target(i).xDesired.Straight = bottom.straight.xDesired;
            Target(i).yDesired.Straight = bottom.straight.yDesired;
            Target(i).xDesired.Left = bottom.left.xDesired;
            Target(i).yDesired.Left = bottom.left.yDesired;
        end
        Target(i).direction = 'bottom';
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x10, pos.y10))
        if Target(i).ay < -0.5 || Target(i).psi < 2.09
            Target(i).TR = 1;
            Target(i).xDesired.Right = right.right.xDesired;
            Target(i).yDesired.Right = right.right.yDesired;
            Target(i).xDesired.Straight = [];
            Target(i).yDesired.Straight = [];
            Target(i).xDesired.Left = [];
            Target(i).yDesired.Left = [];
        else          
            Target(i).FL = 0.5;
            Target(i).TL = 0.5;
            Target(i).xDesired.Right = [];
            Target(i).yDesired.Right = [];
            Target(i).xDesired.Straight = right.straight.xDesired;
            Target(i).yDesired.Straight = right.straight.yDesired;
            Target(i).xDesired.Left = right.left.xDesired;
            Target(i).yDesired.Left = right.left.yDesired;
        end
        Target(i).direction = 'right';
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x11, pos.y11))
        if Target(i).ay < -0.5 || Target(i).psi < 3.67
            Target(i).TR = 1;
            Target(i).xDesired.Right = top.right.xDesired;
            Target(i).yDesired.Right = top.right.yDesired;
            Target(i).xDesired.Straight = [];
            Target(i).yDesired.Straight = [];
            Target(i).xDesired.Left = [];
            Target(i).yDesired.Left = [];
        else          
            Target(i).FL = 0.5;
            Target(i).TL = 0.5;
            Target(i).xDesired.Right = [];
            Target(i).yDesired.Right = [];
            Target(i).xDesired.Straight = top.straight.xDesired;
            Target(i).yDesired.Straight = top.straight.yDesired;
            Target(i).xDesired.Left = top.left.xDesired;
            Target(i).yDesired.Left = top.left.yDesired;
        end
        Target(i).direction = 'top';
    elseif (inpolygon(Target(i).xPos, Target(i).yPos, pos.x12, pos.y12))
        if Target(i).ay < -0.5 || Target(i).psi < 5.24
            Target(i).TR = 1;
            Target(i).xDesired.Right = left.right.xDesired;
            Target(i).yDesired.Right = left.right.yDesired;
            Target(i).xDesired.Straight = [];
            Target(i).yDesired.Straight = [];
            Target(i).xDesired.Left = [];
            Target(i).yDesired.Left = [];
        else       
            Target(i).FL = 0.5;
            Target(i).TL = 0.5;
            Target(i).xDesired.Right = [];
            Target(i).yDesired.Right = [];
            Target(i).xDesired.Straight = left.straight.xDesired;
            Target(i).yDesired.Straight = left.straight.yDesired;
            Target(i).xDesired.Left = left.left.xDesired;
            Target(i).yDesired.Left = left.left.yDesired;
        end
        Target(i).direction = 'left';
    end
    if (Target(i).FL == 0 && Target(i).TR == 0 && Target(i).TL == 0)
        disp(['Could not assign probability for ' num2str(i)]);
        assignIssues = true;
    end
end
end
