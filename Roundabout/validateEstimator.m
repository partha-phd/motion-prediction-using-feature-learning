%%% VALIDATION OF THE MACHINE LEARNING APPROACH %%%
clc; clearvars; close all;
% Add the necessary folders to path
addpath([pwd '\generatedData']);
% Load the required files
load('featuresPOG_Validation');
id = size(POG_);
noOfScenarios = id(1);
timeInstances = id(2);
gridX = id(3);
gridY = id(4);
% Preprocessing the data


%% Reshaping the ground truth POG
% START loop over the number of scenarios
counter = 0;
truePOG_Validation = single(zeros(noOfScenarios, timeInstances,...
    gridX, gridY));
for i = 1:timeInstances:size(POG_Validation,1)
    counter = counter+1;
    truePOG_Validation(counter,:,:,:) = POG_Validation(i:i+49,:,:);
end
% END loop over the number of scenarios

%% Computation of error metric
error_low = zeros(793,timeInstances);
error_mid = zeros(793,timeInstances);
error_high = zeros(793,timeInstances);
mean_low = zeros(793,timeInstances);
mean_mid = zeros(793,timeInstances);
mean_high = zeros(793,timeInstances);
counter = 1;
% START loop over the number of scenarios
for i = 1:noOfScenarios
    POG_scenario = squeeze(truePOG_Validation(i,:,:,:));
    if ~all(POG_scenario(:)==0)
        % START loop over the time instances
        for j = 1:timeInstances
            low_id = find(truePOG_Validation(i,j,:,:) <= 0.3 & ...
                truePOG_Validation(i,j,:,:)~=0);
            mid_id = find(truePOG_Validation(i,j,:,:) > 0.3 & ...
                truePOG_Validation(i,j,:,:) <= 0.7);
            high_id = find(truePOG_Validation(i,j,:,:) > 0.7 & ...
                truePOG_Validation(i,j,:,:) <= 1);
            truePOG = truePOG_Validation(i,j,:,:);
            reconPOG = reconPOG_Validation(i,j,:,:);
            
            if ~isempty(low_id)
                error_low(counter,j) = sqrt(immse(truePOG(low_id),...
                    reconPOG(low_id)));
                mean_low(counter,j) = mean(truePOG(low_id));
            end
            if ~isempty(mid_id)
                error_mid(counter,j) = sqrt(immse(truePOG(mid_id),...
                    reconPOG(mid_id)));
                mean_mid(counter,j) = mean(truePOG(mid_id));
            end
            if ~isempty(high_id)
                error_high(counter,j) = sqrt(immse(truePOG(high_id),...
                    reconPOG(high_id)));
                mean_high(counter,j) = mean(truePOG(high_id));
            end
            clear truePOG reconPOG low_id mid_id high_id
        end
        counter = counter+1;
    end
    clear POG_scenario
    % END loop over the time instances
end
% END loop over the number of scenarios

% Computing mean error over the time instances
% START loop over the time instances
for i = 1:timeInstances
    mean_error_low(i) = mean(error_low(:,i));
    mean_error_mid(i) = mean(error_mid(:,i));
    mean_error_high(i) = mean(error_high(:,i));
    mean_val_low(i) = mean(mean_low(:,i));
    mean_val_mid(i) = mean(mean_mid(:,i));
    mean_val_high(i) = mean(mean_high(:,i));
end
% END loop over the time instances