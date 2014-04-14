#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=100000+100;


struct Node
{
    int l,r;
    int color;
};

Node tree[4*maxn];

void buildtree(int l,int r,int n=1)
{
    int m=(l+r)>>1;
    tree[n].l=l;
    tree[n].r=r;
    tree[n].color=1;
    if(l==r) return;
    buildtree(l,m,n<<1);
    buildtree(m+1,r,n<<1|1);
    return;
}


void change(int l,int r,int col,int n)
{
    if(tree[n].l>=l && tree[n].r<=r )
    {
        tree[n].color=col;
        return;
    }
    int m=(tree[n].l+tree[n].r)>>1;
    if(r<=m)
        change(l,r,col,n<<1);
    else if(l<=m && r>m)
    {
        change(l,m,col,n<<1);
        change(m+1,r,col,n<<1|1);
    }
    else if(l>m)
        change(l,r,col,n<<1|1);
    tree[n].color=tree[n<<1].color|tree[n<<1|1].color;
    return ;
}

int query(int a,int b,int n)
{
    int col=0;
    if(tree[n].l>=a && tree[n].r<=b)
    {
        return tree[n].color;
    }
    int m=(tree[n].l+tree[n].r)>>1;
    if(b<=m)
        col|=query(a,b,n<<1);
    else if(a<=m && b>m)
    {
        col|=query(a,m,n<<1);
        col|=query(m+1,b,n<<1|1);
    }
    else if(a>m)
        col|=query(a,b,n<<1|1);
    return col;
}

int toBin(int n)
{
    int res=1<<n;
    return res;
}

int count(int n)
{
    int res=0;
    while(n)
    {
        if(n&1)
            res++;
        n>>=1;
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int L,T,O;
    char ch[2];
    int left,right,col;
    scanf("%d%d%d",&L,&T,&O);
    buildtree(1,L);
    for(int i=0; i<O; ++i)
    {
//        cout<<"ka:"<<i<<endl;
        scanf("%s",ch);
        if(ch[0]=='C')
        {
            scanf("%d%d%d",&left,&right,&col);
            col=toBin(col);
            if(left>right)
            {
                int tem=right;
                right=left;
                left=tem;
            }
            change(left,right,col,1);
        }
        else
        {
            scanf("%d%d",&left,&right);
            if(left>right)
            {
                int tem=right;
                right=left;
                left=tem;
            }
            int res=query(left,right,1);
            res=count(res);
            printf("%d\n",res);
        }
    }
    return 0;
}
