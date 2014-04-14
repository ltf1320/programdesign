#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=1000000+100;
const int inf=0x3f3f3f3f;

char str[maxn];
int fr[maxn];
int len;
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
        for(i=0; i<n; i++)if(sa[i]>=j)
                y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) ws1[i]=0;
        for(i=0; i<n; i++) ws1[wv[i]]++;
        for(i=1; i<m; i++) ws1[i]+=ws1[i-1];
        for(i=n-1; i>=0; i--) sa[--ws1[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
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

int fd[maxn];
void work()
{
    da(fr,sa,len,30);
    calheight(fr,sa,len);
    int mn=inf;
    int mid=rank[0];
    int i=mid;
    memset(fd,-1,sizeof(fd));
    while(i>0)
    {
        mn=min(mn,height[i+1]);
        if(sa[i]>=mn*2&&sa[i]==len-mn)
            fd[mn]=mn;
        i--;
    }
    i=mid+1;
    mn=inf;
    while(i<=len)
    {
        mn=min(mn,height[i]);
        if(sa[i]>=mn*2&&sa[i]==len-mn)
            fd[mn]=mn;
        i++;
    }
    for(int i=1;i<len;i++)
        fd[i]=max(fd[i-1],fd[i]);
    i=mid;
    int now;
    int res=0;
    mn=inf;
    while(i>0)
    {
        mn=min(mn,height[i+1]);
        now=min(mn,min(sa[i],(len-sa[i])/2));
        if(fd[now]!=-1)
        {
            now=min(now,fd[now]);
            res=max(now,res);
        }
        i--;
    }
    i=mid+1;
    mn=inf;
    while(i<=len)
    {
        mn=min(mn,height[i]);
        now=min(mn,min(sa[i],(len-sa[i])/2));
        if(fd[now]!=-1)
        {
            now=min(now,fd[now]);
            res=max(now,res);
        }
        i++;
    }

    printf("%d\n",res);
}

void input()
{
    scanf("%s",str);
    len=strlen(str);
    for(int i=0;i<len;i++)
    {
        fr[i]=str[i]-'a'+1;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        work();
    }
    return 0;
}
