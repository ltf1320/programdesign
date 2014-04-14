clear all
X=1:9;
Y=[9 7 6 3 -1 2 5 7 20];
P=polyfit(X,Y,3);
xi=0:.2:10;
yi=polyval(P,xi);
plot(xi,yi,X,Y,'r.');