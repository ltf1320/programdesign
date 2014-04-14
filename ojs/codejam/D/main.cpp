#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100;
const int maxk=200+10;
int N,K;
int keynum[maxk];
int oped[maxn];
int chskey[maxn][maxk];
int chskeyn[maxn];
int ctkey[maxn];

int stack[maxn];
bool end;
void dfs(int now)
{
    if(now==N)
    {
        end=1;return;
    }
    for(int i=1;i<=N;i++)
    {
        stack[now]=i;
        if(!oped[i]&&keynum[ctkey[i]]>0)
        {
            keynum[ctkey[i]]--;
            for(int j=0;j<chskeyn[i];j++)
                keynum[chskey[i][j]]++;
            oped[i]=1;
            dfs(now+1);
            if(end) return;
            oped[i]=0;
            keynum[ctkey[i]]++;
            for(int j=0;j<chskeyn[i];j++)
                keynum[chskey[i][j]]--;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    int tmp,kk;
    int cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        memset(keynum,0,sizeof(keynum));
        memset(oped,0,sizeof(oped));
        memset(chskeyn,0,sizeof(chskeyn));
        scanf("%d%d",&K,&N);
        for(int i=0;i<K;i++)
        {
            scanf("%d",&tmp);
            keynum[tmp]++;
        }
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&tmp);
            ctkey[i]=tmp;
            scanf("%d",&K);
            for(int j=0;j<K;j++)
            {
                scanf("%d",&kk);
                chskey[i][chskeyn[i]++]=kk;
            }
        }
        end=0;
        dfs(0);
        printf("Case #%d: ",cas);
        if(end)
        {
            for(int i=0;i<N-1;i++)
                printf("%d ",stack[i]);
            printf("%d\n",stack[N-1]);
        }
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
