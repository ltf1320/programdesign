#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N,K;


int main()
{
    scanf("%d%d",&K,&N);
    int s,t,r;
    int ss,res;
    int now;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d",&s,&t,&r);
        ss=s*t;
        res=K/ss;
        if(K%ss==0)
        {
            res=K/ss*(t+r)-r;
        }
        else
        {
            now=K%ss;
            res=K/ss*(t+r)+now/s;
            if(now%s)
                res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
