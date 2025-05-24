%%% GENERATE SCENARIOS FROM OUTDOOR DATASET %%%
%%% DATA FOR TRAINING OF MACHINE LEARNING ALGORITHMS FOR POG ESTIMATION %%%
%%% SCENARIO TYPE - 3 WAY INTERSECTION %%%

clearvars; clc; close all;
% Add the necessary folders to path
currentFolder = pwd;
addpath([currentFolder '\data'], [currentFolder '\utils']);

% Information about the road infrastructure
load('roadInfrastructure');
load('sampleID');

%% Sampling of configurations
% Getting initial state information for random sampling
posXVec1 = [];
posYVec1 = [];
bboxXVec1 = [];
bboxYVec1 = [];
velVec1 = [];
aXVec1 = [];
aYVec1 = [];
psiVec1 = [];
posXVec2 = [];
posYVec2 = [];
bboxXVec2 = [];
bboxYVec2 = [];
velVec2 = [];
aXVec2 = [];
aYVec2 = [];
psiVec2 = [];
posXVec3 = [];
posYVec3 = [];
bboxXVec3 = [];
bboxYVec3 = [];
velVec3 = [];
aXVec3 = [];
aYVec3 = [];
psiVec3 = [];
sampleID = 100; %<-- no of time instances to sample from

for i = 1:36 %<-- no of scenarios available
    if i < 10
        load([pwd '\data\scenario0' num2str(i)]);
    else
        load([pwd '\data\scenario' num2str(i)]);
    end
    for j = 1:size(vehicle,2)
        if j == 1
            posXVec1 = [posXVec1 vehicle(j).posX(1:sampleID)];
            posYVec1 = [posYVec1 vehicle(j).posY(1:sampleID)];
            velVec1 = [velVec1 vehicle(j).v(1:sampleID)];
            aXVec1 = [aXVec1 vehicle(j).aX(1:sampleID)];
            aYVec1 = [aYVec1 vehicle(j).aY(1:sampleID)];
            psiVec1 = [psiVec1 vehicle(j).psi(1:sampleID)];
            bboxXVec1 = [bboxXVec1 vehicle(j).bboxX(:,1:sampleID)];
            bboxYVec1 = [bboxYVec1 vehicle(j).bboxY(:,1:sampleID)];
        elseif j == 2
            posXVec2 = [posXVec2 vehicle(j).posX(1:sampleID)];
            posYVec2 = [posYVec2 vehicle(j).posY(1:sampleID)];
            velVec2 = [velVec2 vehicle(j).v(1:sampleID)];
            aXVec2 = [aXVec2 vehicle(j).aX(1:sampleID)];
            aYVec2 = [aYVec2 vehicle(j).aY(1:sampleID)];
            psiVec2 = [psiVec2 vehicle(j).psi(1:sampleID)];
            bboxXVec2 = [bboxXVec2 vehicle(j).bboxX(:,1:sampleID)];
            bboxYVec2 = [bboxYVec2 vehicle(j).bboxY(:,1:sampleID)];
            if size(vehicle,2)~=3
                posXVec3 = [posXVec3 NaN(1,sampleID)];
                posYVec3 = [posYVec3 NaN(1,sampleID)];
                velVec3 = [velVec3 NaN(1,sampleID)];
                aXVec3 = [aXVec3 NaN(1,sampleID)];
                aYVec3 = [aYVec3 NaN(1,sampleID)];
                psiVec3 = [psiVec3 NaN(1,sampleID)];
                bboxXVec3 = [bboxXVec3 NaN(4,sampleID)];
                bboxYVec3 = [bboxYVec3 NaN(4,sampleID)];
            end
        else
            posXVec3 = [posXVec3 vehicle(j).posX(1:sampleID)];
            posYVec3 = [posYVec3 vehicle(j).posY(1:sampleID)];
            velVec3 = [velVec3 vehicle(j).v(1:sampleID)];
            aXVec3 = [aXVec3 vehicle(j).aX(1:sampleID)];
            aYVec3 = [aYVec3 vehicle(j).aY(1:sampleID)];
            psiVec3 = [psiVec3 vehicle(j).psi(1:sampleID)];
            bboxXVec3 = [bboxXVec3 vehicle(j).bboxX(:,1:sampleID)];
            bboxYVec3 = [bboxYVec3 vehicle(j).bboxY(:,1:sampleID)];
        end
    end
end
noOfSamples = 3000;
% Randomly sampling a configuration
% id = randsample(size(posXVec1,2), noOfSamples);
for dataID = 314:noOfSamples
    plot(xRoad, yRoad, 'k+'); hold on;
    axis equal
    plot(pol.x1, pol.y1);
    plot(pol.x2, pol.y2);
    plot(pol.x3, pol.y3);
    plot(pol.x4, pol.y4);
    plot(pol.x5, pol.y5);
    plot(pol.x6, pol.y6);
    plot(pol.x7, pol.y7);
    plot(pol.x8, pol.y8);
    plot(pol.x9, pol.y9);
    
    % Collecting data from the original dataset for reference data
    initialID = mod(id(dataID),100);
    if initialID == 0
        scenarioID = (floor(id(dataID)./100));
        initialID = 100;
    else
        scenarioID = (floor(id(dataID)./100))+1;
    end
    finalID = initialID+101;
    if scenarioID < 10
        load([pwd '\data\scenario0' num2str(scenarioID)]);
    else
        load([pwd '\data\scenario' num2str(scenarioID)]);
    end
    if finalID > size(vehicle(1).time,2)
        finalID = size(vehicle(1).time,2);
    end
    if isnan(posXVec3(id(dataID)))
        noOfTarget = 2;
    else
        noOfTarget = 3;
    end
    %% Simulation of the vehicle multiple motion hypotheses
    % Traffic participants state
    % Target 1
    Target1.xPos = posXVec1(id(dataID));
    Target1.yPos = posYVec1(id(dataID));
    Target1.vel = velVec1(id(dataID));
    Target1.psi = psiVec1(id(dataID));
    Target1.ax = aXVec1(id(dataID));
    Target1.ay = aYVec1(id(dataID));
    Target1.bboxX = bboxXVec1(:,id(dataID));
    Target1.bboxY = bboxYVec1(:,id(dataID));
    Target1.type = 1; % Car
    Target1.length = 5;
    Target1.width = 2;
    
    % Target 2
    Target2.xPos = posXVec2(id(dataID));
    Target2.yPos = posYVec2(id(dataID));
    Target2.vel = velVec2(id(dataID));
    Target2.psi = psiVec2(id(dataID));
    Target2.ax = aXVec2(id(dataID));
    Target2.ay = aYVec2(id(dataID));
    Target2.bboxX = bboxXVec2(:,id(dataID));
    Target2.bboxY = bboxYVec2(:,id(dataID));
    Target2.type = 1; % Car
    Target2.length = 5;
    Target2.width = 2;
    
    % Target 3
    Target3.xPos = posXVec3(id(dataID));
    Target3.yPos = posYVec3(id(dataID));
    Target3.vel = velVec3(id(dataID));
    Target3.psi = psiVec3(id(dataID));
    Target3.ax = aXVec3(id(dataID));
    Target3.ay = aYVec3(id(dataID));
    Target3.bboxX = bboxXVec3(:,id(dataID));
    Target3.bboxY = bboxYVec3(:,id(dataID));
    Target3.type = 1; % Car
    Target3.length = 5;
    Target3.width = 2;
    
    % Targets
    if noOfTarget == 3
        Targets = [Target1, Target2, Target3];
    elseif noOfTarget == 2
        Targets = [Target1, Target2];
    end
    for i = 1:noOfTarget
        plot(Targets(i).bboxX, Targets(i).bboxY, 'r*');
    end
    % Assignment of probability to the main hypotheses
    [Targets, assignIssues] = fun_probEstimate(Targets, pol,...
        leftVehicle, rightVehicle, bottomVehicle);
    if ~assignIssues
        tic
        % Two track model simulation
        T = 0.02;
        totalTime = 2;
        N = ceil(totalTime/T)+1;
        
        % Simulation parameters
        maxMinSlip = -0.08:0.005:0.04;
        
        % START loop over the targets
        for j = 1:size(Targets,2)
            % START loop over the multiple hypotheses (main + lateral)
            for k = 1:9
                [xDes_Lane, yDes_Lane] = fun_choosePath(k, Targets(j));
                if isempty(xDes_Lane)
                    continue
                end
                % START loop over the multiple hypotheses (longitudinal)
                for l = 1:size(maxMinSlip,2)
                    vehicleDatabase(j,k,l) = Vehicle;
                    % START loop over the time steps
                    for n = 2:N
                        vehicleDatabase(j,k,l).drive(Targets(j).xPos,...
                            Targets(j).yPos, Targets(j).psi,...
                            Targets(j).vel, Targets(j).ax,...
                            Targets(j).ay, xDes_Lane, yDes_Lane,...
                            maxMinSlip(l), T, n, Targets(j).type,...
                            Targets(j).length, Targets(j).width);
                    end
                    % END loop over the time steps
                    if (vehicleDatabase(j,k,l).stability == false)
                        vehicleDatabase(j,k,l).xCG = [];
                        vehicleDatabase(j,k,l).yCG = [];
                        disp('Issues with stability')
                    else
                        plot(vehicleDatabase(j,k,l).xCG(end),...
                            vehicleDatabase(j,k,l).yCG(end), 'g*');
%                         if l == 17
%                             plot(vehicleDatabase(j,k,17).xCG(end),...
%                                 vehicleDatabase(j,k,17).yCG(end), 'b+');
%                         end
                    end
                end
                % END loop over the multiple hypotheses (longitudinal)
                clear xDes_Lane yDes_Lane
            end
            % END loop over the multiple hypotheses (main + lateral)
            plot(vehicle(j).posX(finalID), vehicle(j).posY(finalID), 'mo');
        end
        % END loop over the targets
        
        %% Assignment of probabilities to the motion hypotheses
        intervalPOG = 2:2:N;
        if (N+initialID <= finalID) %<- to make sure the scenarios are 2s
            for n = 1:size(intervalPOG,2)
                fun_probAssign(vehicleDatabase, Targets, intervalPOG(n),...
                    vehicle, initialID);
            end
            % Parameters for evaluation
            timeModelBased(dataID) = toc;
            vehicleCount(dataID) = noOfTarget;
            %% Generation of AOGs and POGs
            % AOG generation
            AOG(dataID,:,:,:) = generateAOG(xRoad, yRoad, Targets);
            for l1 = 1:size(vehicleDatabase,1)
                for l2 = 1:size(vehicleDatabase,2)
                    for l3 = 1:size(vehicleDatabase,3)
                        vehicleDatabase1(l1,l2,l3).xCoordinates =...
                            vehicleDatabase(l1,l2,l3).xCoordinates;
                        vehicleDatabase1(l1,l2,l3).yCoordinates =...
                            vehicleDatabase(l1,l2,l3).yCoordinates;
                        if ~isempty(vehicleDatabase(l1,l2,l3).minProb)
                            vehicleDatabase1(l1,l2,l3).minProb =...
                                vehicleDatabase(l1,l2,l3).minProb;
                        else
                            vehicleDatabase1(l1,l2,l3).minProb = 0;
                        end
                    end
                end
            end
            % POG generation
            parfor n =1:size(intervalPOG,2)
                generatedPOG(n,:,:) = generatePOG_mex(xRoad, yRoad,...
                    vehicleDatabase1, intervalPOG(n));
            end
%             figure(2);
%             for i = 1:size(generatedPOG,1)
%                 imagesc(squeeze(generatedPOG(i,:,:))); pause(0.1);
%             end
            POG(dataID,:,:,:) = generatedPOG;
            % Actual realizations
            parfor n = 1:size(intervalPOG,2)
                referencePOG(n,:,:) = generatePOG_Reference_mex(xRoad,...
                    yRoad, vehicle, intervalPOG(n), initialID);
            end
            POG_reference(dataID,:,:,:) = referencePOG;
%             figure(3);
%             for i = 1:size(referencePOG,1)
%                 imagesc(squeeze(referencePOG(i,:,:))); pause(0.1);
%             end
        else
            disp('Scenario not of required length');
        end
        clear vehicleDatabase1 vehicleDatabase Targets vehicle
    else
        disp('Issues with probability assignment');
    end
    close all;
    dataID
end

%% Pre processing of extracted data
% Scale AOG to make all the data lie in the interval [0,1]
AOG_Scaled = single(scaleAOG(AOG));
POG = single(POG);
id_training = randsample(noOfSamples, floor(0.7*noOfSamples));
id_validation = setdiff(1:noOfSamples, id_training);
AOG_Training = AOG_Scaled(id_training,:,:,:);
AOG_Validation = AOG_Scaled(id_validation,:,:,:);
POG_Train = POG(id_training,:,:,:);
POG_Validate = POG(id_validation,:,:,:);
refPOG_Train = POG_reference(id_training,:,:,:);
refPOG_Validate = POG_reference(id_validation,:,:,:);
% Reshaping to feed in as input to the network
POG_Training = [];
POG_Validation = [];
refPOG_Training = [];
refPOG_Validation = [];
for i = 1:size(POG_Train,1)
    POG_Training = [POG_Training; squeeze(POG_Train(i,:,:,:))];
end
for i = 1:size(POG_Validate,1)
    POG_Validation = [POG_Validation; squeeze(POG_Validate(i,:,:,:))];
end
for i = 1:size(refPOG_Train,1)
    refPOG_Training = [refPOG_Training; squeeze(refPOG_Train(i,:,:,:))];
end
for i = 1:size(refPOG_Validate,1)
    refPOG_Validation = [refPOG_Validation; ...
        squeeze(refPOG_Validate(i,:,:,:))];
end

%% Saving the generated data
mkdir generatedData_20191106
saveDir = [pwd '\generatedData_20191106\'];
save([saveDir 'AOG_Training'], 'AOG_Training');
save([saveDir 'POG_Training'], 'POG_Training');
save([saveDir 'AOG_Validation'], 'AOG_Validation');
save([saveDir 'POG_Validation'], 'POG_Validation');
save([saveDir 'EvalMetric'], 'timeModelBased', 'vehicleCount');