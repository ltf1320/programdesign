#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
const int maxe=100000;
const int inf=0x3f3f3f3f;

int N,M,E;

struct COW
{
    int t1,t2,s;
    bool operator<(const COW &a)const
    {
        return t2<a.t2;
    }
};
COW cow[maxn];
int dp[maxe];
struct TNode
{
    int min;
    int l,r;
};
TNode Tree[4*maxe];

void buildTree(int l,int r,int n)
{
    Tree[n].min=inf;
    Tree[n].l=l;
    Tree[n].r=r;
    if(l==r) return;
    int m=(l+r)>>1;
    buildTree(l,m,n<<1);
    buildTree(m+1,r,n<<1|1);
}

void change(int n,int t,int s)
{
    if(s<Tree[n].min) Tree[n].min=s;
    if(Tree[n].l==Tree[n].r) return;
    int m=(Tree[n].l+Tree[n].r)/2;
    if(t<=m) change(n<<1,t,s);
    else change(n<<1|1,t,s);
}

int input()
{
    if(scanf("%d%d%d",&N,&M,&E)==EOF) return EOF;
    M++;E++;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d",&cow[i].t1,&cow[i].t2,&cow[i].s);
        cow[i].t1++;
        cow[i].t2++;
    }
    return 0;
}

int query(int n,int l,int r)
{
    if(Tree[n].l==l&&Tree[n].r==r) return Tree[n].min;
    int m=(Tree[n].l+Tree[n].r)/2;
    if(r<=m) return query(n<<1,l,r);
    else if(l>m) return query(n<<1|1,l,r);
    else return min(query(n<<1,l,m),query(n<<1|1,m+1,r));
}

int work()
{
    int tmp;
    for(int i=0;i<N;i++)
    {
        tmp=query(1,cow[i].t1-1,cow[i].t2)+cow[i].s;
        if(dp[cow[i].t2]>tmp)
        {
            dp[cow[i].t2]=tmp;
            change(1,cow[i].t2,tmp);
        }

    }
    if(dp[E]!=inf) return dp[E];
    else return -1;
}

int main()
{
    freopen("in.txt","r",stdin);
    input();
    buildTree(M-1,E,1);
    sort(cow,cow+N);
    for(int i=0;i<=E;i++) dp[i]=inf;
    dp[M-1]=0;
    change(1,M-1,0);
    printf("%d\n",work());
    return 0;
}
