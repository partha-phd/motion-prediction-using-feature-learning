clc; clearvars; close all;
cd ..
currentFolder = pwd;
cumProb = [];
TTC = [];
THW = [];
RP = [];
for id = 1:4
    
    idScenario = idSelect(id);
    load([pwd '/POG_DataGeneration/generatedData_230131/' num2str(idScenario) '.mat']);
    % Rasterize the extracted POG
    for idTimesteps = 1:75
        POG_Prob = squeeze(POGForScenario(idTimesteps, :, :));
        xPos_Ego = scenarioInfo.EGO.xCG_New(idTimesteps);
        yPos_Ego = scenarioInfo.EGO.yCG_New(idTimesteps);
        % Conversion to grid
        xPos_Grid = [round(xPos_Ego*2)-3 round(xPos_Ego*2)+3];
        yPos_Grid = [round(yPos_Ego*2)-2 round(yPos_Ego*2)+2];
        % Probability sum
        probValues = POG_Prob(yPos_Grid, xPos_Grid);
        sumProb(idTimesteps) = sum(probValues(:));
    end
    riskPerceptionForScenario = (1 ./ timeHeadWayForScenario) + (4 ./ timeToCollisionForScenario);
    cumProb = [cumProb sumProb];
    TTC = [TTC timeToCollisionForScenario];
    THW = [THW timeHeadWayForScenario];
    RP = [RP riskPerceptionForScenario];

figure(2);
subplot(4,1,1)
plot((1:idTimesteps).*0.04, sumProb, 'LineWidth', 2);
subplot(4,1,2)
plot((1:idTimesteps).*0.04, timeToCollisionForScenario, 'LineWidth', 2);
subplot(4,1,3)
plot((1:idTimesteps).*0.04, timeHeadWayForScenario, 'LineWidth', 2);
riskPerceptionForScenario = (1 ./ timeHeadWayForScenario) + (4 ./ timeToCollisionForScenario);
subplot(4,1,4)
plot((1:idTimesteps).*0.04, riskPerceptionForScenario, 'LineWidth', 2);
close all;
end




