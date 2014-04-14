#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=1100;
int N;
void p1()
{
    printf("NN");
    for(int i=0;i<N;i++)
        putchar('Y');
    puts("");
}

void p2()
{
    printf("YY");
    for(int i=0;i<N;i++)
        putchar('N');
    puts("");
}

int main()
{
    freopen("out.txt","w",stdout);
    scanf("%d",&N);
    printf("%d\n",N+2);
    p1();p1();
    for(int i=0;i<N;i++)
        p2();
    return 0;
}
