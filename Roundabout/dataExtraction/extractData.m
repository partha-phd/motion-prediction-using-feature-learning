%--------------------------------------------------------------------------
%            Parthasarathy Nadarajan
%            CARISSMA & Technische Hochschule Ingolstadt (THI)
%            EXTRACTION OF INFORMATION FROM THE RECORDED DATA
%            TYPE OF SCENARIO: ROUNDABOUT NEAR OUTDOOR FACILITY
%            SENSOR: DRONE
%--------------------------------------------------------------------------
clc; clearvars; close all;

% Load the road infrastructure - recorded using SP80
load('roadInfrastructure'); % <-- Road points
load('GCP_struct'); % <-- Ground control points
load('resolution'); % <-- Information for pixel to metre conversion
figure(1);
plot(xRoad, yRoad, 'g*'); hold on; axis equal;

% Rotate and translate the ground control points
rotAngle = -20; % manually found
R = [cosd(rotAngle) -sind(rotAngle); sind(rotAngle) cosd(rotAngle)];
rotated_North = [GCP_north.x GCP_north.y]*R;
rotated_South = [GCP_south.x GCP_south.y]*R;
x_GCPNorth = rotated_North(1)-590; % manually found
y_GCPNorth = rotated_North(2)-160; % manually found
x_GCPSouth = rotated_South(1)-590;% manually found
y_GCPSouth = rotated_South(2)-160;% manually found
plot(x_GCPNorth, y_GCPNorth, 'r*');
plot(x_GCPSouth, y_GCPSouth, 'b*');

% Load the scenarios
load('DJI_0050_fhd_reg_Tracking_Output_191112.mat');
videoID = 1;
% Rotate and translate the data from drone
x_GCPNorth_Image = resolution(videoID).xPixel_GCPNorth*...
    resolution(videoID).value;
y_GCPNorth_Image = (1080*resolution(videoID).value - ...
    resolution(videoID).yPixel_GCPNorth*resolution(videoID).value);
x_GCPSouth_Image = resolution(videoID).xPixel_GCPSouth*...
    resolution(videoID).value;
y_GCPSouth_Image = (1080*resolution(videoID).value - ...
    resolution(videoID).yPixel_GCPSouth*resolution(videoID).value);

% Angle between the measurements from SP80 and drone
angle_SP80 = atan2((y_GCPNorth-y_GCPSouth), (x_GCPNorth-x_GCPSouth));
angle_Drone = atan2((y_GCPNorth_Image-y_GCPSouth_Image),...
    (x_GCPNorth_Image-x_GCPSouth_Image));
rotAngle = -(angle_SP80-angle_Drone);
% Rotation
R = [cos(rotAngle) -sin(rotAngle); sin(rotAngle) cos(rotAngle)];
rotated_NorthImage = [x_GCPNorth_Image y_GCPNorth_Image]*R;
rotated_SouthImage = [x_GCPSouth_Image y_GCPSouth_Image]*R;
% Translation
diffX = x_GCPNorth-rotated_NorthImage(1);
diffY = y_GCPNorth-rotated_NorthImage(2);
x_GCPNorth_Image_1 = rotated_NorthImage(1)+diffX;
y_GCPNorth_Image_1 = rotated_NorthImage(2)+diffY;
x_GCPSouth_Image_1 = rotated_SouthImage(1)+diffX;
y_GCPSouth_Image_1 = rotated_SouthImage(2)+diffY;
figure(1);
plot(x_GCPNorth_Image_1, y_GCPNorth_Image_1, 'bo');
plot(x_GCPSouth_Image_1, y_GCPSouth_Image_1, 'bo');
scenario.posX = zeros(size(posXCleaned,1), size(posXCleaned,2));
scenario.posY = zeros(size(posXCleaned,1), size(posXCleaned,2));
scenario.v = zeros(size(posXCleaned,1), size(posXCleaned,2));
scenario.psi = zeros(size(posXCleaned,1), size(posXCleaned,2));
scenario.aX = zeros(size(posXCleaned,1), size(posXCleaned,2));
scenario.aY = zeros(size(posXCleaned,1), size(posXCleaned,2));
scenario.vehLength = zeros(size(posXCleaned,1), size(posXCleaned,2));
scenario.vehWidth = zeros(size(posXCleaned,1), size(posXCleaned,2));

% Rotation
for i = 1:size(posXCleaned,2)
    id = find(posXCleaned(:,i) ~= 0); 
    rotatedPoints = [posXCleaned(id,i) posYCleaned(id,i)]*R;
    scenario.posX(id,i) = rotatedPoints(:,1)+diffX;
    scenario.posY(id,i) = rotatedPoints(:,2)+diffY;
    scenario.v(id,i) = speedCleaned(id,i);
    scenario.psi(id,i) = veh_yawCleaned(id,i);
    scenario.aX(id,i) = accX_LTPCleaned(id,i);
    scenario.aY(id,i) = accY_LTPCleaned(id,i);
    scenario.vehLength(id,i) = veh_lengthCleaned(id,i);
    scenario.vehWidth(id,i) = veh_widthCleaned(id,i);
    figure(1);
    p1 = plot(scenario.posX(id,i), scenario.posY(id,i), 'm*');
    figure(2);
    subplot(4,1,1); plot(scenario.v(id,i), '--b', 'LineWidth', 2);
    subplot(4,1,2); plot(scenario.psi(id,i), '--g', 'LineWidth', 2);
    subplot(4,1,3); plot(scenario.aX(id,i), '--g', 'LineWidth', 2); 
    subplot(4,1,4); plot(scenario.aY(id,i), '--m', 'LineWidth', 2);
    delete(p1);
    clear rotatedPoints
end

