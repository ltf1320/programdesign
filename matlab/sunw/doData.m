function suma=doData(angle,direction,minW,ddrec)
%angleΪ��ǣ�directionΪ����(�����ϱ���0,1,2,3����minWΪ�������
data=Data(2);
s=size(data);
for i=1:s(1)
    res(i)=getFS(1,data(i,3),data(i,4),data(i,5),data(i,6),data(i,7),data(i,8),data(i,9),angle,data(i,2),data(i,1),direction,ddrec);
    if res(i)<minW
        res(i)=0;
    end
end
suma=sum(res);