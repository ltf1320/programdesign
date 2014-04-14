#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
int N,x,y;
int num[maxn];
int sum[maxn];

int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
        sum[i]=sum[i-1]+num[i];
    }
    scanf("%d%d",&x,&y);
    int res=0;
    for(int i=1;i<=N;i++)
    {
        if(sum[i]>=x&&sum[i]<=y)
        {
            if(sum[N]-sum[i]>=x&&sum[N]-sum[i]<=y)
            {
                res=i+1;
                break;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
