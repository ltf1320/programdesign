function y=yacobi(a,b,x0)
%%%this function is to compute the root of AX=b
%%%a refers to coefficient matrix 
%%%X refers to column vector,while b is augmented matrix

D=diag(diag(a));   % D is the leading diagonal matix
U=-triu(a,1);
L=-tril(a,-1);
B=D\(L+U);
f=D\b;
y=B*x0+f;
while norm(y-x0)>1.0e-6
    x0=y;
    y=B*x0+f;
end