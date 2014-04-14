clc
clear all
Img=imread('a.jpg');
figure(1)
image(Img);
s=size(Img);
Img(1:50,1:s(2))=2;
Img(51:100,1:s(2))=8;
Img(100:150,1:s(2))=16;
Img(150:200,1:s(2))=64;
Img(200:255,1:s(2))=128;
figure(2)
image(Img)
RE=im2double(Img);
for i=1:s(1)
    for j=1:s(2)
        for k=1:3
            RE(i,j,k)=1-RE(i,j,k);
        end
    end
end
Img=im2uint8(RE);
figure(3)
image(Img);



