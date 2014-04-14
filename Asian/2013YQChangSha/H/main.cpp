#include <stdio.h>
int N,M;
int main()
{
    while(~scanf("%d%d",&M,&N))
    {
        printf("%d\n",(2*M-N/2+1)*(N/2)+M-N/2);
    }
    return 0;
}
