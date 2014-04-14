function f=logistic(p,xdata)
    for i=1:20
       f(i)=1/(4.5^(-1)+exp(p(1)-p(2)*xdata(i)));
    end
    