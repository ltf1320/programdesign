#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    srand(time(0));
    int N,M,K;

    for(int p=0;p<100;p++)
    {
        N=(int)((double)rand()/RAND_MAX*1000)+1;
        M=(int)((double)rand()/RAND_MAX*1000)+1;
        K=(int)((double)rand()/RAND_MAX*100)+1;
        printf("%d %d %d\n",N,M,K);
    }
    /*
    for(int m=1;m<=100;m++)
        for(int n=1;n<=100;n++)
            for(int k=1;k<=10;k++)
            {
                printf("%d %d %d\n",n,m,k);
            }
    */
    return 0;
}
