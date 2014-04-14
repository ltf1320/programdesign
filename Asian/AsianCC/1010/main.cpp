#include <cstdio>
#include <cstring>
#include <queue>


const int maxn=100;
const int MAXN=1000;

using namespace std;

struct Node
{
    int to,next;
    int from,last;
    int weight;
};

Node edge[MAXN];
int box[maxn];
int rebox[maxn];
int dis[maxn];
bool vis[maxn];
int treas[maxn];

const int Inf=0x3f3f3f3f;
struct FSO
{
    int from,dis;
    FSO(int from_,int dis_):from(from_),dis(dis_) {}
    bool operator<(const FSO &n)const {return dis>n.dis;}
};

int dijkstra(int from,int to)
{
    for(int i=0; i<maxn; ++i)
        dis[i]=Inf;
    memset(vis,0,sizeof(vis));
    priority_queue<FSO> que;
    que.push(FSO(from,0));
    dis[from]=0;
    int mx,now;
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
        for(int j=box[mx]; j; j=edge[j].next)
        {
            now=edge[j].to;
            if(dis[now]>dis[mx]+1)
            {
                dis[now]=dis[mx]+1;
                que.push(FSO(edge[j].to,dis[now]));
            }
        }
        vis[mx]=1;
    }
    if(dis[to]!=Inf)
        return dis[to];
    else return -1;
}


int ent=1;
void add(int from,int to)
{
    edge[ent].from=from;
    edge[ent].to=to;
    edge[ent].next=box[from];
    box[from]=ent++;
}


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

struct ASO
{
    int from,dis,f,tre;
    ASO(int from_,int dis_,int f_,int tre_):from(from_),dis(dis_),f(f_),tre(tre_){}
    bool operator<(const ASO &a)const
    {
        return f>a.f;
    }
};


int Astar(int from,int to,int k)
{
    int mx,now,ndis,ntre;
    int c=0;
    if(from==to)
    c--;
//这个判断有争议，用不用都可以试下
    priority_queue<ASO> que;
    que.push(ASO(from,0,dis[from],treas[from]));
    while(1)
    {
        if(que.empty()) break;
        mx=que.top().from;
        ndis=que.top().dis;
        nter=
        que.pop();
        if(mx==to)
        {
            c++;
            printf("%d : %d\n",c,ndis);
        }
        if(c==k)
            return ndis;
        for(int i=box[mx]; i; i=edge[i].next)
        {
            now=edge[i].to;
            que.push(ASO(now,ndis+edge[i].weight,ndis+edge[i].weight+dis[now],));
        }
    }
    return -1;
}

void init()
{
    res=-1;
    ent=0;
    memset(box,-1,sizeof(box));
    memset(vis,0,sizeof(vis));
    memset(maxt,0,sizeof(maxt));
}

int main()
{
    freopen("in.txt","r",stdin);
    int f,t,s;
    while(~scanf("%d%d",&N,&T))
    {
        init();
        for(int i=0; i<N-1; i++)
        {
            scanf("%d%d%d",&f,&t,&s);
            add(f,t,s);
            add(t,f,s);
        }
        for(int i=1; i<=N; i++)
            scanf("%d",&treas[i]);
        if(dijkstra(1,N)==-1)
            printf("Human beings die in pursuit of wealth, and birds die in pursuit of food!\n");
        else
        {

        }
    }
    return 0;
}
