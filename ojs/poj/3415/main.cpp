#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=200000+100;
const int maxm=100;
int N,len,len1,K;
char str1[maxn],str2[maxn];
int getN(char ch)
{
    if(ch>='a'&&ch<='z')
        return ch-'a'+2;
    if(ch>='A'&&ch<='Z')
        return ch-'A'+28;
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
    for(i=0; i<m; i++) ws1[i]=0;
    for(i=0; i<n; i++) ws1[x[i]=r[i]]++;
    for(i=1; i<m; i++) ws1[i]+=ws1[i-1];
    for(i=n-1; i>=0; i--) sa[--ws1[x[i]]]=i;
    for(j=1,p=1; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++)
            y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) ws1[i]=0;
        for(i=0; i<n; i++) ws1[wv[i]]++;
        for(i=1; i<m; i++) ws1[i]+=ws1[i-1];
        for(i=n-1; i>=0; i--) sa[--ws1[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return ;
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


bool has[120];
int hasn;

struct Stack
{
    LL l;
    int na,nb;
};
Stack st[maxn];
int stp;

LL work()
{
    LL res=0;
    da(r,sa,len,maxm);
    calheight(r,sa,len);
    LL suma,sumb;
    stp=suma=sumb=0;
    for(int i=2; i<=len; i++)
    {
  //      if(i==3842)
 //           cout<<i<<" "<<res<<endl;
        if(height[i]>=K)
        {
            //          if(sa[i]==len1) continue;
            st[++stp].l=height[i]-K+1;
            if(sa[i-1]<len1)suma+=st[stp].l;
            else sumb+=st[stp].l;
            st[stp].na=st[stp].nb=0;
            if(sa[i-1]<len1) st[stp].na=1; //i-1
            else  st[stp].nb=1;
            while(stp&&st[stp-1].l>=st[stp].l)
            {
                suma-=(st[stp-1].l-st[stp].l)*st[stp-1].na;
                sumb-=(st[stp-1].l-st[stp].l)*st[stp-1].nb;
                st[stp-1].na+=st[stp].na;
                st[stp-1].nb+=st[stp].nb;
                st[stp-1].l=st[stp].l;
                stp--;
            }
            if(sa[i]<len1) res+=sumb;
            else res+=suma;
  //          cout<<i<<" "<<res<<endl;
        }
        else stp=suma=sumb=0;
    }
    return res;
}

void input()
{
    scanf("%s",str1);
    scanf("%s",str2);
    len1=strlen(str1);
    for(int i=0; str1[i]; i++)
        r[len++]=getN(str1[i]);
    r[len++]=1;
    for(int i=0; str2[i]; i++)
        r[len++]=getN(str2[i]);
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
    freopen("out.txt","w",stdout);
    while(~scanf("%d",&K)&&K)
    {
        init();
        input();
 //       for(int i=0;i<len;i++)
 //           printf("%d\n",r[i]);
        cout<<work()<<endl;
    }
    return 0;
}
