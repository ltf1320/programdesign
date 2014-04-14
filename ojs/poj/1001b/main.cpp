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

struct LargeNum
{
    int num[maxn];
    int n;
    int xp;   //小数点在倒数第几位
    int read()
    {
        memset(num,0,sizeof(num));
        char *tem,*tmm,tem2[maxn];
        tem=new char[maxn];
        tmm=tem;
        tem2[0]=0;
//        if(scanf("%s.%s",tem,tem2)==EOF) return EOF;
        char ch,*z=tem;
        while(1)
        {
            if(scanf("%c",&ch)==EOF) return -1;
            if(ch=='\n' || ch==' ') break;
            if(ch!='.')
                *z++=ch;
            else
            {
                *z=0;
                z=tem2;
            }
        }
        *z=0;
        xp=strlen(tem2);
        strcat(tem,tem2);
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
        rem0();
        return 0;
    }
    void print()
    {
        int i=0,k;
        if(n==1 && num[0]==0)
        {
            printf("0\n");
            return;
        }
        if(xp==0)
        {
            printf("%d",num[i++]);
            for(; i<n; ++i)
                printf("%04d",num[i]);
        }
        else
        {
            if((n-xp/4-1)>0)
            {
                printf("%d",num[i++]);
                for(; i<n-xp/4-1; ++i)
                    printf("%04d",num[i]);
                k=1;
                for(int j=0; j<xp%4; ++j)
                    k*=10;
                char pstr[10]="%0 d";
                pstr[2]=4-xp%4+'0';
                printf(pstr,num[i]/k);
                if(i<n-1)
                {
                    char pstr[10]=".%0 d";
                    if(xp%4)
                    {
                        pstr[3]=xp%4+'0';
                        printf(pstr,num[i]%k);
                    }
                    else putchar('.');
                    i++;
                    k=1000;
                }
                else
                {
                    k/=10;
                    if(i==n-1)
                    {
                        if(num[i]%(k*10)==0)
                        {
                            putchar('\n');
                            return;
                        }
                        putchar('.');
                    }
                }
                for(; i<n-1; ++i)
                    printf("%04d",num[i]);
                while(k)
                {
                    if(num[i]%k)
                    {
                        printf("%d",(num[i]/k)%10);
                        k/=10;
                    }
                    else
                    {
                        printf("%d",(num[i]/k)%10);
                        break;
                    }
                }
            }
            else if((n-xp/4-1)==0)
            {
                k=1;
                for(int j=0; j<xp%4; ++j)
                    k*=10;
                if(num[i]/k!=0)
                    printf("%d",num[i]/k);
                if(i<n-1)
                {
                    char pstr[10]=".%0 d";
                    if(xp%4)
                    {
                        pstr[3]=xp%4+'0';
                        printf(pstr,num[i]%k);
                    }
                    else putchar('.');
                    i++;
                    k=1000;
                }
                else
                {
                    k/=10;
                    if(i==n-1)
                    {
                        if(num[i]%(k*10)==0)
                        {
                            putchar('\n');
                            return;
                        }
                        putchar('.');
                    }
                }
                for(; i<n-1; ++i)
                    printf("%04d",num[i]);
                while(k)
                {
                    if(num[i]%k)
                    {
                        printf("%d",(num[i]/k)%10);
                        k/=10;
                    }
                    else
                    {
                        printf("%d",(num[i]/k)%10);
                        break;
                    }
                }
            }
            else
            {
                putchar('.');
                for(int j=0; j<xp-4*n; ++j)
                    putchar('0');
                for(; i<n-1; ++i)
                    printf("%04d",num[i]);
                k=1000;
                while(k)
                {
                    if(num[i]%k)
                    {
                        printf("%d",(num[i]/k)%10);
                        k/=10;
                    }
                    else
                    {
                        printf("%d",(num[i]/k)%10);
                        break;
                    }
                }
            }
        }
        putchar('\n');
    }
    void rem0()
    {
        while(xp>4)
        {
            if(num[n-1]==0)
            {
                n--;
                xp-=4;
            }
            else break;
        }
    }
};

LargeNum operator*(LargeNum a,LargeNum b)
{
    LargeNum res;
    res.xp=a.xp+b.xp;
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
    int n=a.n+b.n-1;;
    while(res.num[n++]);
    res.n=n-1;
    rev(res.num,res.n);
    res.rem0();
    return res;
}

LargeNum operator^(LargeNum a,int n)
{
    LargeNum res;
    res.xp=0;
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
    LargeNum n1,n2,res;
    int n;
    freopen("in.txt","r",stdin);
    while(n1.read()!=EOF && scanf("%d",&n)!=EOF)
    {
        getchar();
        res=n1^n;
        res.print();
    }
    return 0;
}
