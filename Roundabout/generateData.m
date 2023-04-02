%%% GENERATE SCENARIOS FROM OUTDOOR DATASET %%%
%%% DATA FOR TRAINING OF MACHINE LEARNING ALGORITHMS FOR POG ESTIMATION %%%
%%% SCENARIO TYPE - ROUNDABOUT %%%

clearvars; clc; close all;
% Add the necessary folders to path
currentFolder = pwd;
addpath([currentFolder '\data'], [currentFolder '\utils']);

% Information about the road infrastructure
load('roadInfrastructure');
load('scenario_01');
figure(1);
plot(xRoad, yRoad, 'g*'); hold on; axis equal

% Random sampling of data based on time instance
noOfSamples = 2;
sampleID = randsample(100:size(scenario.posX,1)-200, noOfSamples);
% Scenario area under consideration
xScenario = [20 110 110 20 20];
yScenario = [-35 -35 35 35 -35];
for dataID = 1:noOfSamples
    id = find(scenario.posX(sampleID(dataID),:)~=0);
    noOfTarget = 1;
    % Number of targets in the scenario
    for i = 1:size(id,2)
        Targets(noOfTarget).xPos = scenario.posX(sampleID(dataID), id(i));
        Targets(noOfTarget).yPos = scenario.posY(sampleID(dataID), id(i));
        if ~inpolygon(Targets(noOfTarget).xPos,...
                Targets(noOfTarget).yPos, xScenario, yScenario)
            Targets(noOfTarget) = [];
            continue
        end
        Targets(noOfTarget).xPosFinal = ...
            scenario.posX(sampleID(dataID)+100, id(i));
        Targets(noOfTarget).yPosFinal = ...
            scenario.posY(sampleID(dataID)+100, id(i));
        if (Targets(noOfTarget).xPosFinal &&...
                Targets(noOfTarget).yPosFinal) == 0
            Targets(noOfTarget) = [];
            continue
        end
        Targets(noOfTarget).vel = scenario.v(sampleID(dataID), id(i));
        Targets(noOfTarget).psi = scenario.psi(sampleID(dataID), id(i));
        if Targets(noOfTarget).psi < 0
            Targets(noOfTarget).psi = 6.28+Targets(noOfTarget).psi;
        end
        Targets(noOfTarget).ax = scenario.aX(sampleID(dataID), id(i));
        Targets(noOfTarget).ay = scenario.aY(sampleID(dataID), id(i));
        Targets(noOfTarget).length = scenario.vehLength(...
            sampleID(dataID), id(i));
        Targets(noOfTarget).width = scenario.vehWidth(...
            sampleID(dataID), id(i));
        Targets(noOfTarget).type = 1;
        Targets(noOfTarget).bboxX = squeeze(scenario.bboxX...
            (sampleID(dataID),id(i),:));
        Targets(noOfTarget).bboxY= squeeze(scenario.bboxY...
            (sampleID(dataID),id(i),:));
        vehicle(noOfTarget).xPos = scenario.posX(sampleID(dataID):...
            sampleID(dataID)+100, id(i));
        vehicle(noOfTarget).yPos = scenario.posY(sampleID(dataID):...
            sampleID(dataID)+100, id(i));
        vehicle(noOfTarget).bboxX = squeeze(scenario.bboxX...
            (sampleID(dataID):sampleID(dataID)+100,id(i),:));
        vehicle(noOfTarget).bboxY = squeeze(scenario.bboxY...
            (sampleID(dataID):sampleID(dataID)+100,id(i),:));
        plot(Targets(noOfTarget).bboxX, Targets(noOfTarget).bboxY);
        noOfTarget = noOfTarget+1;    
    end
    
    % Assignment of probability to the main hypotheses
    [Targets, assignIssues] = fun_probEstimate(Targets, pol,...
        left, right, bottom, top);
    
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
            p1(j) = plot(Targets(j).xPos, Targets(j).yPos, 'r*');
            p2(j) = plot(Targets(j).xPosFinal, Targets(j).yPosFinal, 'b+');
            title(num2str(sampleID(dataID)));
            for k = 1:9
                [xDes_Lane, yDes_Lane] = fun_choosePath(k, Targets(j));
                if isempty(xDes_Lane)
                    continue
                end
                % START loop over the multiple hypotheses (longitudinal)
                for l = 1:size(maxMinSlip,2)
                    vehicleDatabase(j,k,l) = Vehicle;
                    vehicleDatabase(j,k,l).lf = Targets(j).length*1000/2;
                    vehicleDatabase(j,k,l).lr = Targets(j).length*1000/2;
                    vehicleDatabase(j,k,l).widthVehicle = ...
                        Targets(j).width*1000;
                    
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
                        p3(j,k,l)=plot(vehicleDatabase(j,k,l).xCG(end),...
                            vehicleDatabase(j,k,l).yCG(end), 'm*');
                    end
                end
                % END loop over the multiple hypotheses (longitudinal)
                clear xDes_Lane yDes_Lane
            end
            % END loop over the multiple hypotheses (main + lateral)
        end
        % END loop over the targets
        %% Assignment of probabilities to the motion hypotheses
        intervalPOG = 2:2:N;
        for n = 1:size(intervalPOG,2)
            fun_probAssign(vehicleDatabase, Targets, intervalPOG(n),...
                vehicle);
        end
        % Parameters for evaluation
        timeModelBased(dataID) = toc;
        vehicleCount(dataID) = size(Targets,2);
        
        %% Generation of AOGs and POGs
        % AOG generation
        AOG(dataID,:,:,:) = generateAOG(xRoad, yRoad, Targets);
        % POG generation
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
        parfor n =1:size(intervalPOG,2)
            generatedPOG(n,:,:) = generatePOG_mex(xRoad, yRoad,...
                vehicleDatabase1, intervalPOG(n));
        end
        POG(dataID,:,:,:) = generatedPOG;
        
        % Actual realizations
        parfor n = 1:size(intervalPOG,2)
            referencePOG(n,:,:) = generatePOG_Reference_mex(xRoad,...
                yRoad, vehicle, intervalPOG(n));
        end
        POG_reference(dataID,:,:,:) = referencePOG;
        clear Targets vehicleDatabase vehicle vehicleDatabase1
    else
        disp('Issues with probability assignment');
    end
    dataID
    delete(p1)
    delete(p2)
    delete(p3)
end

%% Pre processing of extracted data
% Scale AOG to make all the data lie in the interval [0,1]
AOG_Scaled = single(scaleAOG(AOG));
POG = single(POG);
POG_reference = single(POG_reference);
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
mkdir generatedData
saveDir = [pwd '\generatedData\'];
save([saveDir 'AOG_Training'], 'AOG_Training');
save([saveDir 'POG_Training'], 'POG_Training');
save([saveDir 'AOG_Validation'], 'AOG_Validation');
save([saveDir 'POG_Validation'], 'POG_Validation');
save([saveDir 'refPOG_Training'], 'refPOG_Training');
save([saveDir 'refPOG_Validation'], 'refPOG_Validation');
save([saveDir 'EvalMetric'], 'timeModelBased', 'vehicleCount');