#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000000+100;
struct Point
{
    int x,y;
};
Point pts[maxn];

double getArea(Point &a,Point &b,Point &c)
{
    return 1.0*(b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
}

int main()
{
    freopen("in.txt","r",stdin);
    int N;
    double resx,resy,area,na;
    double nx,ny;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        resx=resy=area=0;
        scanf("%d",&N);
        for(int i=0; i<N; i++)
            scanf("%d%d",&pts[i].x,&pts[i].y);
        for(int i=1;i<N-1;i++)
        {
            nx=(1.0*pts[0].x+pts[i].x+pts[i+1].x);
            ny=(1.0*pts[0].y+pts[i].y+pts[i+1].y);
            na=getArea(pts[0],pts[i],pts[i+1]);
            area+=na;
            resx+=nx*na;
            resy+=ny*na;
        }
        printf("%.2f %.2f\n",resx/area/3,resy/area/3);
    }
    return 0;
}
