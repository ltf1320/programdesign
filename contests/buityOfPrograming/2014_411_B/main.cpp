#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;
const LL MOD=1E9+7;

int main()
{
    int T,N;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&N);
        /*
        LL res=0;
        for(int i=1; i<=N; i++)
        {
            res+=i*i*i;
            res%=MOD;
            for(int j=1; j<=N; j++)
                if(j!=i)
                    for(int k=1; k<=N; k++)
                        if(k!=i&&k!=j)
                        {
                            res+=i*k*j;
                            res%=MOD;
                        }
        }
        */
                LL tmp=N*(N+1)/2;
                LL res=tmp*tmp*tmp-3*(N*(N+1)*(2*N+1)/6*tmp-tmp*tmp);
                printf("Case %d: ",cas);
        cout<<res%MOD<<endl;
    }
    return 0;
}
