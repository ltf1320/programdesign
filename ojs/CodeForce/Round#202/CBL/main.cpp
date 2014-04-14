#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+100;
const int inf=0x3f3f3f3f;
int num[maxn];
int min1,min2;
int mx;
int N;
long long res;
int main()
{
    scanf("%d",&N);
    min1=min2=inf;
    mx=-1;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&num[i]);
    }
    while(true)
    {
        sort(num,num+N);
        if(!num[N-1]) break;
        for(int i=1;i<N;i++)
        {
            if(num[i]>0)
                num[i]--;
        }
        res++;
    }
    printf("%I64d\n",res);
    return 0;
}
