#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=25;
const int inf=0x3f3f3f3f;
int N;
bool map[maxn][maxn];
int mk,mp;
int count(int a)
{
    int res=0;
    while(a)
    {
        if(a&1)
            res++;
        a>>=1;
    }
    return res;
}

int ans,anst;

bool in[1<<maxn];
int dis[1<<maxn];
queue<int> que;

int getPd()
{
    int res=0;
    for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++)
        {
            if(!map[i][j])
                res++;
        }
    return res;
}

int getDis(int now,int i)
{
    int res=0;
    for(int j=1;j<=N;j++)
    {
        if(j==i) continue;
        if(now&(1<<(j-1)))
        {
            if(!map[i][j])
                res++;
        }
        else
        {
            if(!map[i][j])
                res--;
        }
    }
    return res;
}

void spfa()
{
    que.push(0);
    in[0]=1;
    dis[0]=getPd();
    int now,nxt,p;
    int ct;
    int pt=0;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        pt++;
        ct=count(now);
        if(ct>=mk&&ct<=mp)
        {
            if(dis[now]<ans)
            {
                ans=dis[now];
                anst=now;
            }
        }
        if(ct==mp) continue;
        for(int i=1;i<=N;i++)
        {
            if(!(now&(1<<(i-1))))
            {
                nxt=now|(1<<(i-1));
                if(in[nxt]) continue;
                p=getDis(now,i);
                if(dis[nxt]>dis[now]+p)
                {
                    dis[nxt]=dis[now]+p;
                    if(!in[nxt])
                    {
                        que.push(nxt);
                    }
                }
            }
        }
    }
    cout<<pt<<endl;
}

void init()
{
    for(int i=0;i<1<<(N+1);i++)
        dis[i]=inf;
    memset(map,0,sizeof(map));
    memset(in,0,sizeof(in));
}

void input()
{
    int now,c,kk;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&now,&c);
        for(int j=0;j<c;j++)
        {
            scanf("%d",&kk);
            map[now][kk]=1;
        }
    }
}

void work()
{
    ans=inf;
    if(N%2)
    {
        mk=N/2;
        mp=N/2+1;
    }
    else
    {
        mk=mp=N/2;
    }
    spfa();
    printf("%d\n",ans);
    int cnt;
    cnt=0;
    for(int i=0;i<N;i++)
        if(anst&(1<<i))
            cnt++;
    printf("%d",cnt);
    for(int i=0;i<N;i++)
        if(anst&(1<<i))
            printf(" %d",i+1);
    puts("");
    cnt=0;
    for(int i=0;i<N;i++)
        if(!(anst&(1<<i)))
            cnt++;
    printf("%d",cnt);
    for(int i=0;i<N;i++)
        if(!(anst&(1<<i)))
            printf(" %d",i+1);
    puts("");
}

int main()
{
    freopen("in.txt","r",stdin);
    bool start=0;
    while(~scanf("%d",&N))
    {
        if(start) puts("");
        start=1;
        init();
        input();
        work();
    }
    return 0;
}
