#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10;
const int maxv=20000*21+1000;
int num[maxn];
bool c[maxv];

void work()
{
    int sum;
    int k;
    int cas=1;
    bool start=0;
    while(true)
    {
        memset(c,0,sizeof(c));
        c[0]=1;
        sum=0;
        for(int i=1; i<=6; i++)
        {
            scanf("%d",&num[i]);
            sum+=num[i]*i;
        }
        if(sum==0) return;
        if(start) putchar('\n');
        else start=1;
        if(sum%2)
        {
            printf("Collection #%d:\nCan't be divided.\n",cas++);
            continue;
        }
        sum/=2;
        for(int i=1; i<=6; i++)
        {
            k=1;
            while(k<=num[i])
            {
                for(int j=sum; j>=k*i; j--)
                    if(c[j-i*k]==1)
                        c[j]=1;
                num[i]-=k; //!
                k*=2;
            }
            k=num[i];
            for(int j=sum; j>=k*i; j--)
                if(c[j-i*k])
                    c[j]=1;
            if(c[sum]==1) break;
        }
        if(c[sum]) printf("Collection #%d:\nCan be divided.\n",cas++);
        else printf("Collection #%d:\nCan't be divided.\n",cas++);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    work();
    return 0;
}
