function [ pri ] = func( x )
%return the privaty of f(x1,x2)=2*x1^2-2*x1*x2+2*x2^2-6*x1
%有两个约束
if 3*x(1)+4*x(2)-6>0
    pri=10;
else if -1*x(1)+4*x(2)-2>0
        pri=10;
    else
        pri=2*x(1)*x(1)-2*x(1)*x(2)+2*x(2)*x(2)-6*x(1);
    end
end
pri=10-pri;
end

