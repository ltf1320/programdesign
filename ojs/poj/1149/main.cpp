#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
const int maxm=1000+10;
int N,M;
int num[maxm];
int con[maxm][maxm];
int now[maxm];

int main()
{
    freopen("in.txt","r",stdin);
    int a,b;
    int t1,t2;
    int res;
    while(~scanf("%d%d",&N,&M))
    {
        res=0;
        memset(conn,0,sizeof(conn));
        for(int i=1;i<=M;i++)
            scanf("%d",&num[i]);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a);
            for(int i=0;i<a;i++)
                scanf("%d",&now[i]);
            for(int i=0;i<a;i++)
                for(int j=0;j<a;j++)
                    con[i][j]=1;
            scanf("%d",&b);
        }
        printf("%d\n",res);
    }
    return 0;
}
