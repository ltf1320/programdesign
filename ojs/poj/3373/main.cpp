#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50;


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
//反过来存，加减乘法会快，除法会略慢，若只有除法，可以正着存
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

LNI operator-(LNI a,LNI b);
LNI operator/(LNI a,int n);
int operator%(LNI a,int n);


LNI operator+(LNI a,LNI b)
{
    LNI res;
    if(a.f*b.f==1)
    {
        res.f=a.f;
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
        res.num[res.n]=jw;
        res.n++;
    }
    return res;
}

bool operator<(const LNI &a,const LNI &b)
{
    if(a.f!=b.f) return a.f<b.f;
    if(a.n!=b.n) return a.f>0?(a.n<b.n):(a.n>b.n);
    for(int i=0; i<a.n; ++i)
        if(a.num[i]!=b.num[i]) return a.f>0?(a.num[i]<b.num[i]):(a.num[i]>b.num[i]);
    return 0;
}

LNI operator-(LNI a,LNI b)
{
    LNI res;
    if(a.f*b.f==-1)
    {
        b.f*=-1;
        return a+b;
    }
    res.f=a.f;
    if((a<b&&a.f>0)||(b<a&&a.f<0))
    {
        LNI t=a;
        a=b;
        b=t;
        res.f=-1*a.f;
    }
    memset(res.num,0,sizeof(res.num));
    int jw=0;
    res.n=max(a.n,b.n);
    for(int i=0; i<res.n; ++i)
    {
        if(i<a.n && i<b.n)
        {
            res.num[i]=a.num[i]-b.num[i]+jw;
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
    while(res.num[res.n-1]==0)
        res.n--;
    return res;
}

int operator%(LNI a,int n)
{
    for(int i=0;i<a.n-1;i++)
    {
        a.num[i]%=n;
        a.num[i+1]+=a.num[i]*10000;
    }
    a.num[a.n-1]%=n;
    return a.num[a.n-1];
}


LNI find(LNI a,int k)
{
    int diff=0;
    a=a-(a%k);

}

int main()
{
    LNI a;
    int k;
    while(a.read()!=EOF)
    {
        scanf("%d",&k);
        if(a%k){
            a.print();
            continue;
        }

    }
    return 0;
}
