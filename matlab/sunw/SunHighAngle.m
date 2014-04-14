function res=SunHighAngle(hn,time)
sres=sin(40.1/180*pi)*sin(CWJ(hn))+cos(40.1/180*pi)*cos(CWJ(hn))*cos(getTimeAngle(time));
res=asin(sres);
