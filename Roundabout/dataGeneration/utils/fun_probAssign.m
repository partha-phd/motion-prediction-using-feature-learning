% Function to assign probabilities to the main and sub hypotheses
function fun_probAssign(vehicleDatabase, Targets, n, vehicle)
% START loop over the target
for i = 1:size(vehicleDatabase,1)
    
    probVal(1:3) = [Targets(i).FL*0.1...
        Targets(i).FL*0.8 Targets(i).FL*0.1];
    probVal(4:6) = [Targets(i).TR*0.1...
        Targets(i).TR*0.8 Targets(i).TR*0.1];
    probVal(7:9) = [Targets(i).TL*0.1...
        Targets(i).TL*0.8 Targets(i).TL*0.1];
    
    % START loop over the multiple hypotheses (lateral)
    for j = 1:size(vehicleDatabase,2)
        % START loop over the multiple hypotheses (longitudinal)
        for k = 1:size(vehicleDatabase,3)
            if ~isempty(vehicleDatabase(i,j,k).xCoordinates)
                multiplePaths(k) = vehicleDatabase(i,j,k).xCG(n);
            end
        end
        % END loop over the multiple hypotheses (longitudinal)
        if ~isempty(vehicleDatabase(i,j,k).xCoordinates)
            % Current state estimation
            distCurrent = vehicle(i).xPos(n);
            if distCurrent < min(multiplePaths)
                distCurrent = min(multiplePaths);
            elseif distCurrent > max(multiplePaths)
                distCurrent = max(multiplePaths);
            end
            % Triangular distribution
            pd = makedist('Triangular', 'a', min(multiplePaths),...
                'b', distCurrent, 'c', max(multiplePaths));
            minProb = pdf(pd, multiplePaths');
            minProb = (minProb/sum(minProb)).*probVal(j);
            % START loop over the multiple hypotheses (longitudinal)
            for k = 1:size(vehicleDatabase, 3)
                vehicleDatabase(i,j,k).minProb(n) = minProb(k);
            end
            % END loop over the multiple hypotheses (longitudinal)
        end
    end
    % END loop over the multiple hypotheses (lateral)
end
% END loop over the target
end