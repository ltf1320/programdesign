#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxn=200;
const int inf=0x3f3f3f3f;

struct EDGE
{
    int from,to;
    double com,rate;
};
EDGE edge[maxn*2];

int n,m;

int ctn;
void add(int from,int to,double rate,double com)
{
    edge[ctn].to=to;
    edge[ctn].from=from;
    edge[ctn].com=com;
    edge[ctn].rate=rate;
    ctn++;
}

double dis[maxn];
double im;

bool bellman(int start)
{
    for(int i=0;i<=n;++i)
        dis[i]=0;
    dis[start]=im;
    bool flag;
    for(int i=0;i<n;i++)
    {
        flag=1;
        for(int j=0;j<ctn;j++)
        {
            if(dis[edge[j].to]<(dis[edge[j].from]-edge[j].com)*edge[j].rate)
            {
                flag=0;
                dis[edge[j].to]=(dis[edge[j].from]-edge[j].com)*edge[j].rate;
            }
        }
        if(flag) break;
        if(i==n-1&&!flag) return true;
    }
    /*
    for(int i=0;i<ctn;i++)
    {
        if(dis[edge[i].to]<(dis[edge[i].from]-edge[i].com)*edge[i].rate)
            return true;
    }
    */
    return false;
}



int main()
{
    freopen("in.txt","r",stdin);
    int start;
    int a,b;
    double com1,com2,rate1,rate2;
    scanf("%d%d%d%lf",&n,&m,&start,&im);
    ctn=0;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%lf%lf%lf%lf",&a,&b,&rate1,&com1,&rate2,&com2);
        add(a,b,rate1,com1);
        add(b,a,rate2,com2);
    }
    if(bellman(start)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
