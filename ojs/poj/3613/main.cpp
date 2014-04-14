#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=100+10;
const int maxi=1000+10;
const int inf=0x3f3f3f3f;
int N,T,S,E;
int mp[maxi];
int kn;

struct EDGE
{
    int next,to;
    int l;
};
EDGE edge[maxn*2];
int box[maxi];
int ent;

void add(int f,int t,int l)
{
    edge[ent].to=t;
    edge[ent].l=l;
    edge[ent].next=box[f];
    box[f]=ent++;
}

struct Mat
{
    int dis[maxn][maxn];
    Mat operator*(const Mat &a)
    {
        Mat res;
        for(int i=0; i<kn; i++)
            for(int j=0; j<kn; j++)
            {
                res.dis[i][j]=inf;
                for(int k=0; k<kn; k++)
                {
                    res.dis[i][j]=min(res.dis[i][j],dis[i][k]+a.dis[k][j]);
                }
            }
        return res;
    }
    Mat operator^(int n)
    {
        Mat res,now=*this;
        for(int i=1; i<kn; i++)
            for(int j=0;j<kn;j++)
                res.dis[i][j]=inf;
        for(int i=0;i<kn;i++)
            res.dis[0][i]=dis[0][i];
        n--;
//        res.print();
        while(n)
        {
            if(n&1)
            {
                res=res*now;
//                res.print();
            }
            n>>=1;
            now=now*now;
//            now.print();
        }
        return res;
    }
    void print()
    {
        for(int i=0;i<kn;i++)
        {
            for(int j=0;j<kn;j++)
                printf("%d ",dis[i][j]);
            puts("");
        }
        puts("");
    }
};

void dfs(int now)
{
    if(mp[now]==-1)
    {
        mp[now]=kn++;
        for(int i=box[now]; i!=-1; i=edge[i].next)
        {
            dfs(edge[i].to);
        }
    }
}

void work()
{
    kn=0;
    memset(mp,-1,sizeof(mp));
    dfs(S);
    Mat sb;
    for(int i=0; i<kn; i++)
        for(int j=0; j<kn; j++)
            sb.dis[i][j]=inf;
    for(int i=1; i<=1000; i++)
    {
        if(mp[i]!=-1)
            for(int j=box[i]; j!=-1; j=edge[j].next)
            {
                if(mp[edge[j].to]!=-1)
                {
                    sb.dis[mp[i]][mp[edge[j].to]]=edge[j].l;
                }
            }
    }
    sb=sb^N;
//    sb.print();
    if(sb.dis[mp[S]][mp[E]]>=inf)
        printf("-1\n");
    else printf("%d\n",sb.dis[mp[S]][mp[E]]);
}

void input()
{
    int f,t,l;
    for(int i=0;i<T;i++)
    {
        scanf("%d%d%d",&l,&f,&t);
        add(f,t,l);
        add(t,f,l);
    }
}

void init()
{
    memset(box,-1,sizeof(box));
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d%d%d",&N,&T,&S,&E);
    init();
    input();
    work();
    return 0;
}
