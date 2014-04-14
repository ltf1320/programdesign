#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=100+10;
const int maxc=20+10;
const int maxN=15+5;
const int inf=0x3f3f3f3f;

bool uscol[maxc];
int res;
struct Node
{
    int x1,y1,x2,y2;
};
Node color[maxc][maxN];
bool bred[maxc][maxN];
int coln[maxc];

struct TreeNode
{
    int l,r;
    bool s;
};
TreeNode oped[maxn][5*maxn];

void buildTree(int x,int y1,int y2,int n)
{
    oped[x][n].s=0;
    oped[x][n].l=y1;
    oped[x][n].r=y2;
    if(y1==y2) return;
    int m=(y1+y2)>>1;
    buildTree(x,y1,m,n<<1);
    buildTree(x,m+1,y2,n<<1|1);
}

void cover(int x,int y1,int y2,int n)
{
    if(oped[x][n].s) return;
    if(y1==oped[x][n].l&&y2==oped[x][n].r)
    {
        oped[x][n].s=1;
        return;
    }
    int m=(oped[x][n].l+oped[x][n].r)>>1;
    if(y2<=m) cover(x,y1,y2,n<<1);
    else if(y1>m) cover(x,y1,y2,n<<1|1);
    else
    {
        cover(x,y1,m,n<<1);
        cover(x,m+1,y2,n<<1|1);
    }
}

void erase(int x,int y1,int y2,int n)
{
    if(oped[x][n].s) return;
    oped[x][n].s=0;
    if(y1==oped[x][n].l&&y2==oped[x][n].r)
        return;
    int m=(oped[x][n].l+oped[x][n].r)>>1;
    if(y2<=m) erase(x,y1,y2,n<<1);
    else if(y1>m) erase(x,y1,y2,n<<1|1);
    else
    {
        erase(x,y1,m,n<<1);
        erase(x,m+1,y2,n<<1|1);
    }
}

bool query(int x,int y1,int y2,int n)
{
    if(oped[x][n].s) return true;
    if(y1==oped[x][n].l&&y2==oped[x][n].r) return false;
    int m=(oped[x][n].l+oped[x][n].r)>>1;
    if(m>=y2) return query(x,y1,y2,n<<1);
    else if(m<y1) return query(x,y1,y2,n<<1|1);
    else return query(x,y1,m,n<<1)&&query(x,m+1,y2,n<<1|1);
}

bool jud()
{
    for(int i=0;i<maxc;i++)
        for(int j=0;j<coln[i];j++)
        {
            if(!bred[i][j]) return false;
        }
    return true;
}

void dfs(int now,int v)
{
    if(jud())
    {
        if(v<res) res=v;
        return;
    }
    vector<int> vs;
    for(int i=0;i<coln[now];i++)
    {
        if(!bred[now][i]&&query(color[now][i].x1,color[now][i].y1,color[now][i].y2,1))
        {
            cover(color[now][i].x2,color[now][i].y1,color[now][i].y2,1);
            vs.push_back(i);
            bred[now][i]=1;
        }
    }
    for(int i=0;i<maxc;i++)
    {
        if(i==now) continue;
        if(uscol[i])
        {
            dfs(i,v+1);
        }
    }
    for(size_t i=0;i<vs.size();i++)
    {
        erase(color[now][i].x2,color[now][i].y1,color[now][i].y2,1);
        bred[now][i]=0;
    }
    vs.clear();
}

void work()
{
    for(int i=0;i<maxc;i++)
    {
        if(uscol[i])
        {
            dfs(i,0);
        }
    }
}

void init()
{
    for(int i=0;i<maxn;i++) buildTree(i,1,100,1);
    memset(coln,0,sizeof(coln));
    memset(uscol,0,sizeof(uscol));
    memset(bred,0,sizeof(bred));
    res=inf;
}

void input()
{
    int M;
    int x1,x2,y1,y2,col;
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&col);
        color[col][coln[col]].x1=x1;
        color[col][coln[col]].x2=x2;
        color[col][coln[col]].y1=y1;
        color[col][coln[col]].y2=y2;
        coln[col]++;
        uscol[col]=1;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        input();
        work();
        printf("%d\n",res);
    }
    return 0;
}
