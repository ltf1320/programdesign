#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=500000+100;
int N;

struct Node
{
    int t,p;
    double tp;
    bool operator<(const Node &a)const
    {
        return tp<a.tp;
    }
};
Node nds[maxn];
int sumt[maxn],sump[maxn];

int ans[maxn];
int ansn;

int q[maxn];
int head,tail;
int wast[maxn];

bool judge(int i,const Node &a,const Node &b)
{
    return (a.t-b.t)*sump[i+1]<(a.p-b.p)*sumt[i+1];
}

void work()
{
    sort(nds,nds+N);
    for(int i=N-1;i>=0;i--)
    {
        sumt[i]=sumt[i+1]+nds[i].t;
        sump[i]=sump[i+1]+nds[i].p;
    }
    head=0,tail=0;
    for(int i=0;i<N;i++)
    {
        while(tail>head&&judge(i,nds[q[head]],nds[q[head+1]]))
            head++;
        q[++tail]=i;
        while(tail>head&&judge(i,nds[tail-1],nds[q[tail]]))
            tail--;
        wast[i]=q[head];
    }
    head=tail=0;
    for(int i=N-1;i>=0;i--)
    {
        while(tail>head&&judge(i,nds[q[head]],nds[q[head+1]]))
            head++;
        q[++tail]=i;
        while(tail>head&&judge(i,nds[tail-1],nds[q[tail]]))
            tail--;
        if(judge(i,nds[q[tail]],nds[wast[i]]))
            ans[ansn++]=i;
    }
    printf("%d\n",ansn);
    for(int i=ansn-1;i>=0;i--)
        printf("%d\n",ans[i]);
}

void input()
{
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&nds[i].t,&nds[i].p);
        nds[i].tp=1.0*nds[i].t/nds[i].p;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    input();
    work();
    return 0;
}
