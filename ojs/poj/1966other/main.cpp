#include<stdio.h>
#include<string.h>
#include<queue>
const int INF=1000000;
using namespace std;
int dis[200],gap[200],arc[200],first[200],next[1000],vv[1000],pre[200],low,cap[1000],f[1000];
int sap(int s,int t,int n)
{
    int q[500],i,j,mindis,ans=0,front=0,rear=1,u,v,e;
    bool found,vis[500];
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    memset(vis,0,sizeof(vis));
    memset(arc,0,sizeof(arc));
    q[0]=t;vis[t]=true;dis[t]=0;gap[0]=1;
    while(front<rear)
    {
        u=q[front++];e=first[u];

        while(e)
        {
            v=vv[e];
            if(!vis[v])
            {
                dis[v]=dis[u]+1;
                vis[v]=true;
                q[rear++]=v;
                gap[dis[v]]++;
                arc[v]=first[v];
            }
            e=next[e];
        }
    }
    u=s;low=INF;pre[s]=s;//gap[s]=n;
    while(dis[s]<n)
    {
        found=false;
        for(int &e=arc[u];e;e=next[e])if(dis[vv[e]]==dis[u]-1&&cap[e]>f[e])
        {
            found=true;v=vv[e];
            low=low<cap[e]-f[e]?low:cap[e]-f[e];
            pre[v]=u;u=v;

            if(u==t)
            {
                while(u-s)
                {
                    u=pre[u];
                    f[arc[u]]+=low;
                    f[arc[u]^1]-=low;
                }
                ans+=low;low=INF;
            }
            break;
        }
        if(found)
            continue;
        mindis=n;
        for(e=first[u];e;e=next[e])
            if(mindis>dis[vv[e]]&&cap[e]>f[e])
            {
                mindis=dis[vv[j=e]];
                arc[u]=e;
            };
        gap[dis[u]]--;
        if(gap[dis[u]]==0)
            return ans;
        dis[u]=mindis+1;
        gap[dis[u]]++;
        u=pre[u];
    }
    return ans;
}
bool BFS(int N)
{
    int i,e,u,v,cnt=1;
    queue<int>q;
    bool vis[200]={0};
    q.push(0);
    while(!q.empty())
    {
        u=q.front();q.pop();
        e=first[u];
        while(e)
        {
            v=vv[e];
            if(!vis[v])
            {
                q.push(v);
                vis[v]=true;
                cnt++;
            }
            e=next[e];
        }
    }
    if(cnt<N)
        return false;
    return true;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int M,N,u,v,i,j,e=2,ans,t;
    char s[20];
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        e=2;
        memset(first,0,sizeof(first));
        memset(f,0,sizeof(f));
        for(i=0;i<M;i++)
        {
            scanf("%s",s);
            for(u=0,j=1;s[j]-',';j++)
                u=u*10+s[j]-'0';
            for(v=0,j++;s[j]-')';j++)
                v=v*10+s[j]-'0';
            next[e]=first[u+N];
            first[u+N]=e;
            cap[e]=INF;vv[e++]=v;
            next[e]=first[v];
            first[v]=e;
            cap[e]=0;vv[e++]=u+N;
            next[e]=first[v+N];
            first[v+N]=e;
            cap[e]=INF;vv[e++]=u;
            next[e]=first[u];
            first[u]=e;
            cap[e]=0;vv[e++]=v+N;
        }
        for(i=0;i<N;i++)
        {
            next[e]=first[i];
            first[i]=e;
            cap[e]=1;vv[e++]=i+N;
            next[e]=first[i+N];
            first[i+N]=e;
            cap[e]=0;vv[e++]=i;
        }
        if(N==0||!BFS(N))
        {
            printf("0\n");
            continue;
        }
        for(j=0,ans=INF;j<N;j++)
        {
            for(i=0;i<N;i++)
            {
                if(i==j)
                    continue;
                memset(f,0,sizeof(f));
                t=sap(j+N,i,N*2);
                ans=ans<t?ans:t;
            }
        }
        if(ans>N)
            ans=N;
        printf("%d\n",ans);
    }
}
