#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double err=1E-7;
const int maxn=10000;
int N;
struct Node
{
    int x,y;
};
Node nds[20];

struct Tri
{
    double c[3];
    bool operator<(const Tri &a) const
    {
        for(int i=0;i<2;i++)
            if(c[i]<=a.c[i]-err||c[i]>=a.c[i]+err)
                return c[i]<a.c[i];
        return false;
    }
    bool operator==(const Tri &a)
    {
        for(int i=1;i>=0;i--)
            if(c[i]<=a.c[i]-err||c[i]>=a.c[i]+err)
                return false;
        return true;
    }
};
Tri tri[maxn];



int main()
{
    freopen("in.txt","r",stdin);
    int tnt;
    int res;
    int d;
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        for(int i=0;i<N;i++){
            scanf("%d%d",&nds[i].x,&nds[i].y);
            for(int j=0;j<i;j++)
                if(nds[i].x==nds[j].x&&nds[i].y==nds[j].y)
                {
                    N--;
                    i--;
                    break;
                }
        }
        tnt=0;
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                for(int k=j+1;k<N;k++)
                {
                    if((nds[i].x-nds[j].x)*(nds[k].y-nds[i].y)!=(nds[k].x-nds[i].x)*(nds[i].y-nds[j].y))
                    {
                        tri[tnt].c[0]=(nds[i].x-nds[j].x)*(nds[i].x-nds[j].x)+(nds[i].y-nds[j].y)*(nds[i].y-nds[j].y);
                        tri[tnt].c[1]=(nds[j].x-nds[k].x)*(nds[j].x-nds[k].x)+(nds[j].y-nds[k].y)*(nds[j].y-nds[k].y);
                        tri[tnt].c[2]=(nds[i].x-nds[k].x)*(nds[i].x-nds[k].x)+(nds[i].y-nds[k].y)*(nds[i].y-nds[k].y);
                        sort(tri[tnt].c,tri[tnt].c+3);
                        tri[tnt].c[0]=tri[tnt].c[0]/tri[tnt].c[2];
                        tri[tnt].c[1]=tri[tnt].c[1]/tri[tnt].c[2];
                        tnt++;
                    }
                }
        sort(tri,tri+tnt);
        if(tnt) res=1;
        else res=0;
        for(int i=0;i<tnt-1;i++)
        {
            d=1;
            for(int j=i+1;j<tnt;j++)
            {
                if(tri[i]==tri[j])
                    d++;
                else {i=j-1;break;}
            }
            if(d>res)
                res=d;
        }
        printf("%d\n",res);
    }
    return 0;
}
