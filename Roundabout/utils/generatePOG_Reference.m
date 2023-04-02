%% Generation of Predicted Occupancy Grids (Reference)
function POG = generatePOG_Reference(x_Road, y_Road, vehicle, n)

% Construction of grids 0.5m x 0.5m
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

% Initialisation
occupancyGrid = zeros(1, 25200);

% Vectorize the road points
x_Road = x_Road(:);
y_Road = y_Road(:);

% Probability to road points
% START loop over the grids
for m=1:25200
    xv = [gridNew(1,1,m) gridNew(1,2,m) gridNew(1,2,m) gridNew(1,1,m)...
        gridNew(1,1,m)];
    yv = [gridNew(2,1,m) gridNew(2,1,m) gridNew(2,2,m) gridNew(2,2,m)...
        gridNew(2,1,m)];
    if any(inpolygon(x_Road,y_Road,xv,yv))
        occupancyGrid((m))=1;
    end
end
% END loop over the grids

% Probability to target
% START loop over the target
for i = 1:size(vehicle,2)
    % START loop over the grids
    for m = 1:25200
        xv = [gridNew(1,1,m) gridNew(1,2,m) gridNew(1,2,m)...
            gridNew(1,1,m) gridNew(1,1,m)];
        yv = [gridNew(2,1,m) gridNew(2,1,m) gridNew(2,2,m)...
            gridNew(2,2,m) gridNew(2,1,m)];
        xVehicle = [vehicle(i).bboxX(n,:) ...
            vehicle(i).bboxX(n,1)];
        yVehicle = [vehicle(i).bboxY(n,:) ...
            vehicle(i).bboxY(n,1)];
        if any(inpolygon(xVehicle,yVehicle,xv,yv)) || ...
                any(inpolygon(xv,yv, xVehicle, yVehicle))
            occupancyGrid(m)=1;
        end
    end
    % END loop over the grids
end
% END loop over the targets
POG = rot90(reshape(occupancyGrid, [180 140]));
end
