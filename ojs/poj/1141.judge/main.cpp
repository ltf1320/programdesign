#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=110;



int main()
{
    char in[maxn];
    int p,len,i;
    char out[maxn];
    FILE *inF,*outF;
    inF=fopen("data.in","r");
    outF=fopen("data.out","r");
    int d=0;
    while(~fscanf(inF,"%s",in))
    {
        fscanf(outF,"%s",out);
        p=0;
        len=strlen(in);
        i=0;
        while(out[i])
        {
            if(out[i]==in[p]) p++;
            i++;
        }
        if(p<len)
            printf("%d",d);
        d++;
    }
    return 0;
}
