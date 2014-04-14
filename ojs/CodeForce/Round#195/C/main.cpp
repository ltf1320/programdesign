#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
int N;
int num[maxn];

int maxBit(int n)
{
    int res=-1;
    while(n)
    {
        n>>=1;
        res++;
    }
    return res;
}
int ans[maxn];
int ansn;

bool judge(int bit,int n)
{
    if(n==(1<<bit))
        return true;
    return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    bool found=0;
    int nowbit,pbit,And,start;
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d",&num[i]);
    pbit=maxBit(num[N-1]);
    And=num[N-1];
    for(int i=N-2; i>=0; i--)
    {
        nowbit=maxBit(num[i]);
        if(nowbit==pbit)
        {
            And&=num[i];
        }
        else
        {
            if(judge(pbit,And))
            {
                found=1;
                start=i+1;
                break;
            }
            else
            {
                pbit=nowbit;
                And=num[i];
                for(int j=i+1;j<N;j++)
                    if(num[i]&(1<<pbit))
                        And&=num[i];
            }
        }
    }
    if(!found&&judge(pbit,And))
    {
        found=1;
        start=0;
    }
    if(found)
    {
        ansn=0;
        for(int i=start; i<N; i++)
        {
            if(num[i]&(1<<pbit))
                ans[ansn++]=num[i];
        }
        printf("%d\n",ansn);
        for(int i=0; i<ansn-1; i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[ansn-1]);
    }
    else
    {
        printf("%d\n",N);
        for(int i=0; i<N-1; i++)
            printf("%d ",num[i]);
        printf("%d\n",num[N-1]);
    }
    return 0;
}
