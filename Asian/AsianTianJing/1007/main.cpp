#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=100+10;
const int maxn2=15+5;
const int inf=0x3f3f3f3f;
int map[maxn][maxn];

int kmap[maxn2][maxn2];
int C[maxn2];
int D[maxn2];
int change[maxn2];
int kkk;
bool keyP[maxn];

int N,M,H;
int monny;

queue<int> que;
int dis[maxn];
bool in[maxn];
int cnt[maxn];
bool spfa(int from,int to)
{
    memset(cnt,0,sizeof(cnt));
    memset(in,0,sizeof(in));
    int nx;
    for(int i=0;i<=N;i++)
        dis[i]=inf;
    dis[from]=0;
    keyP[to]=0;
    que.push(from);
    while(!que.empty())
    {
        nx=que.front();
        que.pop();
        for(int i=1;i<=N;i++)
        {
            if(map[nx][i]!=-1&&!keyP[i])
            {
                if(dis[nx]+map[nx][i]<dis[i])
                {
                    dis[i]=dis[nx]+map[nx][i];
                    if(!in[i])
                    {
                        que.push(i);
                        in[i]=1;
                        cnt[i]++;
                        if(cnt[i]>N) {
                            while(!que.empty())que.pop();
                            return 0;
                        }
                    }
                }
            }
        }
        in[nx]=0;
    }
    keyP[to]=1;
    return 1;
}


void sd()
{
    for(int i=1;i<=H;i++)
        for(int j=i+1;j<=H;j++)
            if(spfa(change[i],change[j]))
                if(kmap[i][j]==-1||dis[change[j]]<kmap[i][j])
                    kmap[i][j]=kmap[j][i]=dis[change[j]];
    if(keyP[1])
    {
        for(int i=1;i<=H;i++)
            kmap[i][16]=kmap[i][1];
    }
    else
    {
        bool tmp[maxn2];
        memcpy(tmp,keyP,sizeof(tmp));
        memset(keyP,0,sizeof(keyP));
        spfa(1,0);
        memcpy(keyP,tmp,sizeof(tmp));
        for(int i=1;i<=H;i++)
            kmap[0][i]=kmap[i][0]=kmap[i][16]=dis[change[i]];
    }
    C[16]=D[16]=0;
    C[0]=D[0]=0;
}

int dis2[maxn2];
bool in2[maxn2];
int cnt2[maxn2];
bool spfa2(int from,int to)
{
    memset(cnt2,0,sizeof(cnt2));
    memset(in2,0,sizeof(in2));
    int nx;
    for(int i=0;i<=H;i++)
        dis2[i]=inf;
    dis2[from]=0;
    que.push(from);
    while(!que.empty())
    {
        nx=que.front();
        que.pop();
        for(int i=1;i<=16;i++)
        {
            if(map[nx][i]!=-1)
            {
                if(dis[nx]+map[nx][i]<dis[i])
                {
                    dis[i]=dis[nx]+map[nx][i];
                    if(!in[i])
                    {
                        que.push(i);
                        in[i]=1;
                        cnt[i]++;
                        if(cnt[i]>N) {
                            while(!que.empty())que.pop();
                            return 0;
                        }
                    }
                }
            }
        }
        in[nx]=0;
    }
    return 1;
}



bool vis[maxn2];
bool dfs(int now)
{
    if(now==16) return true;
    for(int i=0;i<=H;i++)
    {
        if(kmap[now][i]!=-1)
        {
            if(!vis[i])
            {
                if(monny>kmap[now][i]+D[i])
                {
                    monny+=C[i]-kmap[now][i]-D[i];
                    vis[i]=1;
                    if(dfs(i))return true;
                    vis[i]=0;
                    monny-=C[i]-kmap[now][i]-D[i];
                    //不打工过去？
                    if(C[i]<D[i])
                    {
                        monny+=-kmap[now][i];
                        if(dfs(i))return true;
                        monny-=kmap[now][i];
                    }
                }
            }
            else
            {
                if(monny>kmap[now][i])
                {
                    monny+=-kmap[now][i];
                    vis[i]=1;
                    if(dfs(i))return true;
                    vis[i]=0;
                    monny-=kmap[now][i];
                }
            }
        }
    }
    return false;
}

void init()
{
    memset(map,-1,sizeof(map));
    memset(kmap,-1,sizeof(kmap));
}


void input()
{
    scanf("%d%d%d",&N,&M,&monny);
    int f,t,v;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&f,&t,&v);
        map[f][t]=map[t][f]=v;
    }
    scanf("%d",&H);
    int c,d;
    kkk=0;
    for(int i=1;i<=H;i++)
    {
        scanf("%d%d%d",&v,&c,&d);
        if(v==1) kkk=i;
        change[i]=v;
        C[i]=c;
        D[i]=d;
        keyP[v]=1;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        input();
        sd();
        monny+=C[kkk]-D[kkk];
        vis[kkk]=1;
        if(dfs(kkk))printf("YES\n");
        else
        {
            if(C[kkk]<D[kkk]){
                C[16]=C[kkk];
                D[16]=D[kkk];
                if(dfs(kkk))printf("YES\n");
                else printf("NO\n");
            }
            else printf("NO\n");
        }
    }
    return 0;
}


