#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=80000+100;

int ans[maxn];

bool is[maxn];
int pri[maxn];
int prn;

void getpri()
{
    memset(is,0,sizeof(is));
    pri[prn++]=2;
    for(int i=2;i<maxn;i+=2)
        is[i]=1;
    for(int i=3;i<maxn;i++)
    {
        if(!is[i])
        {
            pri[prn++]=i;
            for(int j=i;j<maxn;j+=2*i)
                is[i]=1;
        }
        else is[i]=0;
    }
}

int findm(int x)
{
    int res=0;
    for(int i=0;i<prn;i++)
    {
        if(pri[i]*pri[i]>x)
            break;
        if(x%pri[i]==0&&is[x/pri[i]])
            res++;
    }
    return res;
}

int findadd(int n,int i,int now)
{
    if(n==3)
    {
        if(is[now])
            return 1;
        else return 0;
    }
    int res=0;
    if(is[now]) res++;
    for(;i<prn;i++)
    {
        if(pri[i]+pri[i]>now) break;
        res+=findadd(n+1,i,now-pri[i]);
    }
    return res;
}

int findmul(int n,int i,int now)
{
    if(n==3)
    {
        if(is[now])
            return 1;
        else return 0;
    }
    int res=0;
    if(is[now]) res++;
    for(;i<prn;i++)
    {
        if(pri[i]*pri[i]>now) break;
        if(now%pri[i]==0)
            res+=findadd(n+1,i,now/pri[i]);
    }
    return res;
}

int find(int x)
{
    int res=0;
    for(int i=0;i<prn;i++)
    {
        if(pri[i]>x)
           break;
        res+=findm(x-pri[i]);
    }
    res+=findadd(1,0,x);
    res+=findmul(1,0,x);
    if(is[x]) res--;
    return res;
}



int main()
{
    getpri();
    int x;
    while(~scanf("%d",&x))
    {
        printf("%d\n",find(x));
    }
    return 0;
}
