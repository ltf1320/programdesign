function res=getA(hn,time)

sres=-sin(getTimeAngle(time))*cos(CWJ(hn))/cos(SunHighAngle(hn,time));
res=asin(sres);