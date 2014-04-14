#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>

#define MK(a,b) make_pair(a,b)

using namespace std;
const int maxn=10000+100;
int N;

const int dx[]= {0,0,1,-1};
const int dy[]= {1,-1,0,0};

map<pair<int,int>,int> mp;
int fa[maxn];
int type[maxn]; //0 for black,1 for white
set<pair<int,int> > hed[maxn];
set<pair<int,int> > has[maxn];

int find(int a)
{
    if(fa[a]==a)
        return a;
    fa[a]=find(fa[a]);
    return fa[a];
}

void Uni(int a,int b)
{
    a=find(a);
    b=find(b);
    fa[b]=a;
    for(set<pair<int,int> >::iterator iter=has[b].begin(); iter!=has[b].end(); iter++)
    {
        has[a].insert(*iter);
    }
    has[b].clear();
    for(set<pair<int,int> >::iterator iter=hed[b].begin(); iter!=hed[b].end(); iter++)
    {
        hed[a].insert(*iter);
    }
    hed[b].clear();
}

void del(int a)
{
    int x,y;
    int nf;
    for(set<pair<int,int> >::iterator iter=has[a].begin();iter!=has[a].end();iter++)
    {
        x=iter->first;
        y=iter->second;
        mp.erase(MK(x,y));
        for(int j=0; j<4; j++)
        {
            int nx=x+dx[j],ny=y+dy[j];
            if(mp.count(MK(nx,ny)))
            {
                nf=find(mp[MK(nx,ny)]);
                if(nf!=a)
                {
                    hed[nf].insert(MK(x,y));
                }
            }
        }
    }
    has[a].clear();
}

void AC()
{
    int nt=0,nf;
    int x,y;
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d",&x,&y);
        mp[MK(x,y)]=i;
        type[i]=nt;
        has[i].insert(MK(x,y));
        for(int j=0; j<4; j++) //get the edge of point i
        {
            int nx=x+dx[j],ny=y+dy[j];
            if(nx&&ny)
                if(!mp.count(MK(nx,ny)))
                    hed[i].insert(MK(nx,ny));
        }
        for(int j=0; j<4; j++)
        {
            int nx=x+dx[j],ny=y+dy[j];
            if(nx&&ny)
            {
                if(mp.count(MK(nx,ny)))
                {
                    nf=find(mp[MK(nx,ny)]);
                    hed[nf].erase(MK(x,y));
                    if(type[nf]==nt)
                        Uni(i,nf);
                    else
                        if(hed[nf].size()==0)
                            del(nf);
                }
            }
        }
        if(hed[i].size()==0)
            del(i);
        nt^=1;
    }
    int Nb(0),Nw(0);
    for(int i=1;i<=N;i++)
    {
        if(type[i]==0)
            Nb+=has[i].size();
        else
            Nw+=has[i].size();
    }
    printf("%d %d\n",Nb,Nw);
}


void init()
{
    for(int i=0; i<=N; i++)
    {
        fa[i]=i;
        has[i].clear();
        hed[i].clear();
    }
    mp.clear();

}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        init();
//        input();
        AC();
    }
    return 0;
}
