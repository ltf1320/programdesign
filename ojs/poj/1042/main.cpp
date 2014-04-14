#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=30;
int h,n;
int f[maxn];
int d[maxn];
int t[maxn];

struct Node
{
    int nf,no;
    Node(int n,int f):nf(f),no(n) {}
    Node () {}
    bool operator<(const Node &a)const
    {
        if(nf==a.nf) return no>a.no;
        return nf<a.nf;
    }
};

priority_queue<Node> que;
int nowt[maxn];
int rest[maxn];
int res,nres;

bool judge()
{
    for(int i=0;i<n;i++)
    {
        if(nowt[i]>rest[i])
            return true;
        else if(nowt[i]<rest[i]) return false;
    }
    return false;
}

int main()
{
    freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    int hd,nt;
    Node now;
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d",&h);
        res=-1;
        h*=12;
        hd=0;
        for(int i=0; i<n; i++)
            scanf("%d",&f[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&d[i]);
        for(int i=1; i<n; i++)
            scanf("%d",&t[i]);
        t[0]=0;
        for(int i=0; i<n; i++)
        {
            while(!que.empty()) que.pop();
            memset(nowt,0,sizeof(nowt));
            nres=0;
            hd+=t[i];
            nt=h-hd;
            if(nt<=0) break;
            for(int j=0;j<=i;j++)
                que.push(Node(j,f[j]));
            for(int j=0;j<nt;j++)
            {
                if(que.empty())
                {
                    nowt[0]+=5;
                    continue;
                }
                now=que.top();
                que.pop();
                nowt[now.no]+=5;
                nres+=now.nf;
                now.nf-=d[now.no];
                if(now.nf>0)
                    que.push(now);
            }
            if(nres>res)
            {
                for(int j=0;j<n;j++)
                    rest[j]=nowt[j];
                res=nres;
            }
            if(nres==res&&judge())
            {
                for(int j=0;j<n;j++)
                    rest[j]=nowt[j];
                res=nres;
            }
        }
        for(int i=0;i<n-1;i++)
            printf("%d, ",rest[i]);
        printf("%d\n",rest[n-1]);
        printf("Number of fish expected: %d\n\n",res);
    }
    return 0;
}
