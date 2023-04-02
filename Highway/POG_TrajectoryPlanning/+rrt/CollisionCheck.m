% Function - Collision check along the edge--------------------------------
function [collision, p_step, p_pos_step, p_angle_updated] = ...
    CollisionCheck(p_pos, p_angle, l_angle, gridConverted, EGO,...
    param, sampleTime)

% Initialisation
collision = 0;
p_angle_updated = p_angle;

% Checking for the change in the steering deviation
if (p_angle >=0 && p_angle <=90 && l_angle >= 270 && l_angle <=360)
    angle_diff = p_angle + (360-l_angle);
    if abs(angle_diff) > EGO.steerMax
        p_angle_updated = l_angle+EGO.steerMax;
    end
elseif (l_angle >=0 && l_angle <=90 && p_angle >= 270 && p_angle <=360)
    angle_diff = l_angle + (360-p_angle);
    if abs(angle_diff) > EGO.steerMax
        p_angle_updated = l_angle-EGO.steerMax;
    end
else
    angle_diff = l_angle-p_angle;
    if (abs(angle_diff) > EGO.steerMax) && (angle_diff <= 0)
        p_angle_updated = l_angle+EGO.steerMax;
    elseif (abs(angle_diff) > EGO.steerMax) && (angle_diff > 0)
        p_angle_updated = l_angle-EGO.steerMax;
    end
end
try
    if(p_angle_updated < 0)
        p_angle_updated = 360+p_angle_updated;
    end
catch
    disp('Error here');
end


ex=cosd(p_angle_updated);
ey=sind(p_angle_updated);
t_x = param.minDist*ex;
t_y = param.minDist*ey;
exOrtho=ex*cos(pi/2)+ey*sin(pi/2);
eyOrtho=-ex*sin(pi/2)+ey*cos(pi/2);

% Update the position of the ego
p_pos_step(1) = p_pos(1) + t_x;
p_pos_step(2) = p_pos(2) + t_y;

% Computation of the bounding boxes
P(1)=p_pos_step(1)+ex*(EGO.lf)+EGO.w/2*exOrtho;
P(5)=p_pos_step(2)+ey*(EGO.lf)+EGO.w/2*eyOrtho;
P(2)=p_pos_step(1)+ex*(EGO.lf)-EGO.w/2*exOrtho;
P(6)=p_pos_step(2)+ey*(EGO.lf)-EGO.w/2*eyOrtho;
P(3)=p_pos_step(1)-ex*(EGO.lr)+EGO.w/2*exOrtho;
P(7)=p_pos_step(2)-ey*(EGO.lr)+EGO.w/2*eyOrtho;
P(4)=p_pos_step(1)-ex*(EGO.lr)-EGO.w/2*exOrtho;
P(8)=p_pos_step(2)-ey*(EGO.lr)-EGO.w/2*eyOrtho;

% Conversion to grid
p_step(1) = round(p_pos_step(1)/param.gridResolutionX);
p_step(2) = round(p_pos_step(2)/param.gridResolutionY);
P_grid = [round(P(1:4)/param.gridResolutionX) ...
    round(P(5:8)/param.gridResolutionY)];

% Checking for occupancy value
try
    probOccupancy(1) = gridConverted(sampleTime + 1, p_step(2), p_step(1));
    probOccupancy(2) = gridConverted(sampleTime + 1, P_grid(5), P_grid(1));
    probOccupancy(3) = gridConverted(sampleTime + 1, P_grid(6), P_grid(2));
    probOccupancy(4) = gridConverted(sampleTime + 1, P_grid(7), P_grid(3));
    probOccupancy(5) = gridConverted(sampleTime + 1, P_grid(8), P_grid(4));
catch
    collision = 1;
    return;
end

% If above the set threshold, declare the step as collision
if any(probOccupancy > param.minThresh)
    collision = 1;
    return;
end
end




