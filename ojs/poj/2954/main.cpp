#include <cstdio>
using namespace std;

int x1,y1,x2,y2,x3,y3;

int gcd(int a,int b)
{
    int t;
    for(;b;t=b,b=a%b,a=t);
    return a;
}

int abs(int a)
{
    return a>0?a:-a;
}

int getEV()
{
    int g1,g2,g3;
    g1=gcd(abs(x2-x1),abs(y2-y1));
    if((x2-x1)==0) g1=abs(y2-y1);
    if((y2-y1)==0) g1=abs(x2-x1);
    g2=gcd(abs(y3-y1),abs(x3-x1));
    if((x3-x1)==0) g2=abs(y3-y1);
    if((y3-y1)==0) g2=abs(x3-x1);
    g3=gcd(abs(y3-y2),abs(x3-x2));
    if((x3-x2)==0) g3=abs(y3-y2);
    if((y3-y2)==0) g3=abs(x3-x2);
    return g1+g2+g3;
}

int main()
{
    freopen("in.txt","r",stdin);
    int s,e;
    while(~scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3))
    {
        if(!(x1||y1||x2||y2||x3||y3)) break;
        s=abs((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1)); //area
        e=getEV();
        printf("%d\n",(s-e)/2+1);
    }
    return 0;
}
