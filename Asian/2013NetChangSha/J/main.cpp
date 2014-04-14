#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
int N,P;
int a[maxn];
int s[maxn];

void dfs(int i)
{
    if(a[i]==-1) return;
    if(i<N-1&&a[i+1]!=-1)
    {
        if(i>0&&a[i-1]==-1)
        {
            a[i-1]=s[i]-a[i]-a[i+1];
            dfs(i-1);
        }
        if(i<N-2&&a[i+2]==-1)
        {
            a[i+2]=s[i+1]-a[i]-a[i+1];
            dfs(i+2);
        }
    }
    if(i>0&&a[i-1]!=-1)
    {
        if(i>1&&a[i-2]==-1)
        {
            a[i-2]=s[i-1]-a[i]-a[i-1];
            dfs(i-2);
        }
        if(a[i+1]==-1&&i<N-1)
        {
            a[i+1]=s[i]-a[i]-a[i-1];
            dfs(i+1);
        }
    }
    if(i<N-2&&a[i+2]!=-1&&a[i+1]==-1)
    {
        a[i+1]=s[i+1]-a[i]-a[i+2];
        dfs(i+1);
    }
    if(i>1&&a[i-2]!=-1&&a[i-1]==-1)
    {
        a[i-1]=s[i-1]-a[i]-a[i-2];
        dfs(i-1);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        for(int i=0; i<N; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<N; i++)
            scanf("%d",&s[i]);
        a[2]=s[1]-s[0];
        for(int i=5; i<N; i+=3)
            a[i]=s[i-1]-s[i-2]+a[i-3];
        a[N-3]=s[N-2]-s[N-1];
        for(int i=N-6; i>=0; i-=3)
            a[i]=s[i+1]-s[i+2]+a[i+3];
        for(int i=0; i<N; i++)
        {
            dfs(i);
        }
        scanf("%d",&P);
        int t,res,nr;
        for(int i=0; i<P; i++)
        {
            scanf("%d",&t);
            if(a[t]!=-1)
                printf("%d\n",a[t]);
            else
            {
                res=s[t];
                if(t>0&&a[t-1]!=-1)
                    res-=a[t-1];
                if(t<N-1&&a[t+1]!=-1)
                    res-=a[t+1];
                if(t>0)
                {
                    nr=s[t-1];
                    if(t>1&&a[t-2]!=-1)
                        nr-=a[t-2];
                    if(a[t-1]!=-1)
                        nr-=a[t-1];
                    res=min(res,nr);
                }
                if(t<N-1)
                {
                    nr=s[t+1];
                    if(t<N-2&&a[t+2]!=-1)
                        nr-=a[t+2];
                    if(a[t+1]!=-1) //
                        nr-=a[t+1];
                    res=min(res,nr);
                }
                printf("%d\n",res);
            }
        }

        for(int i=0;i<N;i++)
            printf("%d ",a[i]);
        puts("");

    }
    return 0;
}
