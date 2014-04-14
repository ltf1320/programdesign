/*���TLE or WA��n�����...��������ǹ���
����һ���߶��������⣬һ���ص������һ��int�͵�������color������
��������������һ�������ȽϺ���⣬�ڶ��������Ƚ�ǿ�󣬵���һ���Ƚ������
������
��һ��������lazy��ǣ��޸ĺͲ�ѯʱ����lazy��Ǿ����·ţ�һ����׼���߶���
�ڶ���������ȥ��lazy��ǣ���color���Ƿ�ֻ��һ����ɫ����Ϊlazy�ı��
��һ����ǿ����뷨�����һ���߶α�lazy�ˣ����϶�ֻ��һ����ɫ���϶��Ƕ����޸�Ϊһ����ɫ��
��������û�б�lazy,��Ϊ�����е���ɫ�϶�Ҳֻ����һ�֣������·Ų��ᵼ�´���

��һ�ַ���310ms���ģ��ڶ���250ms����
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
