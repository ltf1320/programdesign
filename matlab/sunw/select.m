clear all
clc
fdl=load('zongfadianliang.mat');
zjD=subass;
s=size(fdl.res);
for i=1:s(1)
    for j=1:s(2)
        res(i,j)=fdl.res(i,j)*(10+15*.09+10*0.8)/1000-zjD(i,4);
    end
end
res