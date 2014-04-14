#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=N+1;i<2*N;i++)
        printf("%d ",i);
    printf("%d\n",2*N);
    return 0;
}
