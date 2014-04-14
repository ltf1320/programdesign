#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=20;
int N;
int sym[maxn];//1 for +,2 for -,3 for .
int RES;
int b[]= {0,
          0,
          0,
          1,
          1,
          1,
          1,
          6,
          10,
          11,
          17,
          88,
          162,
          197,
          437,
          1350
         };
int p10[maxn];

int getS(int a)
{
    int res=0;
    while(a)
    {
        res++;
        a/=10;
    }
    return p10[res];
}
int cal()
{
    int sum=0;
    int now=1,pre=1;
    for(int i=1; i<N; i++)
    {
        if(sym[i]!=3)
        {
            if(pre==1)
                sum+=now;
            else if(pre==2)
                sum-=now;
            now=i+1;
            pre=sym[i];
        }
        else now=now*getS(i+1)+i+1;
    }
    if(pre==1)
        sum+=now;
    else if(pre==2)
        sum-=now;
    return sum;
}

void print()
{
    printf("1");
    for(int i=1; i<N; i++)
    {
        putchar(' ');
        switch(sym[i])
        {
        case 1:
            putchar('+');
            break;
        case 2:
            putchar('-');
            break;
        case 3:
            putchar('.');
            break;
        }
        putchar(' ');
        printf("%d",i+1);
    }
    putchar('\n');
}
int dn;
void dfs(int now)
{
    if(dn>N/2+1) return;
    if(RES>20) return;
    if(now==N)
    {
        if(cal()==0)
        {
            RES++;
            if(RES<=20) print();
        }
        return;
    }
    sym[now]=1;
    dfs(now+1);
    sym[now]=2;
    dfs(now+1);
    sym[now]=3;
    dn++;
    dfs(now+1);
    dn--;
}

int main()
{
//   freopen("in.txt","r",stdin);
    scanf("%d",&N);
    p10[0]=1;
    for(int i=1; i<N/2+1; i++)
        p10[i]=p10[i-1]*10;
    dfs(1);
    printf("%d\n",b[N]);
    return 0;
}
