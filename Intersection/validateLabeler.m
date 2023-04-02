%%% VALIDATION OF THE MODEL BASED APPROACH METHOD %%%
clc; clearvars; close all;
% Add the necessary folders to path
addpath([pwd '\generatedData'])
% Load the required files
load('POG_Training_1');
load('refPOG_Training_1');

POG_Training = POG_Training_1;
POG_Reference = refPOG_Training_1;

counter = 0;
% START loop over the scenarios
for j = 1:(size(POG_Training)/50)
    % START loop over the time instances
    for i = 1:50
        counter = counter+1;
        POG_Training_Vec = POG_Training(counter,:,:);
        POG_Training_Vec = POG_Training_Vec(:);
        POG_Reference_Vec = POG_Reference(counter,:,:);
        POG_Reference_Vec = POG_Reference_Vec(:);
        id_low = find((POG_Training_Vec > 0)&(POG_Training_Vec<= 0.3));
        id_mid = find((POG_Training_Vec > 0.3)&(POG_Training_Vec<= 0.7));
        id_high = find((POG_Training_Vec > 0.7)&(POG_Training_Vec<= 1.0));
        if ~isempty(id_low)
            valRef_low = POG_Reference_Vec(id_low);
            ratio_low(j,i) = size(find(valRef_low~=0),1)/size(id_low,1);
        end
        if ~isempty(id_mid)
            valRef_mid = POG_Reference_Vec(id_mid);
            ratio_mid(j,i) = size(find(valRef_mid~=0),1)/size(id_mid,1);
        end
        if ~isempty(id_high)
            valRef_high = POG_Reference_Vec(id_high);
            ratio_high(j,i) = size(find(valRef_high~=0),1)/size(id_high,1);
        end
    end
    % END loop over the time instances
end
% END loop over the scenarios

% Discarding the scenarios with zero value
for i = 1:(size(POG_Reference)/50)
    if (ratio_low(i,:) == 0)
        ratio_low(i,:) = nan;
        ratio_mid(i,:) = nan;
        ratio_high(i,:) = nan;
    end
end
