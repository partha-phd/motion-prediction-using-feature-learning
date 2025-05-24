% Generation of Augmented Occupancy Grids
function augmentedOccupancyGrid = generateAOG(x_Road, y_Road,...
    Targets)

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
occupancyGrid = zeros(1, 126000);
% 1 - occupancy, 2 - v, 3 - Phi, 4 - longAccln, 5 - latAccln
occ=1:5:126000;
vel=2:5:126000;
psi=3:5:126000;
ax=4:5:126000;
ay=5:5:126000;

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
        occupancyGrid(occ(m))=1;
        occupancyGrid(vel(m))=0;
        occupancyGrid(psi(m))=0;
        occupancyGrid(ax(m))=0;
        occupancyGrid(ay(m))=0;
    end
end
% END loop over the grids

% Probability to target
% START loop over the target
for i = 1:size(Targets,2)
    % START loop over the grids
   for m = 1:25200
        xv = [gridNew(1,1,m) gridNew(1,2,m) gridNew(1,2,m)...
            gridNew(1,1,m) gridNew(1,1,m)];
        yv = [gridNew(2,1,m) gridNew(2,1,m) gridNew(2,2,m)...
            gridNew(2,2,m) gridNew(2,1,m)];
        xVehicle = [Targets(i).bboxX; Targets(i).bboxX(1)];
        yVehicle = [Targets(i).bboxY; Targets(i).bboxY(1)];
        
        if (any(inpolygon(xVehicle, yVehicle, xv, yv)) ||...
                any(inpolygon(xv, yv, xVehicle, yVehicle)))
            occupancyGrid(occ(m))=1;
            occupancyGrid(vel(m))=Targets(i).vel;
            occupancyGrid(psi(m))=Targets(i).psi;
            occupancyGrid(ax(m))=...
                Targets(i).ax;
            occupancyGrid(ay(m))=Targets(i).ay;
        end
    end
    % END loop over the grids
end
% END loop over the targets
augmentedOccupancyGrid(:,:,1) = rot90(reshape(occupancyGrid(1:5:126000),...
    [180 140]));
augmentedOccupancyGrid(:,:,2) = rot90(reshape(occupancyGrid(2:5:126000),...
    [180 140]));
augmentedOccupancyGrid(:,:,3) = rot90(reshape(occupancyGrid(3:5:126000),...
    [180 140]));
augmentedOccupancyGrid(:,:,4) = rot90(reshape(occupancyGrid(4:5:126000),...
    [180 140]));
augmentedOccupancyGrid(:,:,5) = rot90(reshape(occupancyGrid(5:5:126000),...
    [180 140]));
end
