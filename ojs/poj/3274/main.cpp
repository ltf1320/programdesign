#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+10;
const int inf=0x3f3f3f3f;
int N,K,res;

struct Node
{
    int l,r;
    int pnum[30];
};
Node Tree[4*maxn];
int cha[maxn];

void buildTree(int l,int r,int n)
{
    Tree[n].l=l;
    Tree[n].r=r;
    if(l==r)
    {
        int tmp=cha[l];
        memset(Tree[n].pnum,0,sizeof(Tree[n].pnum));
        for(int i=0;tmp;tmp>>=1,i++)
        {
            if(tmp&1) Tree[n].pnum[i]=1;
        }
        return;
    }
    buildTree(l,(l+r)>>1,n<<1);
    buildTree(((l+r)>>1)+1,r,n<<1|1);
    for(int i=0;i<K;i++)
        Tree[n].pnum[i]=Tree[n<<1].pnum[i]+Tree[n<<1|1].pnum[i];
}
int qt[30];
void query(int l,int r,int n)
{
    if(l==Tree[n].l&&r==Tree[n].r)
    {
        for(int i=0;i<K;i++)
            qt[i]+=Tree[n].pnum[i];
        return;
    }
    int m=(Tree[n].l+Tree[n].r)>>1;
    if(r<=m) query(l,r,n<<1);
    else if(l>m) query(l,r,n<<1|1);
    else
    {
        query(l,m,n<<1);
        query(m+1,r,n<<1|1);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++)
        scanf("%d",&cha[i]);
    buildTree(1,N,1);
    res=1000;
    int k;
    for(int i=1;i<=N;i++)
        for(int j=res;j<=N-i;j++)
        {
            memset(qt,0,sizeof(qt));
            query(i,i+j,1);
            for(k=1;k<K;k++)
                if(qt[k]!=qt[k-1]) break;
            if(k==K) res=j;
        }
    printf("%d\n",res+1);
    return 0;
}
