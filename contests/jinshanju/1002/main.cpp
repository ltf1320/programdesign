#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;
struct Mat
{
    LL a[2][2];
    Mat operator*(const Mat &b) const
    {
        Mat res;
         for(int i=0;i<2;++i)
            for(int j=0;j<2;++j)
            {
                res.a[i][j]=a[i][0]*b.a[0][j]+a[i][1]*b.a[1][j];
                if(res.a[i][j]>=MOD)
                    res.a[i][j]%=MOD;
            }
        return res;
    }
    Mat operator^(LL k) const
    {
        Mat now=*this;
        Mat res;
        res.a[0][0]=res.a[1][1]=1;
        res.a[1][0]=res.a[0][1]=0;
        while(k)
        {
            if(k&1)
                res=res*now;
            now=now*now;
            k>>=1;
        }
        return res;
    }
};
Mat dd;

void pre()
{
    dd.a[0][0]=dd.a[0][1]=dd.a[1][0]=1;
    dd.a[1][1]=0;
}
LL res;

void cc(LL a,LL n)
{
    LL now=a;
    while(n)
    {
        if(n&1)
        {
            res*=now;
            if(res>=MOD)res%=MOD;
        }
        n>>=1;
        now*=now;
        if(now>=MOD)
            now%=MOD;
    }
}

int main()
{
    pre();
    Mat rMat;
    LL a,b,n;
    LL ap,bp;

    while(cin>>a>>b>>n)
    {
        if(n==0)
        {
            cout<<a<<endl;
            continue;
        }
        rMat=dd^(n);
        ap=rMat.a[1][1];
        bp=rMat.a[1][0];
        res=1;
        cc(a,ap);
        cc(b,bp);
        cout<<res%MOD<<endl;
    }
    return 0;
}
