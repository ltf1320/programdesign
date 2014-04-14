#include <iostream>
#include <cstdio>
using namespace std;

int abs(int a)
{
    return a>0?a:-a;
}

int main()
{
    int T;
    int N,A,B,k,ka,kb,ma,mb;
    int cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        scanf("%d%d%d",&N,&A,&B);
        if(N%2)
        {
            k=N/2+1;
            ka=A/k;
            kb=B/k;
            ma=A%k;
            mb=B%k;
            if(kb>ka+1)
                printf("Case #%d: -1\n",cas);
            else if(ka+1>kb)
                printf("Case #%d: 1\n",cas);
            else
            {
                if(ma>mb)   printf("Case #%d: 1\n",cas);
                else printf("Case #%d: -1\n",cas);
            }
        }
        else
        {
            k=N/2;
            if(A>=B)
            {
                if(A>=2*B) printf("Case #%d: 1\n",cas);
                else printf("Case #%d: 0\n",cas);
            }
            else
            {
                if(B>2*A) printf("Case #%d: -1\n",cas);
                else printf("Case #%d: 0\n",cas);
            }
        }
    }
    return 0;
}
