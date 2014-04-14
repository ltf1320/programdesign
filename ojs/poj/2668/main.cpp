#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
int D,N;
LL res;

int find(int now,int dam)
{
    LL l=now,r=N;
    LL m;
    while(r>=l)
    {
        m=(l+r)>>1;
        if(ceil(1.0*D/m)>=dam)
            l=m+1;
        else r=m-1;
    }
    return (int)r;
}



int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int now,fi;
    int cnt;
    int lg;
    bool flag;
    while(~scanf("%d%d",&D,&N))
    {
        if(D==0&&N==0) break;
        res=0;
        cnt=0;
        flag=0;
        lg=log(N)+1;
        for(int i=1;i<=N;i++)
        {
            now=ceil(1.0*D/i);
            if(!flag&&ceil(1.0*D/i)==ceil(1.0*D/(i+lg)))
                flag=1;
            if(flag)
                fi=find(i,now);
            else fi=i;
            fi=min(fi,N);
            res+=(fi-i+1)*now;
            i=fi;
            cnt++;
        }
        printf("%I64d\n",res);
 //       cout<<cnt<<endl;
    }
    return 0;
}
