#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int C,H,B;
int ti[maxn];
int dpl[maxn][maxn];
int dpr[maxn][maxn];

int mabs(int a)
{
    return a>0?a:-a;
}

void printdp()
{
    for(int i=0;i<=H;i++)
    {
        for(int j=0;j<=H;j++)
            printf("%d ",dpl[i][j]);
        puts("");
    }
    puts("");
    for(int i=0;i<=H;i++)
    {
        for(int j=0;j<=H;j++)
            printf("%d ",dpr[i][j]);
        puts("");
    }
    puts("");
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int h,t;
    int res;
    int end;
    while(~scanf("%d%d%d",&C,&H,&B))
    {
        memset(ti,0,sizeof(ti));
        end=B;
        for(int i=0;i<C;i++)
        {
            scanf("%d%d",&h,&t);
            ti[h]=max(ti[h],t);
            end=max(end,h);
        }
        dpl[0][end]=ti[0];
        dpr[0][end]=max(ti[end],end);
        for(int i=0;i<=B;i++)
            for(int j=end;j>=B;j--)
            {
                if(i==0&&j==end) continue;
                dpl[i][j]=dpr[i][j]=inf;
                if(i>0)
                {
                    dpl[i][j]=min(dpl[i][j],dpl[i-1][j]+1);
                    dpr[i][j]=min(dpr[i][j],dpl[i-1][j]+j+1-i);
                }
                if(j<end)
                {
                    dpr[i][j]=min(dpr[i][j],dpr[i][j+1]+1);
                    dpl[i][j]=min(dpl[i][j],dpr[i][j+1]+j+1-i);
                }
                dpl[i][j]=max(dpl[i][j],ti[i]);
                dpr[i][j]=max(dpr[i][j],ti[j]);
            }
        res=min(dpr[B][B],dpl[B][B]);
        printf("%d\n",res);
//        printdp();
    }
    return 0;
}
