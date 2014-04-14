clf;
x=3*pi*(-1:0.05:1);
y=x;
[X,Y]=meshgrid(x,y);
R=sqrt(X.^2+Y.^2)+eps;
Z=sin(R)./R;
h=surf(X,Y,Z);
colormap(jet);
%axis off;
for i=1:0.0001:1.25
       rotate(h,[0 0 1],i);drawnow;
end