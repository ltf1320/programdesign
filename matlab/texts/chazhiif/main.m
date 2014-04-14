clc
clear all
x=-5:0.01:5;
N=length(x);
for i=1:N
    y(i)=chazhiif(x(i));
end
plot(x,y)
y