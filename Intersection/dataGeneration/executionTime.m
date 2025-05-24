for i = 1:max(vehicleCount)
    id = vehicleCount==i;
    timeModel{i} = timeModelBased(id);
    timeML{i} = Prediction_Time(id);
    clear id;
end

fid = fopen('boxPlot_timeModel_Highway.txt', 'wt');
for i = 1:max(vehicleCount)
    a1 = i;
    a2 = nanmean(timeModel{i});
    a3 = max(timeModel{i});
    a4 = min(timeModel{i});
    a5 = quantile(timeModel{i}, 0.75);
    a6 = quantile(timeModel{i}, 0.25);
    fprintf(fid, '%f %f %f %f %f %f\n', a1, a2, a5, a6, a3, a4);
end
fclose(fid);
fid = fopen('boxPlot_timeML_Highway.txt', 'wt');
for i = 1:max(vehicleCount)
    a7 = i;
    a8 = nanmean(timeML{i});
    a9 = max(timeML{i});
    a10 = min(timeML{i});
    a11 = quantile(timeML{i}, 0.75);
    a12 = quantile(timeML{i}, 0.25);
    fprintf(fid, '%f %f %f %f %f %f\n', a7, a8, a11, a12, a9, a10);
end
fclose(fid);