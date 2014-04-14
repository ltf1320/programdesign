/*这道TLE or WA了n遍的题...最后总算是过了
就是一个线段树的问题，一个重点就是用一个int型的数储存color的种类
有两个方法，第一个方法比较好理解，第二个方法比较强大，但有一步比较难理解
区别是
第一个方法有lazy标记，修改和查询时遇到lazy标记就先下放，一个标准的线段树
第二个方法舍去了lazy标记，用color中是否只有一个颜色来作为lazy的标记
（一个很强大的想法：如果一段线段被lazy了，它肯定只有一种颜色（肯定是都被修改为一种颜色）
而就算是没有被lazy,因为子树中的颜色肯定也只有那一种，所以下放不会导致错误）

第一种方法310ms过的，第二种250ms过的
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
struct Node
{
    int l,r;
    int color;
    bool lazy;
};
Node tree[4*maxn];

void buildtree(int l,int r,int n)
{
    tree[n].r=r;
    tree[n].l=l;
    tree[n].color=1;
    tree[n].lazy=0;
    if(r==l)
    {
        return;
    }
    int m=(l+r)>>1;
    buildtree(l,m,n<<1);
    buildtree(m+1,r,n<<1|1);
}
/*
bool Onecolor(int col)
{
    if((col&(col-1))==0) return 1;
    else return 0;
}
*/
void pushDown(int n)
{
    if(tree[n].lazy)
    {
        tree[n<<1].color=tree[n<<1|1].color=tree[n].color;
        tree[n].lazy=0;
        tree[n<<1].lazy=tree[n<<1|1].lazy=1;
    }
}


void pushUp(int n)
{
    tree[n].color=tree[n<<1].color|tree[n<<1|1].color;
}
void change(int l,int r,int col,int n)
{
    if(tree[n].l==l && tree[n].r==r)
    {
        tree[n].color=col;
        if(l!=r)
            tree[n].lazy=1;
        return;
    }
    if(tree[n].color==col) return;
    pushDown(n);
//    if(Onecolor(tree[n].color)) //if there are more than one color in it,it couldn't have lazy step,and if it has only one color ,this step is always right
//        tree[n<<1].color=tree[n<<1|1].color=tree[n].color;
    int m=(tree[n].l+tree[n].r)>>1;
    if(r<=m) change(l,r,col,n<<1);
    else if(l<=m && r>m)
    {
        change(l,m,col,n<<1);
        change(m+1,r,col,n<<1|1);
    }
    else change(l,r,col,n<<1|1);
    pushUp(n);
}
int query(int l,int r,int n)
{
    int res=0;
    if(tree[n].l==l&&tree[n].r==r)
        return tree[n].color;
    pushDown(n);
//   if(Onecolor(tree[n].color)) return tree[n].color;
    int m=(tree[n].l+tree[n].r)>>1;
    if(r<=m) res=res|query(l,r,n<<1);
    else if(l<=m && r>m)
    {
        res=res|query(l,m,n<<1);
        res=res|query(m+1,r,n<<1|1);
    }
    else res=res|query(l,r,n<<1|1);
    return res;
}

inline int toBin(const int n)
{
    return 1<<(n-1);
}

int count(int n)
{
    int res=0;
    while(n)
    {
        if(n&1) res++;
        n>>=1;
    }
    return res;
}

void BS(int &a,int &b)
{
    if(a>b)
    {
        int tem=a;
        a=b;
        b=tem;
    }
    return;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int L,T,O;
    scanf("%d%d%d",&L,&T,&O);
    buildtree(1,L,1);
    char ch[2];
    int l,r,col,res;
    for(int i=0; i<O; ++i)
    {
        scanf("%s",ch);
        if(ch[0]=='C')
        {
            scanf("%d%d%d",&l,&r,&col);
            BS(l,r);
            col=toBin(col);
            change(l,r,col,1);
        }
        else
        {
            scanf("%d%d",&l,&r);
            BS(l,r);
            res=query(l,r,1);
            printf("%d\n",count(res));
        }
    }
    return 0;
}
