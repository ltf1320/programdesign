#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;
struct JZ2
{
    LL arr[2][2];
    JZ2 operator*(const JZ2& a)
    {
        JZ2 tem;
        for(int i=0; i<2; ++i)
            for(int j=0; j<2; ++j)
            {
                tem.arr[i][j]=arr[i][0]*a.arr[0][j]+arr[i][1]*a.arr[1][j];
                if(tem.arr[i][j]<0) printf("errtem\n");
            }
        return tem;
    }
    JZ2 operator^(int n)
    {
        JZ2 tem,now;
        now=*this;
        tem.arr[0][0]=tem.arr[1][1]=1;
        tem.arr[0][1]=tem.arr[1][0]=0;
        while(n)
        {
            if(n&1)
            {
                tem=tem*now;
                tem.mod();
            }
            n>>=1;
            now=now*now;
            now.mod();
        }
        return tem;
    }
    void mod()
    {
        if(arr[0][0]>=MOD)
            arr[0][0]%=MOD;
        if(arr[0][1]>=MOD)
            arr[0][1]%=MOD;
        if(arr[1][0]>=MOD)
            arr[1][0]%=MOD;
        if(arr[1][1]>=MOD)
            arr[1][1]%=MOD;
    }
};

LL mpow(int a,int n)
{
    LL res=1;
    LL now=a;
    while(n)
    {
        if(n&1)
        {
            res*=now;
            if(res<0) printf("err\n");
            if(res>=MOD)res%=MOD;
        }
        n>>=1;
        now*=now;
        if(now<0) printf("err\n");
        if(now>=MOD) now%=MOD;
    }
    return res;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    int a,b,n;
    JZ2 jz;
    int res;
    while(~scanf("%d%d%d",&a,&b,&n))
    {
        jz.arr[0][0]=jz.arr[0][1]=jz.arr[1][0]=1;
        jz.arr[1][1]=0;
        jz=jz^n;
        res=(mpow(a,jz.arr[1][1])*mpow(b,jz.arr[1][0]))%MOD;
        printf("%d\n",res);
    }
    return 0;
}
