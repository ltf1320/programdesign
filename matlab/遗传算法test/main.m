clc
clear all

global popsize;
global mutep;
global matep;

popsize=50;
mutep=0.01;
matep=0.8;

ogeneration=getInitG();
[fitValue SFitValue]=getFitValue(ogeneration);

maxFitValue=zeros(popsize);
FitCode=zeros(popsize,46);
meanFitValue=zeros(popsize);

gennum=50;

for i=1:gennum
    
    ngeneration=copy(ogeneration,SFitValue); %¸´ÖÆ
    for j=1:2:popsize  %½»Åä
        if isDo(matep)
            [a b]=cross(ngeneration(j,:),ngeneration(j+1,:));
            ngeneration(j,:)=a;
            ngeneration(j+1,:)=b;
        end
    end
    ngeneration=mutation(ngeneration); %±äÒì
    [fitValue SFitValue]=getFitValue(ngeneration);
    for j=1:popsize
        if fitValue(j)>maxFitValue(i)
            maxFitValue(i)=fitValue(j);
            FitCode(i,:)=ngeneration(j,:);
        end
    end
    meanFitValue(i)=mean(fitValue);
end

rMaxValue=0;
for i=1:gennum
    if maxFitValue(i)>rMaxValue
        rMaxValue=maxFitValue(i);
        rMaxCode=FitCode(i,:);
    end
end
rMaxValue=10-rMaxValue
x=unzip(rMaxCode)

figure(1)
plot(1:popsize,maxFitValue);