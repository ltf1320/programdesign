#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=200+20;

int creverse(char* m)
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

struct LargeNum
{
    char num[maxn];
    int p;
    void print()
    {
        int l=strlen(num);
        if(p)
        {
            char t=num[l-p];
            num[l-p]=0;
            printf("%s.%c%s\n",num,t,&num[l-p+1]);
        }
        else
        {
            printf("%s\n",num);
        }
    }
    void read()
    {
        char itg[maxn],dec[maxn];
        if(scanf("%s.%s",itg,dec)==1)
            dec[0]=0;
        p=strlen(dec);
        strcpy(num,itg);
        strcat(num,dec);
    }
};

LargeNum operator*(LargeNum a,LargeNum b)
{
    LargeNum res;
    res.p=a.p+b.p;
    int la,lb;
    int jw;
    int i,j;
    la=creverse(a.num);
    lb=creverse(b.num);
    for(int i=0;i<la+lb;++i)
        res.num[i]='0';
    jw=0;
    for(i=0; i<la; ++i)
    {
        for(j=0; j<lb; ++j)
        {
            res.num[i+j]+=(a.num[i]-'0')*(b.num[j]-'0')+jw+'0';
            jw=(res.num[i+j]-'0')/10;
            res.num[i+j]=(res.num[i+j]-'0')%10+'0';
        }
    }
    if(jw)
    {
        res.num[la+lb-1]=jw+'0';
        res.num[la+lb]=0;
    }
    else res.num[la+lb-1]=0;
    int l=strlen(res.num);
    for(int i=l;i>=l-res.p;--i)
    {
        if(res.num[i]!='0')
        {
            res.num[i+1]=0;
            res.p-=l-i-1;
            break;
        }
    }
    creverse(res.num);
    return res;
}

int main()
{
    LargeNum a,b,res;
    a.read();
    b.read();
    res=a*b;
    res.print();
    return 0;
}
