function y=feibonaqi(n)

a=1;
b=1;
c=a;
sum=2;
for i=3:n
    c=b;
    b=b+a;
    a=c;
    sum=sum+a+b;
end
y=b;