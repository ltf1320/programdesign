#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=200+10;
int N,M;
int num[maxn];
bool more[maxn];
double p,E1,E2,res;

void print(double p)
{
    printf("%d.",(int)floor(p));
    printf("%d%d",((int)(p*10))%10,((int)(p*100))%10);
    puts("");
}

int main()
{
    int t;
    int nxt,mx;
    while(~scanf("%d",&N))
    {
        memset(more,0,sizeof(more));
        for(int i=1;i<=N;i++)
            scanf("%d",&num[i]);
        scanf("%d",&M);
        for(int i=0;i<M;i++)
        {
            scanf("%d",&t);
            more[t]=1;
        }
        mx=0;
        nxt=0;
        E1=E2=0;
        for(int i=1;i<=N;i++)
        {
            if(more[i])
            {
                nxt++;
                E1+=num[i];
            }
            else E2+=num[i];
            mx=max(num[i],mx);
        }
        if(mx==0)
        {
            puts("0.00");
            continue;
        }
        if(nxt==N)
        {
            puts("inf");
            continue;
        }
        p=1.0*nxt/N;
        E1/=nxt;
        E2/=(N-nxt);
        if(nxt==0)
        {
            printf("%.2f\n",E2);
            continue;
        }
        res=(1-p)*E2+p/(1-p)*(E1+(1-p)*E2);
        printf("%.2f\n",res);
    }
    return 0;
}
