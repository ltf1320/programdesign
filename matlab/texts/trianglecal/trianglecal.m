function [x31,y31,x32,y32]=trianglecal(x1,y1,x2,y2,angle1,angle2)
angle3=2*pi-angle1-angle2;
L=sqrt((x1-x2)^2+(y1-y2)^2);
len1=L/sin(angle3)*sin(angle2);
len2=L/sin(angle3)*sin(angle1);
one=sym('(a1-x1)^2+(b1-y1)^2=len1^2');
two=sym('(a1-x2)^2+(b2-y2)^2=len2^2');
[x31,y31,x32,y32]=solve(one,two);
