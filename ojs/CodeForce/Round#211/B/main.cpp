#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=200000;
int num[maxn];
int res;
int nres;
int nj;
int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
        scanf("%d",&num[i]);
    for(int i=0;i<K;i++)
        nres+=num[i];
    res=nres;
    nj=0;
    for(int i=K;i<N;i++)
    {
        nres+=num[i];
        nres-=num[i-K];
        if(nres<res)
        {
            res=nres;
            nj=i-K+1;
        }
    }
    printf("%d\n",nj+1);
    return 0;
}
