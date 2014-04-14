#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N;
int suma,sumb;
bool can;

int main()
{
    scanf("%d",&N);
    can=0;
    int a,b;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&a,&b);
        if((a+b)%2)
            can=1;
        suma+=a;
        sumb+=b;
    }
    if(suma%2==0&&sumb%2==0)
        printf("0\n");
    else if(suma%2==1&&sumb%2==1)
    {
        if(can)
            printf("1\n");
        else
            printf("-1\n");
    }
    else
        printf("-1\n");
    return 0;
}
