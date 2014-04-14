#include <iostream>
#include <cstdio>
using namespace std;

struct JZ2
{
    int arr[2][2];
    JZ2 operator*(const JZ2& a)
    {
        JZ2 tem;
        for(int i=0;i<2;++i)
            for(int j=0;j<2;++j)
                tem.arr[i][j]=arr[i][0]*a.arr[0][j]+arr[i][1]*a.arr[1][j];
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
        arr[0][0]%=10000;
        arr[0][1]%=10000;
        arr[1][0]%=10000;
        arr[1][1]%=10000;
    }
};



int main()
{
    freopen("in.txt","r",stdin);
    int n;
    JZ2 jz;
    while(~scanf("%d",&n))
    {
        if(n==-1) break;
        jz.arr[0][0]=jz.arr[0][1]=jz.arr[1][0]=1;
        jz.arr[1][1]=0;
        jz=jz^n;
        printf("%d\n",jz.arr[0][1]);
    }
    return 0;
}
