#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000000+100;

char que[maxn];

inline int mabs(int a)
{
    return a>0?a:-a;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    gets(que);
    int gn=0;
    int maxdis=0;
    int kk=0,nf=0,nm=0;
    int maxnf=1;
    for(int i=0; que[i]; i++)
    {
        if(que[i]=='F')
        {
            if(gn!=i)
            {
                nf++;
                maxdis=max(maxdis,i-gn);
            }
            gn++;
        }
        else
        {
            if(nf)
            {
                maxnf=max(maxnf,nf);
                kk+=mabs(nf-nm);
                nf=0;
                nm=0;
            }
            nm++;
        }
    }
    maxnf=max(maxnf,nf);
    printf("%d\n",kk+maxdis+maxnf-1);
    return 0;
}
