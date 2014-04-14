#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define p2(x) ((x)*(x))

using namespace std;
const int maxn=20;
const int MOD=maxn*maxn;
int N,NN;
int x[maxn];
int y[maxn];

int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

bool isTri(int x1,int y1,int x2,int y2,int x3,int y3)
{
    if((y2-y3)*(x1-x2)==((y1-y2)*(x2-x3))) return false;
    return true;
}

struct Tri
{
    int l[3];
    Tri(){}
    Tri(int x1,int y1,int x2,int y2,int x3,int y3)
    {
        l[0]=p2(x1-x3)+p2(y1-y3);
        l[1]=p2(x1-x2)+p2(y1-y2);
        l[2]=p2(x2-x3)+p2(y2-y3);
        sort(l,l+3);
        int gc=gcd(l[0],gcd(l[1],l[2]));
        for(int i=0;i<3;i++)
            l[i]/=gc;
    }
    bool operator==(const Tri &a)const
    {
        for(int i=0;i<3;i++)
            if(l[i]!=a.l[i])
                return false;
        return true;
    }
    int getHas()const
    {
        return (l[0]+l[1]+l[2])%MOD;
    }
};


struct HasNode
{
    Tri tri;
    int num;
    int next;
};

struct Has
{
    HasNode has[maxn*maxn*maxn];
    int box[maxn*maxn+100];
    int end;
    int insert(const Tri &a)
    {
        int h=a.getHas();
        for(int i=box[h];i!=-1;i=has[i].next)
        {
            if(a==has[i].tri)
            {
                has[i].num++;
                return 1;
            }
        }
        has[end].tri=a;
        has[end].num=1;
        has[end].next=box[h];
        box[h]=end++;
        return 0;
    }
    void init()
    {
        memset(box,-1,sizeof(box));
        end=0;
    }
};
Has has;

int sta[maxn];
void dfs(int n,int cnt)
{
    if(cnt==3)
    {
        if(isTri(x[sta[0]],y[sta[0]],x[sta[1]],y[sta[1]],x[sta[2]],y[sta[2]]))
            has.insert(Tri(x[sta[0]],y[sta[0]],x[sta[1]],y[sta[1]],x[sta[2]],y[sta[2]]));
        return;
    }
    if(n==N) return;
    dfs(n+1,cnt);
    sta[cnt]=n;
    dfs(n+1,cnt+1);
}

void work()
{
    dfs(0,0);
    int res=0;
    for(int i=0;i<has.end;i++)
    {
        res=max(res,has.has[i].num);
//        res+=has.has[i].num;
    }
    printf("%d\n",res);
}

void input()
{
    int nx,ny;
    bool flag;
    N=0;
    for(int i=0;i<NN;i++)
    {
        scanf("%d%d",&nx,&ny);
        flag=0;
        for(int j=0;j<N;j++)
        {
            if(nx==x[j]&&ny==y[j])
            {
                flag=1;
                break;
            }
        }
        if(flag) continue;
        x[N]=nx;
        y[N]=ny;
        N++;
    }
}

void init()
{
    has.init();
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&NN)&&NN)
    {
        init();
        input();
        work();
    }
    return 0;
}
