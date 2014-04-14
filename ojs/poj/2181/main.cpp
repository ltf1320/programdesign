#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int last,now;
int main()
{
    freopen("in.txt","r",stdin);
    int res,nres;
    int P,i;
    bool flag;
    while(~scanf("%d",&P))
    {
        scanf("%d",&last);
        nres=last;
        res=0;
        i=1;
        flag=0;
        while(i<P)
        {
            scanf("%d",&now);
            i++;
            if(flag==0)
            {
                if(now<last)
                {
                    res+=last;
                    flag=1;
                }
            }
            else
            {
                if(now>last)
                {
                    res-=last;
                    flag=0;
                }
            }
            last=now;
            nres=max(nres,res);
        }
        if(flag==0)
        {
            res+=last;
            nres=max(nres,res);
        }
        printf("%d\n",nres);
    }
    return 0;
}
