#include <iostream>
#include <cstdio>
#include <cstring>

#define p2(x) ((x)*(x))

using namespace std;
const int maxn=2000+100;
int N;
int num[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        int res=0;
        for(int i=0;i<N;i++)
            scanf("%d",&num[i]);
        int pre=0,pd=num[0],npd;
        for(int i=1;i<N;i++)
        {
            npd=max(pd,num[i]+i-pre);
            if(p2(npd)>p2(pd)+p2(num[i]))
            {
                res+=p2(pd);
                pd=num[i];
                pre=i;
            }
            else pd=npd;
        }
        res+=p2(pd);
        printf("%d\n",res);
    }
    return 0;
}
