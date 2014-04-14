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
long long sum;
long long res;
int main()
{
    scanf("%d",&N);
    min1=min2=inf;
    mx=-1;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&num[i]);
        sum+=num[i];
    }
    sort(num,num+N);
    if(num[0]+num[1]<=num[N-1])
        res=num[N-1];
    else if(num[N-1]>num[0])
    {
        if(num[N-1]%2)  res++;
        res+=(num[0]+num[1]-num[N-1])/(N-1)+num[N-1];
        if((num[0]+num[1]-num[N-1])%(N-1))
            res++;
    }
    else
    {
        res=sum/(N-1)+(sum%(N-1)==0?0:1);
    }
    printf("%I64d\n",res);
    return 0;
}
