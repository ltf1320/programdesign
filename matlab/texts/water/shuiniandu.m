function mu=shuiniandu(t)
mu0=1.785e-3;
a=0.03368;
b=0.000221;
mu=mu0./(1+a*t+b*t.*t);
