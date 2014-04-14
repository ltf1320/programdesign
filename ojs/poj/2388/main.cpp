#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=10000+100;
int ss[maxn];



int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&ss[i]);
    sort(ss,ss+n);
    printf("%d\n",ss[n/2]);
    return 0;
}
