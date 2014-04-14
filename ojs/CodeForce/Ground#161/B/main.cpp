#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=50+10;
int main()
{
    int N,K;
    int num[maxn];
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
        scanf("%d",&num[i]);
    sort(num,num+N);
    if(K>N) printf("-1\n");
    else
    {
        printf("%d %d\n",num[N-K],0);
    }
    return 0;
}
