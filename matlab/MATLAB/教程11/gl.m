function f=gl(t,n)
   for i=1:n
       f(i)=1/(1+25*t(i)^2);
   end
   f