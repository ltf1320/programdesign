#include <iostream>
#include<cmath>
#include <cstdio>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
   float a,b,c;
   double cosC,sinC,area;
   while(1)
   {
       cin>>a>>b>>c;
       if(!cin) break;
       if(a+b>c&&a+c>b&&b+c>a)
       {
           cosC=(a*a+b*b-c*c)/(2*a*b);
           sinC=sqrt(1-cosC*cosC);
           area=0.5*a*b*sinC;
           printf("%.3f",area);
           cout<<endl;
       }
       else cout<<"no"<<endl;
   }
}
