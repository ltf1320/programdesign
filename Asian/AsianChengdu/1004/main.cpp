#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const __int64 P[3]={(__int64)1000000007,222222224,183120};
int kkk;

struct JZ2
{
    __int64 arr[2][2];
    JZ2 operator*(const JZ2& a)
    {
        JZ2 tem;
        for(int i=0;i<2;++i)
            for(int j=0;j<2;++j)
                tem.arr[i][j]=arr[i][0]*a.arr[0][j]%P[kkk]+arr[i][1]*a.arr[1][j]%P[kkk];
        return tem;
    }
    JZ2 operator^(__int64 n)
    {
        JZ2 tem,now;
        now=*this;
        tem.arr[1][1]=1;
        tem.arr[0][0]=1;
        tem.arr[0][1]=0;
        tem.arr[1][0]=0;
        while(n)
        {
            //now:3,10,109,12970,183642229,121702232
            //znow:3,10,109,12970,183642229,84886138
            //now:
            //znowk: 183642229,55602393,55602393,16835050
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
        arr[0][0]%=P[kkk];
        arr[0][1]%=P[kkk];
        arr[1][0]%=P[kkk];
        arr[1][1]%=P[kkk];
    }
};

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    JZ2 pz;
    pz.arr[0][0]=3;
    pz.arr[0][1]=1;
    pz.arr[1][0]=1;
    pz.arr[1][1]=0;
    JZ2 res;
    __int64 n;
    while(~scanf("%I64d",&n))
    {
        res.arr[0][0]=n;
        //33,121702232,74000913
        for(kkk=2;kkk>=0;kkk--) //这里写成了int kkk,调了一个钟
        {
            if(res.arr[0][0])
                res=pz^(res.arr[0][0]-1);
        }
        printf("%I64d\n",res.arr[0][0]);
    }
    return 0;
    /*
    long long a,b,c;
    b=1,c=0;
    for(long long i=1;;i++)
    {
        a=(3*b+c)%222222224;
        c=b;
        b=a;
        if(c==0&&b==1)
        {
            printf("%lld\n",i);
            break;
        }
    }
    */
}
