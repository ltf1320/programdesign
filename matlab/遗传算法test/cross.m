function [ cs1,cs2 ] = cross( in1,in2 )
%the mating

pp=round(rand*46);
cs1=zeros(46,1);
cs2=zeros(46,1);
for i=1:pp
    cs1(i)=in2(i);
    cs2(i)=in1(i);
end

for i=pp+1:46;
    cs1(i)=in1(i);
    cs2(i)=in2(i);
end
end


