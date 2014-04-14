function [ code ] = zip( x )
%ZIP Summary of this function goes here
%   Detailed explanation goes here
code=zeros(46,1);
x=x*10^6;
for i=1:23
    code(i)=mod(x(1),2);
    x(1)=floor(x(1)/2);
end
for i=1:23
    code(i+23)=mod(x(2),2);
    x(2)=floor(x(2)/2);
end

end

