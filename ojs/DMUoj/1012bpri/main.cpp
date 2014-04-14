#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int maxn=100000+100;
const int maxn2=1000+100;
const int Inf=maxn;


struct EDGE
{
    int to,next,last,from,weight;
    void reset()
    {
        to=next=from=weight=last=0;
    }
};
EDGE edge[maxn];
int box[maxn2];
int rebox[maxn2];
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
    for(int i=0; i<maxn; ++i)
        edge[i].reset();
    memset(box,0,sizeof(box));
    memset(rebox,0,sizeof(rebox));
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

int dis[maxn2];
bool vis[maxn2];
int dijkstra(int from,int to)  //对反图求dijkstra
{
    int mx,now;
    for(int i=0; i<maxn2; ++i)
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
        for(int i=rebox[mx]; i; i=edge[i].last)
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
    int from,dis,f;
    vector<int> luj;
    ASO(int from_,int dis_,int f_,vector<int> l):from(from_),dis(dis_),f(f_),luj(l){}
    bool operator<(const ASO &a)const
    {
        return f>a.f;
    }
};


int Astar(int from,int to,int k)
{
    int mx,now,ndis;
    int c=0;
    priority_queue<ASO> que;
    vector<int> tem;
    tem.push_back(from);
    que.push(ASO(from,0,dis[from],tem));
    while(1)
    {
        if(que.empty()) break;
        mx=que.top().from;
        ndis=que.top().dis;
        tem=que.top().luj;
        que.pop();
        if(mx==to)
        {
            c++;
            printf("%d : %d\n",c,ndis);
            printf("lujing:");
            for(vector<int>::iterator iter=tem.begin();iter!=tem.end();++iter)
                cout<<*iter<<" ";
            cout<<endl;
        }
        if(c==k)
            return ndis;
        tem.push_back(1);
        for(int i=box[mx]; i; i=edge[i].next)
        {
            now=edge[i].to;
            tem.pop_back();
            tem.push_back(now);
            que.push(ASO(now,ndis+edge[i].weight,ndis+edge[i].weight+dis[now],tem));
        }
    }
    return -1;
}


int main()
{
    freopen("in.txt","r",stdin);
    int n,m,s,t,k;
    int res;
    while(scanf ("%d%d",&n,&m)!=EOF)
    {
        init();
        ent=1;
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d%d",&s,&t,&k); //临时用来存一下
            add(s,t,k);
        }
        scanf("%d%d%d",&s,&t,&k);
        res=dijkstra(t,s);
        if(k!=1)
            res=Astar(s,t,k);
        printf("%d\n",res);
    }
    return 0;
}
