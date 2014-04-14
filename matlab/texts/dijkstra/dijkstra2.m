function res=dijkstra2(X,from,to)
%this is a function to use dijkstra's algorithm to calculate the lenth of
%the sortest route between from and to

%X is a maxtri with the map
%every line refers to a edge that from X(i,1) to X(i,2) end the lenth is
%X(i,3)

%use edge to save the edges of the map
%1 is to,2 is next ,3 is lenth
s=size(X);
sx=s(1);
box=zeros(sx);
ent=1;
for i=1:sx
    edge(i,1)=X(i,2);
    edge(i,2)=box(X(i,1));
    edge(i,3)=X(i,3);
    box(X(i,1))=ent;
    ent=ent+1;
end

vis=zeros(sx);
for i=1:sx
    dis(i)=inf;
end
for i=1:sx
    dis(i)=inf;
end
dis(from)=0;

for i=1:sx
    m=inf;
    mx=-1;
    for j=1:sx
        if vis(j)==0 & dis(j)<m
            mx=j;
            m=dis(j);
        end
    end
    now=box(mx);
    while now~=0;
        if dis(edge(now,1))>dis(mx)+edge(now,3)
            dis(edge(now,1))=dis(mx)+edge(now,3);
        end
        now=edge(now,2);
    end
    vis(mx)=1;
end
res=dis(to);