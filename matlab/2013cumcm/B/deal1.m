clc;
clear all;
for i=1:18
    if i<10
        name(i,:)=sprintf('00%d',i);
    else
        name(i,:)=sprintf('0%d',i);
    end
end
suf='.bmp';
path='.\p1\';
for i=1:18
    pic(i,:,:)=imread([path name(i,:) suf]);
end

% for i=1:3
%     figure(i);
%     a=reshape(pic(i,:,:),size(pic,2),size(pic,3));
%     imshow(a);
% end
a=im2bw(reshape(pic(1,:,:),size(pic,2),size(pic,3)));
map=zeros(18,18);
for i=1:18
    for j=1:18
        if compare( im2bw(reshape(pic(i,:,:),size(pic,2),size(pic,3)),0.5),im2bw(reshape(pic(j,:,:),size(pic,2),size(pic,3)),0.5),10)==1
            map(i,j)=1;
        end
    end
end

ord=topSort(1,zeros(1,18),zeros(18),map);


