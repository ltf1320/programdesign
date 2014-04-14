#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=110;
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
    int num[maxn];
    int n;
    int f;
    int read()
    {
        memset(num,0,sizeof(num));
        char *tem;
        tem=new char[maxn];
        if(scanf("%s",tem)==EOF) return EOF;
        change(tem);
        rev(num,n);
        delete [] tem;
        return 0;
    }
    void change(char *tem)
    {
        f=1;
        if(*tem=='-')
        {
            f=-1;
            tem++;
        }
        while(*tem=='0')
            tem++;
        int l=strlen(tem);
        int p=l%4;
        int k=-1;
        if(p)
        {
            k++;
            num[k]=tem[0]-'0';
            for(int i=1; i<p; ++i)
            {
                num[k]=num[k]*10+tem[i]-'0';
            }
        }
        for(int i=p; i<l; ++i)
        {
            if(i%4==p)
            {
                k++;
                num[k]=tem[i]-'0';
            }
            else
            {
                num[k]=num[k]*10+tem[i]-'0';
            }
        }
        n=(l-1)/4+1;
    }
    void print()
    {
        rev(num,n);
        int i=0;
        if(f<0) putchar('-');
        printf("%d",num[i++]);
        for(; i<n; ++i)
            printf("%04d",num[i]);
        printf("\n");
    }
};


LNI operator+(LNI a,LNI b)
{
    LNI res;
    memset(res.num,0,sizeof(res.num));
    int jw=0;
    res.n=max(a.n,b.n);
    for(int i=0; i<res.n; ++i)
    {
        if(i<a.n && i<b.n)
        {
            res.num[i]=a.num[i]+b.num[i]+jw;
            jw=res.num[i]/10000;
            res.num[i]%=10000;
        }
        else if(i>=a.n)
        {
            res.num[i]=b.num[i]+jw;
            jw=res.num[i]/10000;
            res.num[i]%=10000;
        }
        else if(i>=b.n)
        {
            res.num[i]=a.num[i]+jw;
            jw=res.num[i]/10000;
            res.num[i]%=10000;
        }
    }
    if(jw)
    {
        if(res.num[res.n-1]/1000)
        {
            res.num[res.n]=jw;
            res.n++;
        }
        else
        {
            int k=1;
            for(int i=0; i<k%4; ++i)
                k*=10;
            res.num[k-1]+=jw*k;
        }
    }
    return res;
}


int main()
{
    freopen("in.txt","r",stdin);
    LNI res,zero,tem;
    zero.n=1;
    zero.f=1;
    zero.num[0]=0;
    res=zero;
    while(tem.read()!=EOF)
    {
        if(tem.n==1&&tem.num[0]==0)
        {
            res.print();
            return 0;
        }
        res=res+tem;
    }
    return 0;
}
