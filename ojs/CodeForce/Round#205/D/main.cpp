#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000000+100;

char que[maxn];


int main()
{
    freopen("in.txt","r",stdin);
    gets(que);
    int gn=0;
    int maxdis=0;
    int kk=0,nowmm=0;
    for(int i=0; que[i]; i++)
    {
        if(que[i]=='F')
        {
            if(gn!=i)
                nowmm++;
            maxdis=max(maxdis,i-gn);
            gn++;
        }
        else
        {
            if(nowmm)
            {
                kk+=nowmm-1;
                nowmm=0;
            }
        }
    }
    if(nowmm)
    {
        kk+=nowmm-1;
        nowmm=0;
    }
    printf("%d\n",kk+maxdis);
    return 0;
}
