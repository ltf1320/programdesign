#include <cstdio>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int s,d;
    int in;
    while(~scanf("%d%d",&s,&d))
    {
        if(4*s-d<0)
            in=10*s-2*d;
        else if(3*s-2*d<0)
            in=8*s-4*d;
        else if(2*s-3*d<0)
            in=6*s-6*d;
        else if(s-4*d<0)
            in=3*s-9*d;
        else
            in=-1;
        if(in>0)
        {
            printf("%d\n",in);
        }
        else printf("Deficit\n");
    }
    return 0;
}
