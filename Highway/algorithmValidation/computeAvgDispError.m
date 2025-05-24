% Calculation of the average displacement error between the reference POG
% and original driven trajectory
clc; clearvars; close all;
cd ..
currentFolder = pwd;

for idScenario = 33
    load([pwd '/POG_DataGeneration/generatedData_230129/' num2str(idScenario) '.mat']);
    % Rasterize the extracted POG
    for idTimesteps = 1:75
        POG_Prob = squeeze(POGForScenario(idTimesteps, :, :));
        POG_ID = squeeze(POGIDForScenario(idTimesteps, :, :));
        % Determine the pixels occupied by each target
        for idVehicle = 1:size(scenarioInfo.Target, 2)
            selectRow = [];
            selectCol = [];
            POG_Prob_Vec = [];
            for idRow = 1:size(POG_Prob, 1)
                for idCol = 1:size(POG_Prob, 2)
                    idOccVeh = num2cell(num2str(POG_ID(idRow, idCol)));
                    for idOcc = 1:size(idOccVeh,2)
                        if str2double(idOccVeh{1, idOcc}) == idVehicle
                            selectRow = [selectRow idRow];
                            selectCol = [selectCol idCol];
                        end
                    end
                end
            end
            for id = 1:size(selectCol, 2)
                POG_Prob_Vec(id) = POG_Prob(selectRow(id), selectCol(id));
            end

            if isempty(POG_Prob_Vec)
                continue;
            end
            maxProb= max(POG_Prob_Vec);
            idSelect = find(POG_Prob_Vec == maxProb);
            selectRowMax = max(selectRow(idSelect));
            selectRowMin = min(selectRow(idSelect));
            selectColMax = max(selectCol(idSelect));
            selectColMin = min(selectCol(idSelect));
            meanY(idVehicle, idTimesteps) = ...
                14.75 - (((selectRowMax + selectRowMin) / 2) * 0.5);
            meanX(idVehicle, idTimesteps) = ...
                (((selectColMax + selectColMin) / 2) * 0.5) - 0.25;
            error(idTimesteps, idVehicle) = ...
                sqrt((meanX(idVehicle, idTimesteps) - ...
                scenarioInfo.Target(idVehicle).xCG_New(idTimesteps+1))^2 + ...
                (meanY(idVehicle, idTimesteps) - ...
                scenarioInfo.Target(idVehicle).yCG_New(idTimesteps+1))^2);
        end
        avgDispError(idScenario, idTimesteps) = mean(error(idTimesteps, :));
    end
    clear POGIDForScenario POGForScenario 

    % Sample visualisation
    
    figure;
    for idVehicle = 1:size(scenarioInfo.Target, 2)
        plot(meanX(idVehicle, :), meanY(idVehicle, :),...
            'r', 'LineWidth', 2); hold on
        plot(scenarioInfo.Target(idVehicle).xCG_New(2:76),...
            scenarioInfo.Target(idVehicle).yCG_New(2:76),...
            'g', 'LineWidth', 2);
    
    end
    axis equal
end

% Compute the average displacement error over specific time horizon
% RMSE_OneSec = mean(mean(avgDispError([1:24 26:29 32:40 43:74], 1:25), 2));
% RMSE_TwoSec = mean(mean(avgDispError([1:24 26:29 32:40 43:74], 1:50), 2));
% RMSE_ThreeSec = mean(mean(avgDispError([1:24 26:29 32:40 43:74], 1:74), 2));



