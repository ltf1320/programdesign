clear all
clc
t=0:0.1:2*pi;
x=linspace(1,50,10);
y=linspace(200,1000,5);
y1=sin(t);
y2=cos(t);
y3=t.*t;
y4=t.^0.5;
z=[1:10;2:2:20;3:12;10:10:100;linspace(5,10,10)]
surf(sphere)
colormap(autumn)
xlabel('x');
ylabel('y');
zlabel('z');

% plot(t,y1,'r<-'),hold on,
% plot(t,y2,'b>--'),hold off;
% xlabel('x');
% ylabel('y');
% title('f(x)=sin(x)');
% legend('sin(x)','cos(x)',-1)


% figure(1),
% subplot(2,2,1),plot(t,y1,'--k')
% subplot(2,2,2),plot(t,y2,'r:')
% subplot(4,1,3),plot(t,y3,'b--')
% subplot(4,1,4),plot(t,y4,'c-.')
% figure(2),
% plot(t,y2,'--k')
% 
% 
% x=logspace(-1,2)
% y=10*exp(x);
% loglog(x,y,'b-<')
% 
% x=0:.05:10;
% y=cos(10.^x);
% y=semilogx(x,y)

% 
% t=0:0.02:2*pi;
% polar(t,sin(3*t).*cos(2*t),'--r')


% x=-2.9:0.1:2.9;
% bar(x,exp(x.*sin(x)))
% colormap([1 0 0])
