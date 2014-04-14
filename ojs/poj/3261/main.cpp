#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=20000+100;
const int maxm=1000000+10;
int N,K;
int r[maxn];
int len1,len2;
int wa[maxm],wb[maxm],wv[maxm],ws1[maxm];
int sa[maxn];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int n,int m)
{
    r[n++]=0;
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++)ws1[i]=0;
    for(i=0; i<n; i++)ws1[x[i]=r[i]]++;
    for(i=1; i<m; i++)ws1[i]+=ws1[i-1];
    for(i=n-1; i>=0; i--)sa[--ws1[x[i]]]=i;
    for(j=1,p=1; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) ws1[i]=0;
        for(i=0; i<n; i++) ws1[wv[i]]++;
        for(i=1; i<m; i++) ws1[i]+=ws1[i-1];
        for(i=n-1; i>=0; i--) sa[--ws1[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}

int rank[maxn],height[maxn];
void calheight(int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++)rank[sa[i]]=i;
    for(i=0; i<n; height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
}


bool check(int k)
{
    int maxs,mins,starti;
    maxs=mins=sa[1];
    starti=1;
    for(int i=2; i<=N; i++)
    {
        if(height[i]>=k)
        {

        }
        else
        {
            starti=i;
        }
        if(i-starti+1>=K)
            return true;
    }
    return false;
}

int work()
{
    int l,r,m;
    l=0,r=N;
    while(l<r)
    {
        m=(l+r)>>1;
        if(check(m))
            l=m;
        else r=m;
        if(r-l<=1)
        {
            if(check(r)) return r;
            return l;
        }
    }
    return l;
}


int main()
{
//   freopen("out.txt","w",stdout);
    freopen("in.txt","r",stdin);
    int res;
    while(~scanf("%d%d",&N,&K)&&N)
    {
        memset(sa,0,sizeof(sa));
        for(int i=0; i<N; i++)
        {
            scanf("%d",&r[i]);
            r[i]++;
        }
        da(N,maxm);
        calheight(N);
        res=work();
        printf("%d\n",res);
    }
    return 0;
}
