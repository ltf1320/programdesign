#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
const int maxd=500;

int days[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int peo[maxd];

int getDay(int m,int d)
{
    int res=0;
    for(int i=1;i<m;i++)
        res+=days[i];
    res+=d;
    res+=110;
    return res;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,d,p,t,day;
    int N;
    memset(peo,0,sizeof(peo));
    scanf("%d",&N);
    int res=0;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d%d",&m,&d,&p,&t);
        day=getDay(m,d);
        for(int j=day-1;j>=day-t;j--)
            peo[j]+=p;
    }
    for(int i=0;i<maxd;i++)
        if(res<peo[i]) res=peo[i];
    printf("%d\n",res);
    return 0;
}
