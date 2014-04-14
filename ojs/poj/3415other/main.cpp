#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int u=200010;
struct
{
    long long he;
    int na,nb;
} s[u];
long long h[u];
char str[u],str2[u];
int n,m,t,i,la,p;
long long suma,sumb,ans;
int a[u],sa[u],rank[u],fir[u],sec[u],c[u];
bool comp(int i,int j,int k)
{
    return sec[i]==sec[j]&&sec[i+k]==sec[j+k];
}
void sufarr(int n)
{
    int i,p,l,m=100;
    for(i=0; i<m; i++) c[i]=0;
    for(i=0; i<n; i++) c[rank[i]=a[i]]++;
    for(i=1; i<m; i++) c[i]+=c[i-1];
    for(i=n-1; i>=0; i--) sa[--c[a[i]]]=i;
    for(l=p=1; p<n; l*=2,m=p)
    {
        for(p=0,i=n-l; i<n; i++) sec[p++]=i;
        for(i=0; i<n; i++)
            if(sa[i]>=l) sec[p++]=sa[i]-l;
        for(i=0; i<n; i++) fir[i]=rank[sec[i]];
        for(i=0; i<m; i++) c[i]=0;
        for(i=0; i<n; i++) c[fir[i]]++;
        for(i=1; i<m; i++) c[i]+=c[i-1];
        for(i=n-1; i>=0; i--) sa[--c[fir[i]]]=sec[i];
        memcpy(sec,rank,sizeof(rank));
        rank[sa[0]]=0;
        for(i=p=1; i<n; i++)
            rank[sa[i]]=comp(sa[i],sa[i-1],l)?p-1:p++;
    }
}
void calh()
{
    int i,j,k=0;
    for(i=1; i<=n; i++) rank[sa[i]]=i;
    for(i=0; i<n; h[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1]; a[i+k]==a[j+k]; k++);
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(cin>>t&&t)
    {
        scanf("%s%s",&str,&str2);
        la=strlen(str);
        strcat(str,"@");
        strcat(str,str2);
        n=strlen(str);
        for(i=0; i<n; i++) a[i]=str[i]-'A'+2;
 //       for(i=0;i<n;i++)
 //           printf("%d\n",a[i]);
        a[n]=ans=p=suma=sumb=0;
        sufarr(n+1);
        calh();
        for(i=2; i<=n; i++)
            if(h[i]>=t)
            {
                if(i==3843)
                    cout<<i<<" "<<ans<<endl;
                s[++p].he=h[i]-t+1;
                if(sa[i-1]<la)suma+=s[p].he;
                else sumb+=s[p].he;
                s[p].na=sa[i-1]<la?1:0;
                s[p].nb=sa[i-1]<la?0:1;
                while(s[p-1].he>=s[p].he)
                {
                    suma-=(s[p-1].he-s[p].he)*s[p-1].na;
                    sumb-=(s[p-1].he-s[p].he)*s[p-1].nb;
                    p--;
                    s[p].he=s[p+1].he;
                    s[p].na+=s[p+1].na;
                    s[p].nb+=s[p+1].nb;
                }
                if(sa[i]<la)ans+=sumb;
                else ans+=suma;
                cout<<i<<" "<<ans<<endl;
            }
            else p=suma=sumb=0;
        cout<<ans<<endl;
    }
    return 0;
}
