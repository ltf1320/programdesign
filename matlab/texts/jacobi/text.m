clear all
clc
a=[10 -1 0; -1 10 -1;0 -2 10];
b=[9;7;6];
x0=[0;0;0];
x=jacobi(a,b,x0);
