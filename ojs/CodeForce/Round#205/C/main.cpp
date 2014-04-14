#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
int N;
int num[maxn],s[maxn];
int sum[maxn];
int psum,asum;


int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&num[i]);
        sum[i]=sum[i-1]+num[i];
    }
    getchar();
    char ch;
    for(int i=1;i<=N;i++)
    {
        ch=getchar();
        if(ch=='1')
        {
            s[i]=1;
            psum+=num[i];
        }
    }
    asum=psum;
    for(int i=1;i<=N;i++)
    {
        if(s[i])
        {
            psum-=num[i];
            asum=max(asum,psum+sum[i-1]);
        }
    }
    printf("%d\n",asum);
    return 0;
}
