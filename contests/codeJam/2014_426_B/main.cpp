#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100+10;
const int inf=0x3f3f3f3f;
int N;

int du[maxn];
struct EDGE
{
    int to,next;
};
EDGE edge[maxn*10];
int box[maxn];
int ent;

void _add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t)
{
    du[f]++;du[t]++;
    _add(f,t);
    _add(t,f);
}

int check(int now,int from)
{
    int tmp;
    int m1=-inf,m2=-inf;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(from!=edge[i].to)
        {
            tmp=check(edge[i].to,now);
            if(tmp>m1)
                m1=tmp;
            else if(tmp>m2)
                m2=tmp;
        }
    }
    return max(1,m1+m2+1);
}

int work()
{
    int res=1;
    for(int i=1;i<=N;i++)
    {
        res=max(res,check(i,-1));
    }
    return N-res;
}

void input()
{
    scanf("%d",&N);
    int f,t;
    for(int i=1;i<N;i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
    memset(du,0,sizeof(du));
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        init();
        input();
        printf("Case #%d: ",cas);
        printf("%d\n",work());
    }
    return 0;
}
