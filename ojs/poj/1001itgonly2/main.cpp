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
        char *tem;
        tem=new char[maxn];
        if(scanf("%s",tem)==EOF) return EOF;
        change(tem);
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
        res.num[res.n]=jw;
        res.n++;
    }
    rev(res.num,res.n);
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
    rev(a.num,a.n);
    rev(b.num,b.n);
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
    rev(res.num,res.n);
    return res;
}

LNI operator*(LNI a,LNI b)
{
    LNI res;
    res.f=a.f*b.f;
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

LNI sqr(const LNI &a)  //使用二分法找平方根
{
    LNI res=a/2;
    LNI dif;
    LNI one;
    one.f=1;
    one.num[0]=1;
    one.n=1;
    LNI Max=a,Min=one;
    while(1)
    {
        dif=res*res-a;
        if(dif.n==1&&dif.num[0]==0)
            break;
        if(dif.f<0)
        {
            Min=res;
            dif.f=1;
        }
        else
            Max=res;
        if(!(one<(Max-Min)))
        {
            LNI dif1=Max*Max-a;
            LNI dif2=Min*Min-a;
            dif1.f=1;
            dif2.f=1;
            if(dif1<dif2)
                return Max;
            else return Min;
        }
        res=(Max+Min)/2;
    }
    return res;
}

LNI operator/(LNI a,int n)
{
    LNI res=a;
    for(int i=0; i<res.n; ++i)
    {
        res.num[i+1]+=res.num[i]%n*10000;
        res.num[i]/=n;
    }
    if(res.num[0]==0)
    {
        for(int i=0; i<res.n-1; ++i)
            res.num[i]=res.num[i+1];
        res.n--;
    }
    return res;
}

/*
质因数分解
http://wenku.baidu.com/view/7433bcd9ad51f01dc281f153.html
*/
int main()
{
    freopen("in.txt","r",stdin);
    LNI n1,n2,res;
    int n;
    while(n1.read()!=EOF && n2.read()!=EOF) // && n2.read()!=EOF
    {
        res=n1+n2;
        res.print();
    }
    return 0;
}
