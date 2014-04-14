#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+100;
int N,M;
struct Grass
{
    int cost,green;
    bool operator<(const Grass &a)const
    {
        if(cost==a.cost)
            return green<a.green;
        else return cost<a.cost;
    }
};
Grass grs[maxn],nds[maxn];
bool used[maxn];
int next[maxn];

int find(Grass &nd)
{
    int l=0,r=M;
    int m;
    while(r>=l)
    {
        m=(l+r)>>1;
        if(nd<grs[m])
            r=m-1;
        else l=m+1;
    }
    if(r==-1) r=0;
    for(int i=r;i<N;i=next[i])
    {
        if(!used[i])
        {
            used[i]=1;
            for(int j=r;j<=i;j++)
                next[j]=i+1;
            return grs[i].cost;
        }
    }
    return -1;
}

void work()
{
    int res=0,tmp;
    sort(grs,grs+M);
    for(int i=0;i<N;i++)
    {
        tmp=find(nds[i]);
        if(tmp==-1)
        {
            res=-1;
            break;
        }
        res+=tmp;
    }
    printf("%d\n",res);
}

void input()
{
    for(int i=0;i<N;i++)
        scanf("%d%d",&nds[i].cost,&nds[i].green);
    for(int i=0;i<M;i++)
        scanf("%d%d",&grs[i].cost,&grs[i].green);
}

void init()
{
    memset(used,0,sizeof(used));
    for(int i=0;i<M;i++)
        next[i]=i+1;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
