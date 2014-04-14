#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
const int maxn= 100000+10;
const int maxm=30;
int N;
char str[maxn];
int res;
int r[maxn];
int dp[maxn][30];
set<int> rest;


int wa[maxn],wb[maxn],wv[maxn],ws1[maxn];
int sa[maxn];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
    r[n++]=0;
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++) ws1[i]=0;
    for(i=0; i<n; i++) ws1[x[i]=r[i]]++;
    for(i=1; i<m; i++) ws1[i]+=ws1[i-1];
    for(i=n-1; i>=0; i--) sa[--ws1[x[i]]]=i;
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
    return;
}

int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++) rank[sa[i]]=i;
    for(i=0; i<n; height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
    return;
}


void rmq()
{
    for(int i=0; i<=N; i++)
        dp[i][0]=height[i];
    for(int j=1; (1<<j)<=N; j++)
        for(int i=0; i<=N-(1<<j); i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int lcp(int a,int b)
{
    a=rank[a];
    b=rank[b];
    if(a>b)
    {
        int t=a;
        a=b;
        b=t;
    }
    a++; //!
    int pp=log(1.0*b-a)/log(2.0);
    if(b-a==0) pp=0;
    return min(dp[a][pp],dp[b-(1<<pp)+1][pp]);
}

void work()
{
    for(int i=0; i<N; i++)
        r[i]=str[i]-'a'+1;
    int st;
    r[N]=0;
    da(r,sa,N,maxm);
    calheight(r,sa,N);
    rmq();
    int t1,now,t2;
    for(int l=1; l<=N; l++)
        for(int i=0; i<=N-l; i+=l)
        {
            t1=lcp(i,i+l);
            now=t1/l+1;
            st=i;
            t2=lcp(i-(l-t1%l),i+t1%l);
            if(t2>t1)
            {
                now++;
                st-=l-t1%l;
            }
            if(res<now)
            {
                rest.clear();
                rest.insert(l);
                res=now;
            }
            else if(res==now) //cao
                rest.insert(l);
        }
    for(int i=1; i<=N; i++) //!
        for(set<int>::iterator iter=rest.begin();iter!=rest.end();iter++)
        {
            if(lcp(sa[i],sa[i]+*iter)/(*iter)+1>=res)
            {
                int len=res*(*iter);
                for(int k=0; k<len; k++)
                    putchar(str[sa[i]+k]);
                putchar('\n');
                return;
            }
        }

}

void init()
{
    memset(sa,0,sizeof(sa));
    memset(dp,0,sizeof(dp));
    N=strlen(str);
    rest.clear();
    res=0;//!
}

int main()
{
    freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int cas=0;
    while(~scanf("%s",str))
    {
        cas++;
        if(str[0]=='#') break;
        printf("Case %d: ",cas);
        init();
        work();
    }
    return 0;
}
