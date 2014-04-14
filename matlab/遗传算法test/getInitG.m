function [ generation ] = getInitG(  )

global popsize
generation=zeros(popsize,46);
for i=1:popsize
    a=3*rand;
    b=3*rand;
    generation(i,:)=zip([a b]);
end

end

