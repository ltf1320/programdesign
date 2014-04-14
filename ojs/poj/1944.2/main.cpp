#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
const int maxP=10000+100;
const int inf=0x3f3f3f3f;
int N,P;
int to[maxn];
int F[maxP],T[maxP];


int input()
{
    int t;
   if(scanf("%d%d",&N,&P)==EOF) return EOF;
   for(int i=0;i<P;i++)
   {
       scanf("%d%d",&F[i],&T[i]);
       if(F[i]>T[i])
       {
           t=F[i];
           F[i]=T[i];
           T[i]=t;
       }
   }
   return 0;
}

int work()
{
    int res=inf,now;
    int k;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            to[j]=j;
        for(int j=0;j<P;j++)
        {
            if(i>F[j]&&i<T[j])
            {
                to[1]=max(to[1],F[j]);
                to[T[j]]=N+1;
            }
            else to[F[j]]=max(to[F[j]],T[j]);
        }
        now=0;
        k=0;
        for(int j=1;j<=N;j++)
        {
            if(to[j]>k)
            {
                now+=to[j]-max(j,k);
                k=to[j];
            }
        }
        res=min(res,now);
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~input())
        printf("%d\n",work());
    return 0;
}
