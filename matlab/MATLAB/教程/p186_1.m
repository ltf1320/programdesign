clear
clc
close all
c=200;
a=8;
b1=15;
lgxb=[];lgyb=[];tzxb=[];tzyb=[];%ÉèÁÔ¹·ºá×Ý×ø±êÓëÍÃ×Óºá×Ý×ø±ê
d=0.5;
dt=0.1;
t=0;
lgx=c;lgy=0;tzx=0;tzy=0;
while (sqrt((lgx-tzx)^2+(lgy-tzy)^2)>d)
    t=t+dt;
    lgx=lgx-b1*dt*lgx/sqrt(lgx^2+(a*t-lgy)^2);
    lgxb=[lgxb,lgx];
    lgy=lgy+b1*dt*(a*t-lgy)/sqrt(lgx^2+(a*t-lgy)^2);
    lgyb=[lgyb,lgy];
    tzy=a*t;
    tzyb=[tzyb,tzy];
end
lgxb
lgyb
tzyb
tzxb=zeros(length(tzyb));
plot(lgxb,lgyb,tzxb,tzyb,'*')
hold on
plot(0,120,'r*','markersize',20)