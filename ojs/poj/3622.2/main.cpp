#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=100000+100;
typedef long long LL;
int N,M;

struct Grass
{
    int cost,green;
    bool operator<(const Grass &a)const
    {
        if(green==a.green)
            return cost>a.cost;
        return green>a.green;
    }
};
Grass nds[maxn];

multimap<int,int> grs;

void work()
{
    sort(nds,nds+N);
    bool flag;
    LL res=0;
    multimap<int,int>::iterator iter;
    for(int i=0;i<N;i++)
    {
        flag=0;
        for(iter=grs.lower_bound(nds[i].cost);iter!=grs.end();iter++)
        {
            if(iter->second>=nds[i].green)
            {
                flag=1;
                res+=iter->first;
                grs.erase(iter);
                break;
            }
        }
        if(!flag)
        {
            printf("-1\n");
            return;
        }
    }
    printf("%I64d\n",res);
}

void input()
{
    int c,g;
    for(int i=0;i<N;i++)
        scanf("%d%d",&nds[i].cost,&nds[i].green);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&c,&g);
        grs.insert(make_pair(c,g));
    }
}

void init()
{
    grs.clear();
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
