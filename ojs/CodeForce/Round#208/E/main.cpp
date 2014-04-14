#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
int N,M;
int map[maxn][maxn];
const int inf=0x3f3f3f3f;
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d",&map[i][j]);
    int res=inf,nres=0;
    for(int i=0;i<N;i++)
    {
        nres=0;
        for(int j=0;j<M;j++)
        {
            if(map[i][j])
                nres++;
            else
            {
                if(nres)
                    res=min(res,nres);
                nres=0;
            }
        }
        if(nres)
            res=min(res,nres);
    }
    for(int i=0;i<M;i++)
    {
        nres=0;
        for(int j=0;j<N;j++)
        {
            if(map[j][i])
                nres++;
            else
            {
                if(nres)
                    res=min(res,nres);
                nres=0;
            }
        }
        if(nres)
            res=min(res,nres);
    }
    if(res==inf||res<2)
        printf("-1\n");
    else
    {
        for(int i=2;i<res;i++)
        {
            if((res-1)%i==0)
                printf("%d ",i);
        }
        puts("");
    }
    return 0;
}
