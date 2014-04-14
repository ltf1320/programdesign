#include <iostream>
#include <cstdio>

using namespace std;



int main()
{
    double s,r;
    int y;
    scanf("%lf%lf%d",&r,&s,&y);
    r=1+r/100;
    for(int i=0;i<y;i++)
    {
        s=s*r;
    }
    printf("%d\n",(int)s);
    return 0;
}
