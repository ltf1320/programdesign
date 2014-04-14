clear all
clc
for i=1:200
    y(i)=doData(1.06*2,2,200,(i-100)*pi/2/100);
    x(i)=pi/2/100*i-pi/2;
end
plot(x,y)