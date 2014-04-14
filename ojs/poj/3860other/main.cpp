#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>

typedef double Frac;

const int N=500+10;
const int S=50+10;
const char *INCONSISTENT="INCONSISTENT";
const char *UNAVAILABLE="UNAVAILABLE";
const char *EQUAL="==";
const char *SEQ="<=";
const char *LEQ=">=";
const Frac EPS=1e-8;
const Frac INF=1e100;

typedef std::pair<Frac,std::pair<int,int> > Edg;

int n,nVex;
Edg edg[N];
Frac dist[3*N];
std::map<std::string,int> fruitID;

Edg readEdg();
Frac make_frac(int a,int b);//(a/b)
bool bellman_ford(int s,int n);
Frac inverse(Frac frac);
bool relax(Frac d[]);
int dcmp(long double x);

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while (scanf("%d",&n),n)
    {
        nVex=0;
        fruitID.clear();
        for (int i=0;i<n;++i)
            edg[i]=readEdg();
        Edg query=readEdg();
        for (int i=0;i<nVex;++i)
            edg[n+i]=std::make_pair(make_frac(1,1),std::make_pair(nVex,i));
        n+=nVex;
        if (bellman_ford(nVex,nVex+1))
        {
            n-=nVex;
            int u=query.second.first,v=query.second.second;
            Frac w=query.first;
            bellman_ford(u,nVex);
            bool seq=dcmp(dist[v]-w)<=0;
            bellman_ford(v,nVex);
            bool leq=dcmp(dist[u]-inverse(w))<=0;
            if (seq&&leq)
                puts(EQUAL);
            else
                if (seq)
                    puts(SEQ);
                else
                    if (leq)
                        puts(LEQ);
                    else
                        puts(UNAVAILABLE);
        }
        else
            puts(INCONSISTENT);
    }
    return 0;
}

Edg readEdg()
{
    int a,b,u,v;
    char x[S],y[S];
    scanf("%d%s%d%s",&a,x,&b,y);
    if (!fruitID.count(x))
        u=fruitID[x]=nVex++;
    else
        u=fruitID[x];
    if (!fruitID.count(y))
        v=fruitID[y]=nVex++;
    else
        v=fruitID[y];
    return std::make_pair(make_frac(b,a),std::make_pair(u,v));
}

Frac make_frac(int a,int b)
{
    return log(a/(long double)b);
}

bool bellman_ford(int s,int n)
{
    for (int i=0;i<n;++i)
        dist[i]=INF;
    dist[s]=make_frac(1,1);
    for (int k=0;k<n-1;++k)
        relax(dist);
    return !relax(dist);
}

Frac inverse(Frac frac)
{
    return -frac;
}

bool relax(Frac d[])
{
    bool ans=false;
    for (int i=0;i<n;++i)
    {
        int u=edg[i].second.first,v=edg[i].second.second;
        Frac w=edg[i].first;
        if (d[u]<INF&&dcmp(d[u]+w-d[v])<0)
        {
            d[v]=d[u]+w;
            ans=true;
        }
    }
    return ans;
}

int dcmp(long double x)
{
    if (x<=-EPS)
        return -1;
    if (x>=EPS)
        return 1;
    return 0;
}
