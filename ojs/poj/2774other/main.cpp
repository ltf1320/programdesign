#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const int N=100005*2;
char s[N];
int height[N],sa[N],rank[N],source[N],cnt[N],wa[N],wb[N];
int cmp(int *x,int a,int b,int l)
{
    return (x[a]==x[b])&&(x[a+l]==x[b+l]);
}
void suffix(int *s,int len)
{
    int *y=wb,*t,*r=wa;
    int i,j,k,n,p,m;
    n = len;
    m=128;
    for(i=0;i<m;i++)
        cnt[i]=0;
    for(i=0;i<n;i++)
        cnt[r[i]=s[i]]++;
    for(i=1;i<m;i++)
        cnt[i]=cnt[i]+cnt[i-1];
    for(i=n-1;i>=0;i--)
        sa[--cnt[r[i]]]=i;
    for(j=1,p=1;p<n;m=p,j*=2)
    {
        for(p=0,i=n-j;i<n;i++)
            y[p++]=i;
        for(i=0;i<n;i++)
        {
            if(sa[i]>=j)
                y[p++]=sa[i]-j;
        }
        for(i=0;i<m;i++)
            cnt[i]=0;

        for(i=0;i<n;i++)
            cnt[r[y[i]]]++;

        for(i=1;i<m;i++)
            cnt[i]=cnt[i]+cnt[i-1];

        for(i=n-1;i>=0;i--)
            sa[--cnt[r[y[i]]]]=y[i];

        for(t=r,r=y,y=t,p=1,r[sa[0]]=0,i=1;i<n;i++)
            r[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;

    }
    for(i=1;i<n;i++)
        rank[sa[i]]=i;
    k=0;
    for(i=0;i<n-1;i++)
    {
        j=sa[rank[i]-1];
        for(k?k--:0;s[i+k]==s[j+k];k++);
        height[rank[i]]=k;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,n,ans=0;
    scanf("%s",s);
    j=strlen(s);
    s[j]=1;
    scanf("%s",s+j+1);
    n=strlen(s);
    for(i=0;i<n;i++) source[i]=s[i];
    source[n]=0;
    suffix(source,n+1);
    int result=0;
    for(i=2;i<=n;i++)
    {
        if(result<height[i])
            if((sa[i]>j && sa[i-1]<j) || (sa[i]<j && sa[i-1]>j))
                result=height[i];
    }
    for(int i=0;i<n;i++)
        printf("%d ",sa[i]);
    putchar('\n');
    for(int i=2;i<=n;i++)
        printf("%d ",height[i]);
    putchar('\n');
    cout<<result<<endl;
    return 0;
}
