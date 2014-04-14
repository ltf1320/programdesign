#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    int B=21,G=8,S=1;
    int n;
    printf("%d %d %d\n",G,B,S);
    for(int i=0;i<B;i++)
    {
        n=(int)((double)rand()/RAND_MAX*G)+1;
        printf("%d",n);
        for(int j=0;j<n;j++)
        {
            printf(" %d",(int)((double)rand()/RAND_MAX*G)+1);
        }
        puts("");
    }
    return 0;
}
