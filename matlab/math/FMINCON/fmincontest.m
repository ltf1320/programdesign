clc
clear all

%options=optimset;
[x,y]=fmincon('fun1',rand(2,1),[],[],[],[],zeros(2,1),[],'fun2')
