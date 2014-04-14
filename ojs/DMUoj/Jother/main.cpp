#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

const int N=100010;
int i,j,k;
int n,m;
int a[N],b[N],c[N],d[N],e[N],ans1,ans2;
int min(int a,int b)
{
    return a>b?b:a;
}
int max(int a,int b)
{
    return a>b?a:b;
}

int solve()
{
    int i,j;

    d[1]=0;e[1]=1;
    for (j=2;j<=n;j++)
    if(a[j]==-1)
    {
        d[j]=b[j-1]-d[j-1]-d[j-2];
        e[j]=-e[j-1]-e[j-2];
    }

    ans1=b[1];ans2=0;
    for (i=1;i<=n;i++)
    {
        if (e[i]<0)
        {
            ans1=min(d[i],ans1);
        }
        else if (e[i]>0)
        {
            ans2=max(-d[i],ans2);
        }
    }
    return 0;
}
int solve2(int p)
{
    if (e[p]<0)return d[p]-ans2;
    else return d[p]+ans1;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF)
    {
        a[0]=a[n+1]=0;
        for (i=1;i<=n;i++)scanf("%d",&a[i]);
        for (i=1;i<=n;i++)scanf("%d",&b[i]);
        scanf("%d",&m);
        for (i=1;i<=m;i++){scanf("%d",&c[i]);c[i]++;}

        for (i=3;i<=n;i+=3)
        {
            a[i]=b[i-1]-b[i-2]+a[i-3];
        }
        for (i=n-2;i>=1;i-=3)
        {
            a[i]=b[i+1]-b[i+2]+a[i+3];
        }

        for (i=1;i<=n;i++)
        {
            if (a[i]>-1 && i%3>0)break;
        }
        if (i<=n)
        {
            for (j=i+1;j<=n;j++)
                if(a[j]==-1) a[j]=b[j-1]-a[j-1]-a[j-2];
            for (j=i-1;j>=1;j--)
                if(a[j]==-1) a[j]=b[j+1]-a[j+1]-a[j+2];
        }
        for(i=1;i<=n;i++)
            d[i]=a[i]>-1?a[i]:0;e[i]=0;
        if (a[1] == -1)solve();

        for (i=1;i<=m;i++)
            if (a[c[i]]>-1) printf("%d\n",a[c[i]]);
            else printf("%d\n",solve2(c[i]));
    }
    return 0;
}
