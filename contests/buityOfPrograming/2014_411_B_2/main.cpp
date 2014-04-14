#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;
const LL MOD=1E9+7;

int main()
{
 //   freopen("in.txt","r",stdin);
    int T;
    LL N;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        cin>>N;
        LL tmp=N*(N+1)/2;
        tmp=tmp%MOD;
        LL t1=(tmp*tmp%MOD)*tmp%MOD;
        LL t2=((N*(N+1))/2)%MOD;
        t2=t2*(2*N+1)%MOD;
        t2=t2*tmp%MOD;
        LL t3=tmp*tmp%MOD;
        t3=t3*3%MOD;

      //  LL res=tmp*tmp*tmp-3*(N*(N+1)*(2*N+1)/6*tmp-tmp*tmp);
        LL res=t1-t2+t3;
        res=(res+MOD)%MOD;
        printf("Case %d: ",cas);
        cout<<res%MOD<<endl;
    }
    return 0;
}
