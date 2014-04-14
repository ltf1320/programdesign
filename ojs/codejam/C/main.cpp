#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=20;

void rev(int* m,int l)
{
    int t;
    for(int i=0; i<l/2; ++i)
    {
        t=m[i];
        m[i]=m[l-i-1];
        m[l-i-1]=t;
    }
}

struct LNI
{
    int n;
    int num[maxn];
    LNI(){n=0;memset(num,0,sizeof(num));}
    void print()
    {
        for(int i=0;i<n;i++)
            putchar(num[i]+'0');
    }
    LNI operator+(LNI a)
    {
        LNI res;
        rev(num,n);
        rev(a.num,a.n);
        res.n=max(n,a.n);
        for(int i=0;i<res.n;i++)
        {
            res.num[i]+=num[i]+a.num[i];
            if(res.num[i]>=10)
            {
                res.num[i]-=10;
                res.num[i+1]=1;
            }
        }
        if(res.num[res.n])
            res.n++;
        rev(res.num,res.n);
        rev(num,n);
    }
};

int main()
{
    return 0;
}
