#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
int N;
int num[maxn];

int ansn;
int ans[5][2];

void swap(int l,int r)
{
    int t;
    for(int i=0;i<=(r-l)/2;i++)
    {
        t=num[l+i];
        num[l+i]=num[r-i];
        num[r-i]=t;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
    }
    ansn=0;
    for(int i=1;i<=N;i++)
    {
        if(num[i]>i)
        {
            ans[ansn][0]=i;
            ans[ansn][1]=num[i];
            ansn++;
            swap(i,num[i]);
            i--;
            continue;
        }
    }
    printf("%d\n",ansn);
    for(int i=0;i<ansn;i++)
    {
        printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    return 0;
}
