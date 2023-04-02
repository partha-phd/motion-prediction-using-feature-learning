% Function - Add node to the tree------------------------------------------
function rrt = AddNode(rrt, p, p_pos, iPrev, p_angle, sampleTime, termNode)
node.p = p;
node.p_pos = p_pos;
node.iPrev = iPrev;
node.angPrev = p_angle;
node.sampleTime = sampleTime;
node.terminalNode = termNode;
if length(rrt) >= 1
    rrt{1,iPrev}.terminalNode = 0;
end
rrt{end+1} = node;
end
