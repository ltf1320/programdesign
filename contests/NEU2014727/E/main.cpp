#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=5000;

LL jc[maxn];


int main()
{
    jc[0]=1;
    for(int i=1;i<maxn;i++)
        jc[i]=jc[i-1]*i;
    int T;
    scanf("%d",&T);
    int n;
    while(T--)
    {
        scanf("%d",&n);
        cout<<jc[n]<<endl;
    }
    return 0;
}
