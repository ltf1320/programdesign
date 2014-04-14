#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=3000;

int rev(char* m)
{
    int l=strlen(m);
    char t;
    for(int i=0; i<l; ++i)
    {
        t=m[i];
        m[i]=m[l-i-1];
        m[l-i-1]=t;
    }
    return l;
}

void rev(int* m,int l)
{
    l=(l-1)/4+1;
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
    int l;
    int read()
    {
        memset(num,0,sizeof(num));
        char *tem,*tmm;
        tem=new char[maxn];
        tmm=tem;
        if(scanf("%s",tem)==EOF) return EOF;
        while(*tem=='0')
            tem++;
        l=strlen(tem);
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
        return 0;
    }
    void print()
    {
        int i=0;
        printf("%d",num[i++]);
        for(; i<=(l-1)/4; ++i)     //需要整数的个数应该是(l-1)/4
            printf("%04d",num[i]);
        printf("\n");
    }
};

LNI operator+(LNI a,LNI b)
{
    LNI res;
    rev(a.num,a.l);
    rev(b.num,b.l);
    memset(res.num,0,sizeof(res.num));
    int jw=0;
    int k=max((a.l-1)/4,(b.l-1)/4);
    res.l=max(a.l,b.l);
    for(int i=0;i<=k;++i)
    {
        if(i<=(a.l-1)/4 && i<=(b.l-1)/4)
        {
            res.num[i]=a.num[i]+b.num[i]+jw;
            jw=res.num[i]/10000;
            res.num[i]%=10000;
        }
        else if(i>(a.l-1)/4)
        {
            res.num[i]=b.num[i]+jw;
            jw=res.num[i]/10000;
            res.num[i]%=10000;
        }
        else if(i>(b.l-1)/4)
        {
            res.num[i]=a.num[i]+jw;
            jw=res.num[i]/10000;
            res.num[i]%=10000;
        }
    }
    if(jw)
    {
        if(res.l%4==0)
        {
            res.num[k+1]=jw;
        }
        else
        {
            int k=1;
            for(int i=0;i<k%4;++i)
                k*=10;
            res.num[k-1]+=jw*k;
        }
        res.l++;
    }
    rev(res.num,res.l);
    return res;
}

LNI operator*(LNI a,LNI b)
{
    LNI res;
    rev(a.num,a.l);
    rev(b.num,b.l);
    memset(res.num,0,sizeof(res.num));
    int jw,k;
    res.l=a.l+b.l-1;
    for(int i=0;i<=(a.l-1)/4;++i)
    {
        for(int j=0;j<=(b.l-1)/4;++j)
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
    if(res.num[(res.l-1)/4])
    {

    }
}

int main()
{
    LNI n1,n2,res;
    while(n1.read()!=EOF && n2.read()!=EOF)
    {
        res=n1+n2;
        res.print();
    }
    return 0;
}
