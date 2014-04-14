/*
1 1
99999 1
0000000000001 0000000000002
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2000+100;
int a4[maxn/4];
int b4[maxn/4];
char tem[maxn];
int lena,lenb;

int read(int* a)
{
    if(scanf("%s",tem)==EOF) return -1;
    int l=strlen(tem);
    int len=l/4;
    int p=l%4;
    int k=-1;
    if(p)
    {
        len++;
        k++;
        a[k]=tem[0]-'0';
        for(int i=1; i<p; ++i)
        {
            a[k]=a[k]*10+tem[i]-'0';
        }
    }
    for(int i=p; i<l; ++i)
    {
        if(i%4==p)
        {
            k++;
            a[k]=tem[i]-'0';
        }
        else
        {
            a[k]=a[k]*10+tem[i]-'0';
        }
    }
    return len;
}

void cal()
{
    int t,m,ta,tb;
    m=max(lena,lenb);
    t=0;
    lena--;
    lenb--;
    for(int i=m-1; i>=0; --i,--lena,--lenb)
    {
        ta=lena<0?0:a4[lena];
        tb=lenb<0?0:b4[lenb];
        a4[i]=ta+tb+t;
        t=a4[i]/10000;
        a4[i]%=10000;
    }
    int z=1;
    if(t)
    {
        printf("1");
        printf("%04d",a4[0]);
    }
    else
    {
        for(z=0; z<m; ++z)
            if(a4[z]!=0)
                break;
        printf("%d",a4[z++]);
    }
    for(int i=z; i<m; ++i)
        printf("%04d",a4[i]);
    printf("\n");
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while((lena=read(a4))!=-1)
    {
        lenb=read(b4);
        cal();
    }
    return 0;
}
