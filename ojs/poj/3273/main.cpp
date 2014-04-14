#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
const int inf=100000*10000+100;

int N,M;
int money[maxn];
int MAX;
bool judge(int m)
{
    int now=0,mon=1;
    for(int i=0; i<N; i++)
    {
        if(now+money[i]>m)
        {
            now=money[i];
            mon++;
        }
        else now+=money[i];
        if(mon>M)
            return false;
    }
    return true;
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        MAX=0;
        for(int i=0; i<N; i++)
        {
            scanf("%d",&money[i]);
            MAX=max(MAX,money[i]);
        }
        int l=MAX,r=inf;
        int m;
        while(r>=l)
        {
            m=(r+l)>>1;
            if(judge(m))
                r=m-1;
            else l=m+1;
        }
        printf("%d\n",r+1);
    }
    return 0;
}
