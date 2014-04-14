#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void print(int n)
{
    if(n>=5)
    {
        printf("-O|");
        n-=5;
    }
    else
        printf("O-|");
    for(int i=0;i<n;i++)
        putchar('O');
    putchar('-');
    for(int i=0;i<4-n;i++)
        putchar('O');
    puts("");
}


int main()
{
    int N;
    scanf("%d",&N);
    if(N==0)
        print(0);
    while(N)
    {
        print(N%10);
        N/=10;
    }
    return 0;
}
