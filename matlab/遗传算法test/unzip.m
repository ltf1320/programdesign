function [ x ] = unzip( code )
x=zeros(2,1);
for i=23:-1:1
    x(1)=code(i)+x(1)*2;
    x(2)=code(i+23)+x(2)*2;
end
x(1)=x(1)/10^6;
x(2)=x(2)/10^6;
end

