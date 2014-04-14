#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=50000+100;
const double err=1E-7;
int N;
struct Node
{
    int id;
    int t,p;
    double g;
    bool operator<(const Node &a)const
    {
        return g<a.g;
    }
};
Node nds[maxn];
int ans[maxn];
int ansn;
double pans[maxn];
int d;

bool judge(double m)
{
    for(int i=1;i<=N;i++)
        nds[i].g=nds[i].t-nds[i].p*m;
    sort(nds+1,nds+1+N);
    double sum=0;
    for(int i=d+1;i<=N;i++)
        sum+=nds[i].g;
    return sum>0;
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&nds[i].t,&nds[i].p);
        nds[i].g=1.0*nds[i].t/nds[i].p;
    }
    sort(nds+1,nds+N+1);
    int sumt=0,sump=0;
    for(int i=N;i>0;i--)
    {
        sumt+=nds[i].t;
        sump+=nds[i].p;
        pans[i-1]=1.0*sumt/sump;
    }
    for(d=1;d<N;d++)
    {
        /*
        double l=0,r=40000;
        double m;
        while(r-l>err)
        {
            m=(l+r)/2;
            if(judge(m))
                l=m;
            else r=m;
        }
        if(m>pans[d]+err)
            ans[ansn++]=d;
            */
        if(judge(pans[d]+err))
            ans[ansn++]=d;
    }
    printf("%d\n",ansn);
    for(int i=0;i<ansn;i++)
        printf("%d\n",ans[i]);
}
