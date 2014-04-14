#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+10;
int N;
double res[maxn];

void pre()
{
    res[1]=1.0/2;
    for(int i=2;i<100000;i++)
    {
        res[i]=res[i-1]+1.0/(2*i);
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    pre();
    printf("# Cards Overhang\n");
    while(~scanf("%d",&N))
    {
        printf("%5d     %.3f\n",N,res[N]);
    }
    return 0;
}
