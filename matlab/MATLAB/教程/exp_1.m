clear 
clc
close all
t=-10:0.1:10;
n=length(t);
y=gl(t,n);
t0=-12:0.5:12;
lglr=lglrcz(t,y,t0);
laglr=lglrcz(t,y,8)
fdxx=interp1(t,y,t0);
fendxx=interp1(t,y,8)
plot(t,y,'*',t0,lglr,'r',t0,fdxx,'g')