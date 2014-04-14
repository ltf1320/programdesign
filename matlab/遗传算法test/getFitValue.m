function [ fitValue,SFitValue ] = getFitValue( genaration )
%GETFITVALUE Summary of this function goes here
%   Detailed explanation goes here
global popsize;
SFitValue=zeros(popsize,1);
fitValue=zeros(popsize,1);
for i=1:popsize
    fitValue(i)=func(unzip(genaration(i,:)));
    if i==1
        SFitValue(i)=fitValue(i);
    else
        SFitValue(i)=SFitValue(i-1)+fitValue(i);
    end
end
for i=1:popsize
    SFitValue(i)=SFitValue(i)/SFitValue(popsize);
end
end


