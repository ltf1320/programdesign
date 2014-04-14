clear all
clc
syms x1 x2 x3;
K1=10*x1-x2-9;
K2=(-1)*x1+10*x2-2*x3-7;
K3=(-2)*x2+10*x3-6;
X2to1=solve(K1,x2);
M1=subs(K3,'x2',X2to1);
X3to1=solve(M1,x3);
M2=subs(K2,'x2',X2to1);
M3=subs(M2,'x3',X3to1);
X1=solve(M3)
X2=subs(X2to1,'x1',X1)
X3=subs(X3to1,'x1',X1)




