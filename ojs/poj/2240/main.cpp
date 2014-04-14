#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

const int maxn=1000+10;
const int inf=0x3f3f3f3f;

int n;

struct EDGE
{
    int from,to;
    double c;
};
EDGE edge[maxn];
map<string,int> mm;
double dis[maxn];

int ctn;

bool bellman(int start)
{
    memset(dis,0,sizeof(dis));
    dis[start]=1;
    bool flag;
    for(int i=0;i<n;i++)
    {
        flag=1;
        for(int j=0;j<ctn;j++)
        {
            if(dis[edge[j].to]<(dis[edge[j].from])*edge[j].c)
            {
                flag=0;
                dis[edge[j].to]=(dis[edge[j].from])*edge[j].c;
            }
        }
        if(flag) break;
        if(i==n-1&&!flag) return true;
    }
 /*   for(int i=0;i<ctn;i++)
    {
        if(dis[edge[i].to]<(dis[edge[i].from])*edge[i].c)
            return true;
    }
 */   return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    string t1,t2;
    int m;
    int t1n,t2n;
    double h;
    int cas=0;
    while(~scanf("%d",&n))
    {
        cas++;
        mm.clear();
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            cin>>t1;
            mm[t1]=i;
        }
        scanf("%d",&m);
        ctn=0;
        for(int i=0;i<m;i++)
        {
            cin>>t1>>h>>t2;
            t1n=mm[t1];
            t2n=mm[t2];
            edge[ctn].from=t1n;
            edge[ctn].to=t2n;
            edge[ctn++].c=h;
        }
        if(bellman(0)) printf("Case %d: Yes\n",cas);
        else printf("Case %d: No\n",cas);
    }
    return 0;
}
