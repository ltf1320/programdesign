clc
clear all
x=0:pi/100:2*pi;
y=x;
[X,Y]=meshgrid(x,y);
z=3*sin(X)+cos(Y);
h=surf(z);
axis tight
set(gca,'nextplot','replacechildren');
shading interp;
colormap(jet);
m=1
for k=0:pi/100:2*pi
    z=(sin(X)+cos(Y)).*sin(k);
    set(h,'Zdata',z);
    M(m)=getframe;
    m=m+1;
end
movie(M,2)