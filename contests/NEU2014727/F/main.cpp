#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int judge(int v)
{
    int res=0;
    while(v)
    {
        res++;
        v>>=1;
    }
    return  res;
}

int main()
{
    int n;
    scanf("%d",&n);
    int x,y,xn,yn,res;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        if(x<y)
        {
            x^=y;
            y^=x;
            x^=y;
        }
        xn=judge(x);
        yn=judge(y);
        res=0;
        for(int j=yn;j<xn;j++)
        {
            res++;
            x=x/2;
        }
        while(x!=y)
        {
            res+=2;
            x/=2;
            y/=2;
        }
        printf("%d\n",res);
    }
    return 0;
}
