#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int n,t1,t2,v,sum;
    while(~scanf("%d",&n))
    {
        if(n==-1) break;
        t1=sum=0;
        while(n--)
        {
            scanf("%d%d",&v,&t2);
            sum+=v*(t2-t1);
            t1=t2;
        }
        printf("%d miles\n",sum);
    }
    return 0;
}
