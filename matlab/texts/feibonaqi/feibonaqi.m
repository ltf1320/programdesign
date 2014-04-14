function [y,sum]=feibonaqi(n)

a=1;
b=1;
c=1;
sum=2;
if n==1
    sum=1;
end
for i=3:n;
    c=b;
    b=a+b;
    a=c;
    sum=sum+b;
end
y=b;