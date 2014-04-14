#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=3000;

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
        char *tem,*tmm;
        if(*tem=='-') f=-1;
        tem++;
        tem=new char[maxn];
        tmm=tem;
        if(scanf("%s",tem)==EOF) return EOF;
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
        delete [] tmm;
        n=(l-1)/4+1;
        return 0;
    }
    void print()
    {
        int i=0;
        printf("%d",num[i++]);
        for(; i<n; ++i)
            printf("%04d",num[i]);
        printf("\n");
    }

};
LNI operator-(LNI a,LNI b);
LNI operator+(LNI a,LNI b)
{
    LNI res;
    if(a.f*b.f==1)
    {
        res.f=1;
    }
    else
    {
        if(a.f<0)
        {
            a.f=1;
            return b-a;
        }
        else
        {
            b.f=1;
            return a-b;
        }
    }
    rev(a.num,a.n);
    rev(b.num,b.n);
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
    rev(res.num,res.n);
    return res;
}

LNI operator-(LNI a,LNI b)
{
    LNI res;
    if(a.f*b.f==-1)
    {
        b.f*=-1;
        return a+b;
    }
    rev(a.num,a.n);
    rev(b.num,b.n);
    memset(res.num,0,sizeof(res.num));
    int jw=0;
    res.n=max(a.n,b.n);
    for(int i=0; i<res.n; ++i)
    {
        if(i<a.n && i<b.n)
        {
            res.num[i]=a.num[i]+b.num[i]+jw;
            jw=0;
            if(res.num[i]<0)
            {
                jw=-1;
                res.num[i]+=10000;
            }
        }
        else if(i>=a.n)
        {
            res.num[i]=b.num[i]+jw;
            jw=0;
            if(res.num[i]<0)
            {
                jw=-1;
                res.num[i]+=10000;
            }
        }
        else if(i>=b.n)
        {
            res.num[i]=a.num[i]+jw;
            jw=0;
            if(res.num[i]<0)
            {
                jw=-1;
                res.num[i]+=10000;
            }
        }
    }

//Ã»Ğ´Íê
    rev(res.num,res.n);
    return res;
}

LNI operator*(LNI a,LNI b)
{
    LNI res;
    rev(a.num,a.n);
    rev(b.num,b.n);
    memset(res.num,0,sizeof(res.num));
    int jw,k;
    for(int i=0; i<a.n; ++i)
    {
        for(int j=0; j<b.n; ++j)
        {
            res.num[i+j]+=a.num[i]*b.num[j];
            jw=res.num[i+j]/10000;
            res.num[i+j]%=10000;
            k=1;
            while(jw)
            {
                res.num[i+j+k]+=jw;
                jw=res.num[i+j+k]/10000;
                res.num[i+j+k]%=10000;
                k++;
            }
        }
    }
    int n=a.n+b.n-1;
    while(res.num[n++]);
    res.n=n-1;
    rev(res.num,res.n);
    return res;
}

LNI operator^(LNI a,int n)
{
    LNI res;
    res.n=1;
    res.num[0]=1;
    while(n)
    {
        if(n&1)
            res=res*a;
        a=a*a;
        n>>=1;
    }
    return res;
}


int main()
{
    freopen("in.txt","r",stdin);
    LNI n1,n2,res;
    while(n1.read()!=EOF && n2.read()!=EOF)
    {
        res=n1*n2;
        res.print();
    }
    return 0;
}
