#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    int N=2000;
    printf("%d\n",N);
    srand(time(0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<5;j++)
            printf("%d ",(int)((double)rand()/RAND_MAX*200)-100);
        puts("");
    }
    return 0;
}
