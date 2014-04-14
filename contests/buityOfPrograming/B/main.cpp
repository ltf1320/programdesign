#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=30000;
typedef long long LL;
int get(int n,int m)
{
    if(n<=m)
        return n*(m-1);
    else
        return (n-1)*m;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    int N,M,K;
    int c,md;
    LL res;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&K);
        res=0;
        c=K/N;
        for(int i=1;i<=M;i++)
            res+=get(i,c);
        md=K%N;
        res+=get(c+1,md);
        cout<<res<<endl;
    }
    return 0;
}
