clear all
clc
A=[10,-1,0;-1,10,-2;0,-2,10];
B=[9;7;6];
x0=[0;0;0];
x=yacobi(A,B,x0);
fprintf('x1=%.6f   x2=%.6f   x3=%.6f',x(1),x(2),x(3))