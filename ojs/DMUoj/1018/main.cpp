#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int maxn=1000+100;
const int Inf=0x3f3f3f3f;

int n,m,ti,k;
int minh,maxh;
int happinessarr[maxn];

struct EDGE
{
    int to,next,last,from,weight;
    void reset()
    {
        to=next=from=weight=last=-1;
    }
};
EDGE edge[maxn*2];
int box[maxn];
int rebox[maxn];
int ent;
void add(int from,int to,int weight)
{
    edge[ent].to=to;
    edge[ent].from=from;
    edge[ent].next=box[from];
    edge[ent].last=rebox[to];
    edge[ent].weight=weight;
    box[from]=ent;
    rebox[to]=ent++;
}

void init()
{
    ent=0;
    for(int i=0; i<maxn; ++i)
        edge[i].reset();
    memset(box,-1,sizeof(box));
    memset(rebox,-1,sizeof(rebox));
    memset(happinessarr,0,sizeof(happinessarr));
}

struct FSO
{
    FSO(int from_,int dis_):from(from_),dis(dis_) {}
    bool operator<(const FSO &a)const
    {
        return dis>a.dis;
    }
    int from,dis;
};

int dis[maxn];
bool vis[maxn];
int dijkstra(int from,int to)  //¶Ô·´Í¼Çódijkstra
{
    int mx,now;
    for(int i=0; i<maxn; ++i)
        dis[i]=Inf;
    memset(vis,0,sizeof(vis));
    dis[from]=0;
    priority_queue<FSO> que;
    que.push(FSO(from,0));
    while(1)
    {
        if(que.empty()) break;
        mx=que.top().from;
        if(vis[mx])
        {
            que.pop();
            continue;
        }
        que.pop();
        for(int i=rebox[mx]; i!=-1; i=edge[i].last)
        {
            now=edge[i].from;
            if(dis[now]>dis[mx]+edge[i].weight)
            {
                dis[now]=dis[mx]+edge[i].weight;
                que.push(FSO(now,dis[now]));
            }
        }
        vis[mx]=1;
    }
    return dis[to];
}

struct ASO
{
    int from,ndis,f,hap;
    bool vis[maxn];
    ASO(int from_,int dis_,int f_):from(from_),ndis(dis_),f(f_){memset(vis,0,sizeof(vis));hap=0;}
    ASO(const ASO &from,int addedge)
    {
        memcpy(vis,from.vis,sizeof(vis));
        this->from=edge[addedge].to;
        vis[edge[addedge].to]=1;
        ndis=from.ndis+edge[addedge].weight;
        f=ndis+dis[edge[addedge].to];
        hap=from.hap+happinessarr[edge[addedge].to];
    }
    ASO(){}
    bool operator<(const ASO &a)const
    {
        return f>a.f;
    }
};


int Astar(int from,int to)
{
    int ndis;
    int mh=-1;
    priority_queue<ASO> que;
    ASO tmp;
    que.push(ASO(from,0,dis[from]));
    while(1)
    {
        if(que.empty()) break;
        ndis=que.top().ndis;
        tmp=que.top();
        que.pop();
        if(tmp.from==to)
        {
 //           cout<<"dis:"<<ndis<<endl;
 //           cout<<"maxh:"<<maxh<<"   minh:"<<minh<<"   mh:"<<tmp.hap<<endl;
            if(ndis>ti) return mh;
            if(tmp.hap<=maxh && tmp.hap>=minh)
                mh=max(mh,tmp.hap);
            continue;
        }
        for(int i=box[tmp.from]; i!=-1; i=edge[i].next)
        {
            if(!tmp.vis[edge[i].to])
                que.push(ASO(tmp,i));
        }
    }
    return mh;
}


int main()
{
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int a,b,c;
    int p,h;
    int res;
    while(~scanf("%d%d%d%d",&n,&m,&k,&ti))
    {
        init();
        scanf("%d%d",&minh,&maxh);
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(b==1)
            {
                add(a,101,c);
                add(101,a,c);
            }
            else if(a==1)
            {
                add(b,101,c);
                add(101,b,c);
            }
            add(a,b,c);
            add(b,a,c);
        }
        for(int i=0;i<k;++i)
        {
            scanf("%d%d",&p,&h);
            happinessarr[p]+=h;
        }
        int text=dijkstra(101,1);
        if(text==Inf)
        {
            printf("No way\n");
        }
        else
        {
            res=Astar(1,101);
            if(res==-1) printf("Oh!NO!\n");
            else printf("%d\n",res);
        }
    }
    return 0;
}
