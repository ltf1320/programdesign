#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const __int64 maxn=10005;
__int64 count[maxn];
__int64 P[maxn],num[maxn];
__int64 Prime[maxn];
void init(){
    __int64 i;
    memset(P,0,sizeof(P));
    memset(num,0,sizeof(num));
    for(i=4;i<maxn;i++){
        P[i]=i*(i-1)*(i-2)*(i-3)/24;
    }
}
void gao(__int64 x){
    __int64 i,j;
    __int64 n=x,tot=0;
    for(i=2;i*i<=n;i++){
        if(n%i==0)    Prime[tot++]=i;
        while(n%i==0)n/=i;
    }
    if(n>1)Prime[tot++]=n;
    for(i=1;i<(1<<tot);i++){
        __int64 ji=1;
        __int64 sum=0;
        for(j=0;j<tot;j++)if(i&(1<<j)){
            ji*=Prime[j];
            sum++;
        }
        count[ji]++;
        num[ji]=sum;
    }
}
int  main(){
    freopen("in.txt","r",stdin);
    __int64 i,in,n;
    init();
    while(scanf("%I64d",&n)!=-1){
        memset(count,0,sizeof(count));
        for(i=0;i<n;i++){
            scanf("%I64d",&in);
            gao(in);
        }
        __int64 ans=0;
        for(i=0;i<maxn;i++)if(count[i]){
            if(num[i]%2)    ans+=P[count[i]];
            else            ans-=P[count[i]];
        }
        ans=P[n]-ans;
        printf("%I64d\n",ans);
    }
    return 0;
}
