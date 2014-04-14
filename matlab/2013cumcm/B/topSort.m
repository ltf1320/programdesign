function res=topSort(n,rz,vis,map)

sz=size(map);
if n>sz(1)
    res=rz;
    return;
end

que=0
for i=1:sz(1)
    indu=0;
    if vis(i)~=1
        for j=1:sz(2)
            if vis(j)~=1
                 if map(j,i)==1
                    indu=indu+1;
                 end
            end
        end
       if indu==0
           que(size(que)+1)=i;
       end
    end
end


for i=1:size(que)
    rz(n)=que(i)
    vis(que(i))=1;
    now=topsort(n+1,rz,vis,map);
    for j=1:size(now,1)
        res(size(res,1)+1,:)=now(j,:);
    end
    vis(que(i))=0;
end


