#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
int cost[20];
int v;
int main()
{
    scanf("%d",&v);
    bool flag=0;
    for(int i=1;i<=9;i++)
    {
        scanf("%d",&cost[i]);
        if(cost[i]<=v)
            flag=1;
    }
    if(!flag)
    {
        puts("-1");
        return 0;
    }
    int id=1;
    int mx=cost[1];
    for(int i=2;i<=9;i++)
    {
        if(cost[i]<=mx)
        {
            id=i;
            mx=cost[i];
        }
    }
    int pn=v/cost[id];
    int rest=v%cost[id];
    for(int i=9;i>id;i--)
    {
        while((cost[i]-cost[id])<=rest&&pn>0)
        {
            printf("%d",i);
            rest-=cost[i]-cost[id];
            pn--;
        }
    }
    for(int i=0;i<pn;i++)
        printf("%d",id);
    puts("");
    return 0;
}
