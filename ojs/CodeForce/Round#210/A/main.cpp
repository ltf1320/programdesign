#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;



int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(j)
                putchar(' ');
            if(i==j)
                printf("%d",K);
            else printf("%d",0);
        }
        puts("");
    }
    return 0;
}
