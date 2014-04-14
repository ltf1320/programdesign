#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=300;

char le[maxn],ri[maxn];
int llen,rlen;
int tlen;
char tmp[maxn];

int main()
{
    gets(tmp);
    int i=0,j=0;
    for(;tmp[i]!='|';i++)
    {
        le[llen++]=tmp[i];
    }
    for(i++;tmp[i];i++)
    {
        ri[rlen++]=tmp[i];
    }
    gets(tmp);
    tlen=strlen(tmp);
    int sum=tlen+llen+rlen;
    if(sum%2==0&&llen*2<=sum&&rlen*2<=sum)
    {
        int kk=sum/2-llen;
        printf("%s",le);
        for(j=0;j<kk;j++)
            putchar(tmp[j]);
        putchar('|');
        printf("%s",ri);
        for(;j<tlen;j++)
            putchar(tmp[j]);
        puts("");
    }
    else
        puts("Impossible");
    return 0;
}
