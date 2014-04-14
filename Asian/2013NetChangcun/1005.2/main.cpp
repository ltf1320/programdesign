#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=1000000+100;

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

bool judge(int k)
{
    int mid=rank[0];
    int i=mid-1;
    while(i>0&&height[i+1]>=k)
    {
        if(sa[i]>=k&&sa[i]+k+k<=len)
        {
            return 1;
        }
        i--;
    }
    i=mid+1;
    while(i<=len&&height[i]>=k)
    {
        if(sa[i]>=k&&sa[i]+k+k<=len)
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int next[maxn];
void kmp()
{
    int k=-1;
    next[0]=-1;
    for(int i=1;i<len;i++)
    {
        while(k!=-1&&fr[i]!=fr[k+1])
            k=next[k];
        if(fr[i]==fr[k+1])
            k++;
        next[i]=k;
    }
}

void work()
{
    da(fr,sa,len,30);
    calheight(fr,sa,len);
    kmp();
    int p=len-1;
    while(p>len/3)
        p=next[p];
    while(!judge(p+1)&&p!=-1)
        p=next[p];
    printf("%d\n",p+1);
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
