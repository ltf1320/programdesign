#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=80000+100;

int ans[maxn];

bool is[maxn];
int pri[maxn];
int prn;

void getpri()
{
    memset(is,0,sizeof(is));
    pri[prn++]=2;
    for(int i=2;i<maxn;i+=2)
        is[i]=1;
    for(int i=3;i<maxn;i++)
    {
        if(!is[i])
        {
            pri[prn++]=i;
            for(int j=i;j<maxn;j+=2*i)
                is[i]=1;
        }
        else is[i]=0;
    }
}


int find(int x)
{
    int res=0;

}

int main()
{
    getpri();
    int x;
    while(~scanf("%d",&x))
    {
        printf("%d\n",find(x));
    }
    return 0;
}
