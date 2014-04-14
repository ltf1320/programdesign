c=[2;3;-5];
A=[2,-5,1];
b=[10];
Aeq=[1 1 1];
beq=[7];
[x,f]=linprog(c,A,b,Aeq,beq,zeros(3,1),[5;5;5])