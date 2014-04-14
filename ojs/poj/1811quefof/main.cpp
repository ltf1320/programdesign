#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef unsigned long long U64;

long long multiply( long long a,long long b,long long n)
{
    long long exp,res=0;
    //这个就是用加法，来模拟乘法，为了防止运算的数太大，
    exp=a%n;
    while(b)
    {
        if(b&1)
        {
            res+=exp;
            if(res>n)
                res-=n;
        }
        exp<<=1;
        if(exp>n)
            exp-=n;
        b/=2;
    }
    return res;
}
long long paw(long long a,long long t,long long n)
{
    long long ans=1;
    a=a%n;
    while(t)
    {
        if(t%2==1)
            ans=multiply(ans,a,n);
        a=multiply(a,a,n);
        t/=2;
    }
    return ans;
}

bool miller_rabin(long long n,long long ti)
{
    if(n==2)
        return true;
    if(n<2||!(n&1))
        return false;
    long long p=n-1;
    long long k=0,a,x;
    while(p%2==0)
    {
        p/=2;
        k++;
    }
    long long ans;
    srand(time(0));
    for(int t=1; t<=ti; t++)
    {
        a=rand()%(n-1)+1;
        x=paw(a,p,n);
        for(int i=1; i<=k; i++)
        {
            ans=multiply(x,x,n);
            if(ans==1&&x!=1&&x!=n-1)
                return false;
            x=ans;
        }
        if(ans!=1)
            //注意这个判断！
            return false;
    }
    return true;
}



U64 gcd(U64 a,U64 b)
{
    U64 t;
    if(a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

typedef unsigned long long U64;

typedef unsigned int U32;

const U32 MAX_INDEEP = 10000;

const U32 TABLE_SIZE = 131071;

U32 sqrt_table[TABLE_SIZE] = {0};

class squfof

{

      U32 try_ana(U64 N)

      {

            U32 sqrt_n = (U32) sqrt((long double) N);

            U32 P1 = sqrt_n, Q2 = 1, Q1 = N - (U64) P1*P1;

            U32 B, P, Q, step = MAX_INDEEP;

            if (Q1 == 0)return P1;

            while (sqrt_table[Q1 % TABLE_SIZE] != Q1)

            {

                  B = (sqrt_n + P1) / Q1;

                  P = B * Q1 - P1;

                  Q = Q2 + B * (P1 - P);

                  P1 = P;

                  Q2 = Q1;

                  Q1 = Q;

            }

            U32 sqrt_Qi = (U32) sqrt((long double) Q1);

            B = (sqrt_n - P1) / sqrt_Qi;

            P1 = B * sqrt_Qi + P;

            Q2 = sqrt_Qi;

            Q1 = (N - (U64) P1 * P1) / Q2;

            P = P1;

            P1 = 0;

            while (P != P1 && step--)

            {

                  P1 = P;

                  B = (sqrt_n + P1) / Q1;

                  P = B * Q1 - P1;

                  Q = Q2 + B * (P1 - P);

                  Q2 = Q1;

                  Q1 = Q;

            }

            return P;

      }

public:

      void init()

      {

            for (U32 i = 0; i < (1 << 16); i++)

                  sqrt_table[i * i % TABLE_SIZE] = i * i;

      }

      U32 analyze(U64 N)

      {

            U32 k, t = 0;

            for (k = 1; t == 0 || t == 1; k++)

            {

                  t = gcd(try_ana(k * N), N);

            }

            return t;

      }

};

int main()
{
    freopen("in.txt","r",stdin);
    U64 n,t;
    squfof sq;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        sq.init();
        if(miller_rabin(n,120))
        {
            printf("Prime\n");
            continue;
        }
        printf("%d\n",sq.analyze(n));
    }
    return 0;
}
