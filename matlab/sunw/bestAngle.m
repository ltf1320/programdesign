clear all
clc
for i=1:100
    y(i)=doData((i-1)/100*pi*3/4,2,30);
end
x=[0.01*pi/2:0.01*pi/2:pi/2];
plot(x,y)
