#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=100000+100;

int N,M;
LL res;
LL a[maxn];

void input()
{
    for(int i=0;i<N;i++)
        scanf("%I64d",&a[i]);
}

void work()
{
    res=0;
    for(int i=0;i<N;i++)
        if(a[i]<M)
            res++;
    int pre=0,now=0,tt;
    for(int i=0;i<N;i++)
    {
        now|=a[i];
        if(now>=M)
        {
            res+=(i-pre)*(i-pre-1)/2;
            if(a[i]>=M)
            {
                now=0;
                pre=i+1;
                continue;
            }
            now=tt=0;
            for(int j=i;j>=0;j--)
            {
                tt|=a[j];
                if(tt>=M)
                {
                    res-=(i-j-1)*(i-j-2)/2;
                    pre=j+1;
                    break;
                }
                now|=a[j];
            }
        }
    }
    res+=(N-pre)*(N-pre-1)/2;
    printf("%I64d\n",res);
}


int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        cas++;
        scanf("%d%d",&N,&M);
        input();
        printf("Case #%d: ",cas);
        work();
    }
    return 0;
}
