#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+10;
int N,M;
struct Node
{
    int l,r; //表示的线段范围
    int max;  //存的值
    int min;
};
Node tree[4*maxn];

void buildtree(int l,int r,int n)
{
    tree[n].r=r;
    tree[n].l=l;
    if(r==l)
    {
        scanf("%d",&tree[n].max);
        tree[n].min=tree[n].max;
        return;
    }
    int m=(l+r)>>1;
    buildtree(l,m,n<<1);
    buildtree(m+1,r,n<<1|1);
    tree[n].max=max(tree[n<<1].max,tree[n<<1|1].max);
    tree[n].min=min(tree[n<<1].min,tree[n<<1|1].min);
}
int ql,qr,H;
int query(int l,int r,int n)
{
    if(l>=ql&&r<=qr)
    {
        if(tree[n].max<=H)
        {
            return r-l+1;
        }
    }
    if(l==r) return 0;
    if(tree[n].min>H) return 0;
    int res=0;
    int m=(l+r)>>1;
    res+=query(l,m,n<<1);
    res+=query(m+1,r,n<<1|1);
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        scanf("%d%d",&N,&M);
        buildtree(1,N,1);
        printf("Case %d:\n",cas++);
        while(M--)
        {
            scanf("%d%d%d",&ql,&qr,&H);
            ql++;
            qr++;
            printf("%d\n",query(1,N,1));
        }
    }
    return 0;
}
