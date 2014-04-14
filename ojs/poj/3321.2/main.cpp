#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=200000+100;
int N,M;
bool a[maxn];
int s[maxn];

struct EDGE
{
    int next,to;
};
EDGE edge[maxn];
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
    _add(f,t);
    _add(t,f);
}


int lowbit(int a)
{
    return a&(-a);
}

int sum(int end)
{
    int res=0;
    for(;end>0;end-=lowbit(end))
        res+=s[end];
    return res;
}

void Add(int n,int a)
{
    for(;n<=2*N;n+=lowbit(n))
        s[n]+=a;
}


int first[maxn],last[maxn];
int code;
void dfs(int now,int from)
{
    first[now]=code++;
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from) continue;
        dfs(edge[i].to,now);
    }
    last[now]=code++;
}

int main()
{
    freopen("in.txt","r",stdin);
    memset(box,-1,sizeof(box));
    memset(a,1,sizeof(a));
    code=1;
    int f,t;
    char ch;
    scanf("%d",&N);
    for(int i=0;i<N-1;i++)
    {
        scanf("%d%d",&f,&t);
        add(f,t);
    }
    dfs(1,-1);

    for(int i=1;i<=N;i++)
        Add(first[i],1);
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        getchar();
        scanf("%c%d",&ch,&f);
        if(ch=='C')
        {
            if(a[f])
            {
                Add(first[f],-1);
                a[f]=0;
            }
            else
            {
                Add(first[f],1);
                a[f]=1;
            }
        }
        else
        {
            printf("%d\n",sum(last[f])-sum(first[f]-1));
        }
    }
}
