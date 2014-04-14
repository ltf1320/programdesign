#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5000+100;
const int inf=0x3f3f3f3f;
int N;
bool ori[maxn]; //1 for B,0 for forward

int resk,resm;

struct Node
{
    int l,r;
    bool m;
};
Node tree[maxn*4];


void change(int n,int l,int r)
{
    if(tree[n].l==l&&tree[n].r==r)
    {
        tree[n].m^=1;
        return;
    }
    int m=(tree[n].l+tree[n].r)/2;
    if(r<=m)
        change(n<<1,l,r);
    else if(l>m)
        change(n<<1|1,l,r);
    else
    {
        change(n<<1,l,m);
        change(n<<1|1,m+1,r);
    }
}

bool query(int n,int a)
{
    if(tree[n].l==tree[n].r)
    {
        return tree[n].m;
    }
    if(tree[n].m)
    {
        tree[n<<1].m^=1;
        tree[n<<1|1].m^=1;
        tree[n].m=0;
    }
    int m=(tree[n].l+tree[n].r)/2;
    if(a<=m)
        return query(n<<1,a);
    else return query(n<<1|1,a);
}

void buildTree(int n,int l,int r)
{
    tree[n].l=l;
    tree[n].r=r;
    tree[n].m=0;
    if(l==r)
    {
        tree[n].m=ori[l];
        return;
    }
    int m=(l+r)>>1;
    buildTree(n<<1,l,m);
    buildTree(n<<1|1,m+1,r);

}

void judge(int k)
{
    int nowm=0;
    buildTree(1,1,N);
    for(int i=1;i<=N;i++)
    {
        if(query(1,i))
        {
            if(i+k-1>N)
                return;
            change(1,i,i+k-1);
            nowm++;
        }
    }
    if(nowm<resm)
    {
        resk=k;
        resm=nowm;
    }
}

void input()
{
    char ch;
    for(int i=1;i<=N;i++)
    {
        scanf("%c",&ch);
        if(ch==' '||ch=='\n')
        {
            i--;continue;
        }
        if(ch=='B')
            ori[i]=1;
        else ori[i]=0;
    }
}

void work()
{
    resm=inf;
    for(int i=1;i<=N;i++)
        judge(i);
    printf("%d %d\n",resk,resm);
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    input();
    work();
    return 0;
}
