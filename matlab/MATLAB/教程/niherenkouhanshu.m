clear
clc
close all
xdata=1790:10:1980;
ydata=[3.9,5.3,7.2,9.6,12.9,17.1,23.2,31.4,38.6,50.2,62,72,92,106.5,123.2,131.7,150.7,179.3,204,226.5]*10^(-2);
z=length(xdata);
figure(1)
plot(xdata,ydata,'o')
p0=[0,0];
p=lsqcurvefit('logistic',p0,xdata,ydata)
xdata1=1790:10:2050;
ph=[];
for j=1:length(xdata1)
    ph(j)=1/(4.5^(-1)+exp(p(1)-p(2)*xdata1(j)));
end
figure(2)
plot(xdata1,ph)
set(gca,'xtick',1790:10:2050,'ytick',0:1:5)
figure(3)
plot(xdata,ydata,'.',xdata1,ph)