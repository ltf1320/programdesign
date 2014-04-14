#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=100000+1000;
const int maxm=60;
const int maxst=100+10;
int N;
int res[maxn];
int resn;
int belong[maxn];
bool has[maxst];
int r[maxn];
char str[maxn];
char tmp[maxn];
int len;

int getN(char ch)
{
    if(ch>='a'&&ch<='z')
        return ch-'a'+2;
    else return ch-'A'+28;
}

int scmp(const void *aa,const void *bb)
{
    char *a=(char*)aa,*b=(char*)bb;
    if(strcmp(a,b)>0) return 1;
    else return 0;
}

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

bool check(int k)
{
    int hsn=0;
    for(int i=1; i<=len; i++)
    {
        if(height[i]<k)
        {
            hsn=0;
            memset(has,0,sizeof(has));
            if(belong[sa[i]]&&belong[sa[i]]==belong[sa[i]+k-1])
            {
                hsn++;
                has[belong[sa[i]]]=1;
            }
        }
        else
        {
            if(!has[belong[sa[i]]]&&belong[sa[i]]&&belong[sa[i]]==belong[sa[i]+k-1])
            {
                hsn++;
                has[belong[sa[i]]]=1;
            }
        }
        if(hsn>N/2)
            return true;
    }
    return false;
}

int search()
{
    int l=0,r=len;
    int m;
    while(l<r)
    {
        m=(l+r)>>1;
        if(check(m))
            l=m;
        else r=m-1;
        if(r-l==1)
        {
            if(check(r)) return r;
            else return l;
        }
    }
    return l;
}

void work()
{
    da(r,sa,len,maxm);
    calheight(r,sa,len);
    int k=search();
    if(k==0)
    {
        printf("?\n");
        return;
    }
    int hsn=0;
    resn=0;
    for(int i=1; i<=len; i++)
    {
        if(height[i]<k)
        {
            if(hsn>N/2)
            {
                res[resn++]=sa[i-1];
            }
            hsn=0;
            memset(has,0,sizeof(has));
            if(belong[sa[i]]&&belong[sa[i]]==belong[sa[i]+k-1])
            {
                hsn++;
                has[belong[sa[i]]]=1;
            }
        }
        else
        {
            if(!has[belong[sa[i]]]&&belong[sa[i]]&&belong[sa[i]]==belong[sa[i]+k-1])
            {
                hsn++;
                has[belong[sa[i]]]=1;
            }
        }
    }
    if(hsn>N/2)
    {
        res[resn++]=sa[len];
    }
//   qsort(res,resn,sizeof(char[maxn]),scmp);
 //   char last[maxn];
//    last[0]=0;
//    int p;
    for(int i=0; i<resn; i++)
    {
        for(int j=0; j<k; j++)
            putchar(str[res[i]+j]);
        putchar('\n');
    }
}

void input()
{
    len=0;
    int j;
    for(int i=0; i<N; i++)
    {
        scanf("%s",tmp);
        j=0;
        while(tmp[j])
        {
            belong[len]=i+1;
            str[len]=tmp[j];
            r[len++]=getN(tmp[j++]);
        }
        str[len]=1;
        belong[len]=0;
        r[len++]=1;
    }
}

void init()
{
    memset(sa,0,sizeof(sa));
    memset(belong,0,sizeof(belong));
}

int main()
{
    freopen("in.txt","r",stdin);
    bool start=0;
    while(~scanf("%d",&N)&&N)
    {
        if(start) putchar('\n');
        start=1;
        init();
        input();
        work();
    }
    return 0;
}
