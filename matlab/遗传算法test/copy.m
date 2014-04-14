function [ new ] = copy( old,SFitValue)
global popsize
new=zeros(popsize,46);
for i=1:popsize
    np=rand;
    for j=1:popsize
        if SFitValue(j)>=np
            new(i,:)=old(j,:);
            break;
        end;
    end
end

end