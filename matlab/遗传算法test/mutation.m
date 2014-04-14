function [ mute ] = mutation( generation )
global popsize;
global mutep;
mute=zeros(popsize,46);
for i=1:popsize
    mute(i,:)=generation(i,:);
    if(isDo(mutep))
        k=ceil(rand*46);
        mute(i,k)=abs(generation(i,k)-1);
    end
end

end

