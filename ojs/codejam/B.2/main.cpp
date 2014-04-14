#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
int map[maxn][maxn];
int maxr[maxn],maxc[maxn];
int N,M;

bool judge()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(map[i][j]<maxr[i]&&map[i][j]<maxc[j])
                return 0;
        }
    return 1;
}

int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int T;
    int cas=0;
    scanf("%d",&T);
    while(T--)
    {
        memset(maxr,0,sizeof(maxr));
        memset(maxc,0,sizeof(maxc));
        cas++;
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
            {
                scanf("%d",&map[i][j]);
                maxr[i]=max(maxr[i],map[i][j]);
                maxc[j]=max(maxc[j],map[i][j]);
            }
        if(judge())
            printf("Case #%d: YES\n",cas);
        else printf("Case #%d: NO\n",cas);
    }
    return 0;
}
