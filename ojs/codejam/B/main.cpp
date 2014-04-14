#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100+10;
int map[maxn][maxn];
int N,M;

bool judge()
{
    bool f;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            f=1;
            for(int k=0;k<M;k++)
                if(map[i][k]>map[i][j])
                {
                    f=0;
                    break;
                }
            if(f) continue;
            for(int k=0;k<N;k++)
                if(map[k][j]>map[i][j])
                    return 0;
        }
    return 1;
}

int main()
{
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int T;
    int cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
            {
                scanf("%d",&map[i][j]);
            }
        if(judge())
            printf("Case #%d: YES\n",cas);
        else printf("Case #%d: NO\n",cas);
    }
    return 0;
}
