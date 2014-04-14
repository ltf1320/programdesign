#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=40000+100;
const int maxm=100000+100;
int X,Y,M;

int getS(char c)
{
    if(c<='9'&&c>='0')
        return c-'0';
    else return c-'A'+10;
}

struct EDGE
{
    int next,to;
    int from;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].from=f;
    edge[ent].next=box[f];
    box[f]=ent++;
}

int pa[maxn],pb[maxn];
int disa[maxn],disb[maxn];

bool bfs()
{
    memset(disa,0,sizeof(disa));
    memset(disb,0,sizeof(disb));
    bool flag=0;
    queue<int> que;
    for(int i=0; i<X; i++)
        if(pa[i]==-1)
            que.push(i);
    int now;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            if(!disb[edge[i].to])
            {
                disb[edge[i].to]=disa[now]+1;
                if(pb[edge[i].to]==-1) flag=1;
                else
                {
                    disa[pb[edge[i].to]]=disb[edge[i].to]+1;
                    que.push(pb[edge[i].to]);
                }
            }
        }
    }
    return flag;
}

bool dfs(int now)
{
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(disb[edge[i].to]==disa[now]+1)
        {
            disb[edge[i].to]=0;
            if(pb[edge[i].to]==-1||dfs(pb[edge[i].to]))
            {
                pb[edge[i].to]=now;
                pa[now]=edge[i].to;
                return 1;
            }
        }
    }
    return 0;
}



int Hopcroft_Karp()
{
    memset(pa,-1,sizeof(pa));
    memset(pb,-1,sizeof(pb));
    int res=0;
    while(bfs())
    {
        for(int i=0; i<X; i++)
            if(pa[i]==-1&&dfs(i))
                res++;
    }
    return res;
}

struct QLT
{
    EDGE edge[maxm*4];
    int box[maxn];
    int ent;
    void init()
    {
        memset(box,-1,sizeof(box));
        ent=0;
    }
    void add(int f,int t)
    {
        edge[ent].to=t;
        edge[ent].next=box[f];
        box[f]=ent++;
    }

    int dfn[maxn],low[maxn];
    int fl[maxn],fln;
    vector<int> fls[maxn];
    int stack[maxn],top;
    bool in[maxn];
    int ti;
    void tarjan(int now)
    {
        dfn[now]=low[now]=ti++;
        stack[++top]=now;
        in[now]=1;
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            if(!dfn[edge[i].to])
            {
                tarjan(edge[i].to);
                low[now]=min(low[now],low[edge[i].to]);
            }
            else if(in[edge[i].to])
                low[now]=min(low[now],dfn[edge[i].to]);
        }
        int nd;
        if(dfn[now]==low[now])
        {
            fls[fln].clear();
            while(top!=-1)
            {
                nd=stack[top];
                top--;
                fls[fln].push_back(nd);
                fl[nd]=fln;
                in[nd]=0;
                if(nd==now) break;
            }
            fln++;
        }
    }
    void initTarjan()
    {
        memset(dfn,0,sizeof(dfn));
        memset(in,0,sizeof(in));
        top=-1;
        fln=0;
    }

};

int ress[maxm];
int res;
void input()
{
    char tmp[10];
    int x,y;
    for(int i=0; i<M; i++)
    {
        scanf("%s",tmp);
        x=0;
        for(int j=0; j<3; j++)
        {
            x<<=5;
            x+=getS(tmp[j]);
        }
        y=0;
        for(int j=0; j<3; j++)
        {
            y<<=5;
            y+=getS(tmp[j+3]);
        }
        add(x,y);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
}
QLT ql;
void work()
{
    Hopcroft_Karp();
    ql.init();
    for(int i=0;i<X;i++)
    {
        for(int j=box[i];j!=-1;j=edge[j].next)
        {
            if(edge[j].to!=pa[i])
                ql.add(i+2,edge[j].to+X+2);
            else
                ql.add(edge[j].to+X+2,i+2);
        }
        if(pa[i]==-1)
            ql.add(0,i+2);
        else ql.add(i+2,0);
    }
    for(int i=0;i<Y;i++)
        if(pb[i]==-1)
            ql.add(i+2+X,1);
        else ql.add(1,i+2+X);
    ql.initTarjan();
    for(int i=0;i<X+Y+2;i++)
        if(!ql.dfn[i])
            ql.tarjan(i);
    res=0;
    for(int i=0;i<M;i++)
    {
        if(pa[edge[i].from]==edge[i].to) continue;
        if(ql.fl[edge[i].from+2]!=ql.fl[edge[i].to+2+X])
        {
            ress[res++]=i;
        }
    }
    printf("%d\n",res);
    for(int i=0;i<res;i++)
    {
        if(i) putchar(' ');
        printf("%d",ress[i]);
    }
    puts("");
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&X,&Y,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
