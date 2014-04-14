#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=10000+100;
int N;
int num[maxn];
struct Dui
{
    int max,maxi;
    bool operator<(const Dui &a)
    {
        if(max==a.max)
            return maxi<a.maxi;
        return max<a.max;
    }
};
Dui dui[4*maxn];
int start;

void getStart()
{
    start=2;
    while(start<N)start<<=1;
}

void build_heap()
{
    for(int i=start-1; i>0; i--)
    {
        if(dui[i<<1].max>=dui[i<<1|1].max)
        {
            dui[i].max=dui[i<<1].max;
            dui[i].maxi=dui[i<<1].maxi;
        }
        else
        {
            dui[i].max=dui[i<<1|1].max;
            dui[i].maxi=dui[i<<1|1].maxi;
        }
    }
}

void update(int i)
{
    while(i)
    {
        i>>=1;
        if(dui[i<<1].max>=dui[i<<1|1].max)
        {
            dui[i].max=dui[i<<1].max;
            dui[i].maxi=dui[i<<1].maxi;
        }
        else
        {
            dui[i].max=dui[i<<1|1].max;
            dui[i].maxi=dui[i<<1|1].maxi;
        }
    }
}

int num[maxn];

void input()
{
    for(int i=0; i<N; i++)
        scanf("%d",&num[i]);
}


LL getRes1()
{
    LL res=0;
    memset(dui,0,sizeof(dui));
    getStart();
    for(int i=0; i<N; i++)
    {
        dui[start+i].max=num[i];
        dui[start+i].maxi=i;
    }
    build_heap();
    for(int i=N-1; i>0; i--)
    {
        if(dui[1].max!=dui[start+i].max)
        {
            res+=dui[1].max+dui[start+i].max;
            dui[start+dui[1].maxi].max=dui[start+i].max;
//               dui[start+dui[1].maxi].maxi=dui[start+i].maxi;
            update(start+dui[1].maxi);
        }
        dui[start+i].max=0;
        dui[start+i].maxi=0;
        update(start+i);
    }
    return res;
}
bool yes[maxn];


LL getRes2()
{
    if(N==1) return 0;
    for(int i=0;i<N;i++)
    {
        dui[i].max=num[i];
        dui[i].maxi=i;
    }
    sort(dui,dui+N);
    LL res=0;
    int now;
    memset(yes,0,sizeof(yes));
    if(dui[0].maxi==0)
    {
        res+=dui[1].max+dui[0].max;
        num[0]=dui[1].max;
        num[dui[1].maxi]=
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    LL res;
    while(~scanf("%d",&N))
    {
        input();
    }
    return 0;
}
