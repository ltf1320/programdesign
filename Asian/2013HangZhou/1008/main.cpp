#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=222222;
const int maxnn=200001;
bool is_prim[maxn];
int prim[maxn];
int sum[maxn];
int bj[maxn];
int l[maxn];
int r[maxn];
int num[maxn];
int res[maxn][30];
int resnn[maxn];
int pre[maxn];
int nxt[maxn];
int cnt;
int n,m;
int lowbit(int x)
{
    return x&-(x);
}
void update(int a,int b)
{
    for(int i=a;i<=n;i+=lowbit(i))
    {
        sum[i]+=b;
    }
}
int query(int a)
{
    int res=0;
    for(int i=a;i>0;i-=lowbit(i))
    {
        res+=sum[i];
    }
    return res;
}
void primm()
{
    for(int i=0; i<maxn; i++)
    {
        is_prim[i]=1;
    }
    is_prim[1]=is_prim[0]=0;
    cnt=0;
    for(int i=2; i<maxnn; i++)
    {
        if(is_prim[i])
        {
            prim[cnt++]=i;
        }
        for(int j=0; prim[j]*i<maxnn; j++)
        {
            is_prim[prim[j]*i]=0;
            if(!(i%prim[j]))
            {
                break;
            }
        }
    }
    for(int i=0; i<maxnn; i++)
    {
        int x=i;//
        int end=(int)sqrt(x+0.0);
        resnn[i]=0;
        for(int j=0; prim[j]<=end; j++)
        {
            if(x%prim[j]==0)
            {
                res[i][resnn[i]++]=prim[j];
                while(x%prim[j]==0)
                {
                    x=x/prim[j];
                }
            }
            if(x==1) break;
        }
        if(is_prim[x])
            res[i][resnn[i]++]=x;
    }
}
void init()
{
    memset(pre,0,sizeof(pre));
    for(int i=0;i<maxnn;i++)
    {
        nxt[i]=n+1;
    }
    for(int i=1; i<=n; i++)
    {
        l[i]=i;
        r[i]=i;
    }
}
void input()
{
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&num[i]);
    }
}
void solve()
{
    for(int i=1; i<=n; i++)
    {
        int max=0;
        for(int j=0; j<resnn[num[i]]; j++)
        {
            if(max<pre[res[num[i]][j]])
            {
                max=pre[res[num[i]][j]];
            }
            pre[res[num[i]][j]]=i;
        }
        l[i]=max+1;
    }
    for(int i=n; i>0; i--)
    {
        int max=n+1;
        for(int j=0; j<resnn[num[i]]; j++)
        {
            if(max>nxt[res[num[i]][j]])
            {
                max=nxt[res[num[i]][j]];
            }
            nxt[res[num[i]][j]]=i;
        }
        r[i]=max-1;
    }
    /*for(int i=1;i<=n;i++)
    {
        bj[l[i]]++;
        bj[r[i]]--;
    }*/
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
    {
        update(l[i],1);
        update(r[i],-1);
    }
    int a,b;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",query(num[a])-query(-1));
    }
    /*sum[0]=0;
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+bj[i];
    int a,b;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",sum[b]-sum[a-1]);
    }*/
}

int main()
{
    freopen("in.txt","r",stdin);
    primm();
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
            break;
        input();
        init();
        solve();
    }
    return 0;
}
