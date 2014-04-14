clc
clear all
close all
t=linspace(0,10*pi,4000);
plot3(sin(t),cos(t),t);
ball=line(0,1,'color','r','marker','.','markersize',60,'erasemode','xor');
for i=1:3
    for n=1:600
        set(ball,'xdata',sin(t(n)),'ydata',cos(t(n)),'zdata',t(n));
    end
    drawnow;
end