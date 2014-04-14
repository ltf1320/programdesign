#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=300000+100;
int N,K;

int a[maxn];

bool judge(int c)
{
    for(int i=0;i<N;i++)
    {
        if(a[i]%c>K)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
    sort(a,a+N);
    bool flag=0;
    for(int i=a[0];i>=0;i--)
    {
        if(judge(i))
        {
            flag=1;
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
