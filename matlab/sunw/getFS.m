function res=getFS(S,SZ,SS,FZ,DZ,NZ,XZ,BZ,angle,hn,time,direction,ddirc)
%SΪ�����angleΪб����ȣ�directionΪб�淽��(�����ϱ���0��1,2,3��

%ֱ��ǿ��
highAngle=SunHighAngle(hn,time);
SundirAngle=getA(hn,time);
switch(direction)
    case 0
        dirAngle=pi/2+pi+ddirc;
    case 1
        dirAngle=3*pi/2+pi+ddirc;
    case 2
        dirAngle=pi+pi+ddirc;
    case 3
        dirAngle=pi+ddirc;
end
res=FZ*cos(dirAngle-SundirAngle)*abs(sin(highAngle+angle));
%ɢ��ǿ��
switch(direction)
    case 0
        res=res+BZ;
    case 1
        res=res+DZ;
    case 2
        res=res+NZ;
    case 3
        res+XZ;
end
res=res-cos(dirAngle-SundirAngle)*sin(highAngle)*FZ;
res=S*res;