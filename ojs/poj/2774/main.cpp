#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=200000+100;
int r[maxn];
char str1[maxn],str2[maxn];
int len1,len2;
int wa[maxn],wb[maxn],wv[maxn],ws1[maxn];
int sa[maxn];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
/*
void da(int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++) wss[i]=0;
    for(i=0; i<n; i++) wss[x[i]=r[i]]++;
    for(i=1; i<m; i++) wss[i]+=wss[i-1];
    for(i=n-1; i>=0; i--) sa[--wss[x[i]]]=i;
    for(j=1,p=1; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) wss[i]=0;
        for(i=0; i<n; i++) wss[wv[i]]++;
        for(i=1; i<m; i++) wss[i]+=wss[i-1];
        for(i=n-1; i>=0; i--) sa[--wss[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
*/
void da(int n,int m)
{
	r[n++]=0;
	int i,j,p,*x=wa,*y=wb,*t;
	for(i=0;i<m;i++)ws1[i]=0;
	for(i=0;i<n;i++)ws1[x[i]=r[i]]++;
	for(i=1;i<m;i++)ws1[i]+=ws1[i-1];
	for(i=n-1;i>=0;i--)sa[--ws1[x[i]]]=i;
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
}

int rank[maxn],height[maxn];
void calheight(int n)
{
	int i,j,k=0;
	for(i=1;i<=n;i++)rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}


int main()
{
    freopen("out.txt","w",stdout);
    freopen("in.txt","r",stdin);
    int n;
    scanf("%s%s",str1,str2);
    len1=strlen(str1);
    len2=strlen(str2);
    n=len1+len2+1;
    for(int i=0; i<len1; i++)
        r[i]=str1[i]+1;
    r[len1]=1;
    for(int i=0; i<len2; i++)
        r[i+len1+1]=str2[i]+1;
    r[n]=0;
    da(n,128);
    calheight(n);
    int res=0;
    for(int i=2; i<=n; i++)
    {
        if((sa[i-1]<len1&&sa[i]>len1)||(sa[i-1]>len1&&sa[i]<len1))
        {
            if(height[i]>res)
                res=height[i];
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",sa[i]);
    putchar('\n');
    for(int i=2;i<=n;i++)
        printf("%d ",height[i]);
    putchar('\n');

    printf("%d\n",res);
    return 0;
}
