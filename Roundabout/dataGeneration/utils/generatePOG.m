% Generation of Predicted Occupancy Grids
function predictedOccupancyGrid = generatePOG(x_Road, y_Road,...
    vehicleDatabase, n)

% Construction of grids 1m x 0.5m
X=20:0.5:110;
Y=-35.1:0.5:35;
k=1;
gridNew=zeros(2,2,25200);
for i=1:size(Y,2)-1
    for j=1:size(X,2)-1
        grid=[X(j) X(j+1); Y(i) Y(i+1)];
        gridNew(:,:,k)=grid;
        k=k+1;
    end
end

% Vectorize the road points
x_Road = x_Road(:);
y_Road = y_Road(:);

% Initialisation
occupancyGrid = zeros(10000,25200);

% Probability to road points
% START loop over the grids
for m=1:25200
    xv = [gridNew(1,1,m) gridNew(1,2,m) gridNew(1,2,m) gridNew(1,1,m)...
        gridNew(1,1,m)];
    yv = [gridNew(2,1,m) gridNew(2,1,m) gridNew(2,2,m) gridNew(2,2,m)...
        gridNew(2,1,m)];
    if any(inpolygon(x_Road,y_Road,xv,yv))
        occupancyGrid(:,m)=1;
    end
end
% END loop over the grids

counter = 0;

% Probability to target
% START loop over the target
for i = 1:size(vehicleDatabase,1)
    % START loop over the multiple hypotheses (lateral)
    for j = 1:size(vehicleDatabase,2)
        % START loop over the multiple hypotheses(longitudinal)
        for k = 1:size(vehicleDatabase,3)
            if ~isempty(vehicleDatabase(i,j,k).xCoordinates)
                counter = counter+1;
                % START loop over the grids
                for m = 1:25200
                    xv = [gridNew(1,1,m) gridNew(1,2,m) gridNew(1,2,m)...
                        gridNew(1,1,m) gridNew(1,1,m)];
                    yv = [gridNew(2,1,m) gridNew(2,1,m) gridNew(2,2,m)...
                        gridNew(2,2,m) gridNew(2,1,m)];
                    xVehicle = [vehicleDatabase(i,j,k).xCoordinates(n,1)...
                        vehicleDatabase(i,j,k).xCoordinates(n,2)...
                        vehicleDatabase(i,j,k).xCoordinates(n,3)...
                        vehicleDatabase(i,j,k).xCoordinates(n,4)...
                        vehicleDatabase(i,j,k).xCoordinates(n,1)];
                    yVehicle = [vehicleDatabase(i,j,k).yCoordinates(n,1)...
                        vehicleDatabase(i,j,k).yCoordinates(n,2)...
                        vehicleDatabase(i,j,k).yCoordinates(n,3)...
                        vehicleDatabase(i,j,k).yCoordinates(n,4)...
                        vehicleDatabase(i,j,k).yCoordinates(n,1)];
                    if any(inpolygon(xVehicle,yVehicle,xv,yv)) ||...
                            any(inpolygon(xv,yv, xVehicle, yVehicle))
                        occupancyGrid(counter,m)=...
                            vehicleDatabase(i,j,k).minProb(n);
                    else
                        occupancyGrid(counter,m) = 0;
                    end
                end
                % END loop over the grids
            end
            % END loop over the multiple hypotheses (longitudinal)
        end
    end
    % END loop over the multiple hypotheses (lateral)
end
% END loop over the targets

% Calculating the predicted occupancy grid
occupancyGrid = sum(occupancyGrid, 1);
occupancyGrid(occupancyGrid>1) = 1;
predictedOccupancyGrid = rot90(reshape(occupancyGrid, [180 140]));
end
