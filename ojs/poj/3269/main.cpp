#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=10000+100;
const LL inf=(LL)0x3f3f3f3f*0x3f3f3f3f;
int N;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};

int mabs(int a)
{
    return a>0?a:-a;
}

struct Point
{
    int x,y;
    bool operator<(const Point &a)const
    {
        if(x==a.x)
            return y<a.y;
        return x<a.x;
    }
};
Point pnt[maxn];

int y[maxn];

LL getLen(int x,int y)
{
    LL res=0;
    for(int i=1;i<=N;i++)
    {
        res+=mabs(x-pnt[i].x)+mabs(y-pnt[i].y);
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int mx1,mx2,my1,my2;
    int rx,ry;
    int res;
    LL rlen,tlen;
    bool flag;
    while(~scanf("%d",&N))
    {
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&pnt[i].x,&y[i]);
            pnt[i].y=y[i];
        }
        sort(pnt+1,pnt+N+1);
        sort(y+1,y+N+1);
        if(N&1)
        {
            mx1=pnt[N/2+1].x;
            my1=y[N/2+1];
            res=1;
            rx=mx1;ry=my1;
            flag=0;
            for(int i=1;i<=N;i++)
            {
                if(pnt[i].x==rx&&pnt[i].y==ry)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                rlen=inf;
                for(int i=0;i<4;i++)
                {
                    tlen=getLen(rx+dx[i],ry+dy[i]);
                    if(tlen==rlen)
                        res++;
                    else if(tlen<rlen)
                    {
                        res=1;
                        rlen=tlen;
                    }
                }
            }
            else rlen=getLen(rx,ry);
            printf("%I64d %d\n",rlen,res);
        }
        else
        {
            mx1=pnt[N/2].x;mx2=pnt[N/2+1].x;
            my1=y[N/2];my2=y[N/2+1];
            res=(mx2-mx1+1)*(my2-my1+1);
            rx=mx1;ry=my1;
            for(int i=1;i<=N;i++)
            {
                if(pnt[i].x>=mx1&&pnt[i].x<=mx2&&pnt[i].y>=my1&&pnt[i].y<=my2)
                {
                    if(pnt[i].x==rx&&pnt[i].y==ry)
                    {
                        ry++;
                        if(ry>my2)
                        {
                            ry=my1;
                            rx++;
                        }
                    }
                    res--;
                }
            }
            printf("%I64d %d\n",getLen(rx,ry),res);
        }
    }
    return 0;
}
