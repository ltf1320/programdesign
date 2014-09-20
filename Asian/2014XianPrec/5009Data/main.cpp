#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    int N=50000;
    printf("%d\n",N);
    for(int i=0;i<N;i++)
        printf("%d ",(int)((double)rand()/RAND_MAX*1E9));
    return 0;
}
