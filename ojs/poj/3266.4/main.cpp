#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=50000+100;
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
long long sumt[maxn],sump[maxn];

int ans[maxn];
int ansn;

int q[maxn];
int head,tail;
int best[maxn];

bool judge(int i,const Node &a,const Node &b)//aÓÅÓÚb
{
    return (a.t-b.t)*sump[i]>(a.p-b.p)*sumt[i];
}

bool judge3(const Node &a,const Node &b,const Node &c)
{
    return ((b.p-a.p)*(c.t-b.t)>(b.t-a.t)*(c.p-b.p));
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
        while(tail>head&&nds[q[tail-1]].p>=nds[i].p)
            tail--;
        while(tail>head+1&&judge3(nds[q[tail-2]],nds[q[tail-1]],nds[i]))
            tail--;
        q[tail++]=i;
        while(tail>head+1&&judge(i+1,nds[q[tail-2]],nds[q[tail-1]]))
            tail--;
        best[i]=q[tail-1];
    }
    head=tail=0;
    for(int i=N-1;i>0;i--)
    {
        while(tail>head&&(nds[q[tail-1]].t<=nds[i].t||nds[q[tail-1]].p<=nds[i].p))
            tail--;
        while(tail>head+1&&judge3(nds[q[tail-2]],nds[q[tail-1]],nds[i]))
            tail--;
        q[tail++]=i;
        while(tail>head+1&&judge(i,nds[q[head]],nds[q[head+1]]))
            head++;
 //       cout<<q[head]<<endl;
        if(judge(i,nds[best[i-1]],nds[q[head]]))
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
