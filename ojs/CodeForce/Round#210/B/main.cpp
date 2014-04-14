#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=100000+110;
int res[maxn];
int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    if(K==N)
        puts("-1");
    else
    {
        for(int i=1;i<=N;i++)
            res[i]=i;
        for(int j=1;j<=N-K;j+=2)
        {
            if(j==N-K)
                swap(res[1],res[N-K]);
            else
                swap(res[j],res[j+1]);
        }
        for(int i=1;i<=N;i++)
        {
            if(i>1)
                putchar(' ');
            printf("%d",res[i]);
        }
    }
    return 0;
}
