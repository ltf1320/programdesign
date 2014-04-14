#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double pi=3.1415926;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    double r1,r2;
    double u=1.1723328E18;
    double parkr,SOIr;
    double oriu;
    while(cin>>r1>>r2)
    {
        cin>>parkr>>SOIr>>oriu;
        double th=pi*sqrt((r1+r2)*(r1+r2)*(r1+r2)/(8*u));
   //     cout<<"tH="<<th<<endl;
        double res=180-sqrt(u/r2)*th/r2*180/pi;//Planetary Phase Angle
        while(res<0.0)
            res+=360;
        while(res>360)
            res-=360;
        double dv=sqrt(u/r1)*(sqrt(2*r2/(r1+r2))-1);
  //      cout<<"Hohmann ¦¤v1 ="<<dv<<endl;
        double ejv=sqrt((parkr*(SOIr*dv*dv-2*oriu)+2*SOIr*oriu)/(parkr*SOIr));
  //      cout<<"Ejection Velocity = "<<ejv<<endl;
        double er=ejv*ejv/2-oriu/parkr;
        double h=parkr*ejv;
        double e=sqrt(1+2*er*h*h/(oriu*oriu));
        double angle=180-acos(1/e)*180/pi;  //Ejection Angle
        printf("%.1f\n%.1f\n",res,angle);
    }
    return 0;
}
