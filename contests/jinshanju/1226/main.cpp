#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=20000+1000;
const int maxm=80;
int N,len;

int getN(char ch)
{
    if(ch>='a'&&ch<='z')
        return ch-'a'+2;
    if(ch>='A'&&ch<='Z')
        return ch-'A'+28;
    if(ch>='0'&&ch<='9')
        return ch-'0'+60;
    return -1000000;
}


int r[maxn];
int belong[maxn];
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
    for(i=0;i<m;i++) ws1[i]=0;
    for(i=0;i<n;i++) ws1[x[i]=r[i]]++;
    for(i=1;i<m;i++) ws1[i]+=ws1[i-1];
    for(i=n-1;i>=0;i--) sa[--ws1[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ws1[i]=0;
        for(i=0;i<n;i++) ws1[wv[i]]++;
        for(i=1;i<m;i++) ws1[i]+=ws1[i-1];
        for(i=n-1;i>=0;i--) sa[--ws1[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return ;
}

int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}

bool has[120];
int hasn;
bool check(int k)
{
    hasn=0;
    for(int i=1;i<=len;i++)
    {
        if(height[i]<k)
        {
            if(hasn>=N) return true;
            hasn=1;
            memset(has,0,sizeof(has));
            has[belong[sa[i]]/2]=1;
        }
        else
        {
            if(belong[sa[i]]&&!has[belong[sa[i]]/2]&&belong[sa[i]]==belong[sa[i]+k-1])
            {
                hasn++;
                has[belong[sa[i]]/2]=1;
            }
        }
    }
    if(hasn>=N) return true;
    return false;
}

int work()
{
    da(r,sa,len,maxm);
    calheight(r,sa,len);
    int l=0,r=101;
    int m;
    while(l<r)
    {
        m=(l+r)>>1;
        if(check(m))
            l=m;
        else r=m-1;
        if(r-l<=1)
        {
            if(check(r)) return r;
            else return l;
        }
    }
    return l;
}
char tmp[120];
void input()
{
    int j;
    for(int i=1;i<=N;i++)
    {
        scanf("%s",tmp);
        for(j=0;tmp[j];j++)
        {
            belong[len]=2*i;
            r[len++]=getN(tmp[j]);
        }
        belong[len]=0;
        r[len++]=1;
        for(j--;j>=0;j--)
        {
            belong[len]=2*i+1;
            r[len++]=getN(tmp[j]);
        }
        belong[len]=0;
        r[len++]=1;
    }
    r[len]=0;
}

void init()
{
    memset(sa,0,sizeof(sa));
    len=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        init();
        input();
        if(N==1)
            printf("%d\n",strlen(tmp));
        else printf("%d\n",work());
    }
    return 0;
}
