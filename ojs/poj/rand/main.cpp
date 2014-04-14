#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <ctime>
using namespace std;
const int maxn=100000000;
int tmp[100];

int main()
{
    freopen("out.txt","w",stdout);
    // int N=20,M=20;
    srand(time(0));
    double u=1.1723328E18;
    int cnt=0;
    for(int k=0;k<10000;k++)
    {
        double r1=((double)rand()/RAND_MAX*(6E10))+3E9;
        double r2=((double)rand()/RAND_MAX*(6E10))+3E9;
        double parkr=((double)rand()/RAND_MAX*(1E7))+1E6;
        double SOIr=((double)rand()/RAND_MAX*(1E8))+parkr;
        double oriu=((double)rand()/RAND_MAX*(1E14))+1E9;
        double dv=sqrt(u/r1)*(sqrt(2*r2/(r1+r2))-1);
  //      cout<<"Hohmann ¦¤v1 ="<<dv<<endl;
        double ejv=sqrt((parkr*(SOIr*dv*dv-2*oriu)+2*SOIr*oriu)/(parkr*SOIr));
  //      cout<<"Ejection Velocity = "<<ejv<<endl;
        double er=ejv*ejv/2-oriu/parkr;
        double h=parkr*ejv;
        double e=sqrt(1+2*er*h*h/(oriu*oriu));

        if(SOIr*dv*dv-2*oriu<=0||e<1.0)
        {
            k--;
            cnt++;
            continue;
        }

        printf("%.2f\n%.2f\n",r1,r2);
        printf("%.2f\n%.2f\n%.2f\n\n",parkr,SOIr,oriu);
    }
    cout<<endl<<cnt<<endl;
    return 0;
}
