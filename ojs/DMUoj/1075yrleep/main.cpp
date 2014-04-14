#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=33333;
struct
{
    int to;
    int next;
} e[maxn];
int head[maxn],lon;
int edgemake(int from,int to)
{
    e[++lon].to=to;
    e[lon].next=head[from];
    head[from]=lon;
}
int n,m;
int text[211][211];
struct
{
    int from,to;
} que[maxn];
int sz;


int queue[maxn],check[maxn];
int bfs()
{
    memset(check,0,sizeof(check));
    int st=1,ed=0;
    queue[++ed]=1;
    check[1]=1;
    while(st<=ed)
    {
        int t=queue[st++];
        for(int k=head[t]; k!=-1; k=e[k].next)
        {
            int u=e[k].to;
            if(!text[t][u])
                if(!check[u])
                {
                    check[u]=1;
                    queue[++ed]=u;
                }
        }
    }
    if(check[2]&&check[n])
        return(1);
    else
        return(0);
}

char ans[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d %d",&n,&m))
    {
        memset(head,-1,sizeof(head));
        lon=0,sz=0;
        for(int i=1; i<=m; i++)
        {
            int from,to;
            scanf("%d %d",&from,&to);
            edgemake(from,to);
            edgemake(to,from);
            que[++sz].from=from;
            que[sz].to=to;
        }
        memset(text,0,sizeof(text));
        memset(ans,0,sizeof(ans));

        if(!bfs())
        {
            printf("-1\n");
 //           return 0;
 continue;
        }

        for(int i=sz; i>=1; i--)
        {
            int from=que[i].from,to=que[i].to;
            text[from][to]=1;
            text[to][from]=1;
            ans[i]='0';
            if(!bfs())
            {
                text[from][to]=0;
                text[to][from]=0;
                ans[i]='1';
            }
        }
        int k;
        for(k=strlen(&ans[1]); ans[k]=='0'; k--);
        for(; k>=1; k--)
            printf("%c",ans[k]);
        printf("\n");
    }
}
