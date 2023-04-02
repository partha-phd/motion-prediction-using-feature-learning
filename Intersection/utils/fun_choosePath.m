function [xDes_Lane, yDes_Lane] = fun_choosePath(k, Target)
switch k
    case 1
        if isempty(Target.xDesired.Straight)
            xDes_Lane = [];
            yDes_Lane = [];
        else
            xDes_Lane = Target.xDesired.Straight(1,:);
            yDes_Lane = Target.yDesired.Straight(1,:);
        end
    case 2
        if isempty(Target.xDesired.Straight)
            xDes_Lane = [];
            yDes_Lane = [];
        else
            xDes_Lane = Target.xDesired.Straight(2,:);
            yDes_Lane = Target.yDesired.Straight(2,:);
        end
    case 3
        if isempty(Target.xDesired.Straight)
            xDes_Lane = [];
            yDes_Lane = [];
        else
            xDes_Lane = Target.xDesired.Straight(3,:);
            yDes_Lane = Target.yDesired.Straight(3,:);
        end
    case 7
        if isempty(Target.xDesired.Left)
            xDes_Lane = [];
            yDes_Lane = [];
        else
            xDes_Lane = Target.xDesired.Left(1,:);
            yDes_Lane = Target.yDesired.Left(1,:);
        end
    case 8
        if isempty(Target.xDesired.Left)
            xDes_Lane = [];
            yDes_Lane = [];
        else
            xDes_Lane = Target.xDesired.Left(2,:);
            yDes_Lane = Target.yDesired.Left(2,:);
        end
    case 9
        if isempty(Target.xDesired.Left)
            xDes_Lane = [];
            yDes_Lane = [];
        else
            xDes_Lane = Target.xDesired.Left(3,:);
            yDes_Lane = Target.yDesired.Left(3,:);
        end
    case 4
        if isempty(Target.xDesired.Right)
            xDes_Lane = [];
            yDes_Lane = [];
        else
            xDes_Lane = Target.xDesired.Right(1,:);
            yDes_Lane = Target.yDesired.Right(1,:);
        end
    case 5
        if isempty(Target.xDesired.Right)
            xDes_Lane = [];
            yDes_Lane = [];
        else
            xDes_Lane = Target.xDesired.Right(2,:);
            yDes_Lane = Target.yDesired.Right(2,:);
        end
    case 6
        if isempty(Target.xDesired.Right)
            xDes_Lane = [];
            yDes_Lane = [];
        else
            xDes_Lane = Target.xDesired.Right(3,:);
            yDes_Lane = Target.yDesired.Right(3,:);
        end
end
end