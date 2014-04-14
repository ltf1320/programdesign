clear all
clc
clear all
clc
subD=subass;%组件数据
planeD=plane2;%面数据
ss=size(subD);
ps=size(planeD);
for i=1:ss(1)
    for j=1:ps(1)
        res(i,j)=subD(i,1)/1000*subD(i,2)/1000*(doData(planeD(j,2),planeD(j,1),subD(i,5),0.23))*subD(i,3)/100;
    end
end
res