function res=compare(p1,p2,err)
%if the right of p1 can match the left of p2

% if size(p1)~=size(p2)
%     res=0;
% else
    sz=size(p1);
    sum=0;
    for i=1:sz(1)
        if p1(i,sz(2))~=p2(i,1)
            sum=sum+1;
        end
    end
    if sum<err
        res=1;
    else
        res=0;
    end
%end