#include <stdio.h>
#include <stdint.h>
#include <string.h>
const int MOD=95041567;
uint64_t bl[10000];
int vis[MOD+1];
/*该函数是用来计算组合函数的即 n! / (m! * (n-m)!)*/

uint64_t combine(int n,int m)
{
    int i = 0;
    uint64_t a = 1,b = 1,k = 1;

    if (m > n / 2)
          m = n - m;

   /*get (n - m)! */
    for (i = n - m;i > 1;i--) {
        a *= i;
    }

  /* get n! */
    for (i = n;i > 1;i--) {
        b *= i;
    }

    /* get m! */
    for (i = m;i > 1;i--) {
        k *= i;
    }

    return b / (k * a);
}

uint64_t bell(int n)
{
    uint64_t t = 0;
    int i;

    if (n == 0)
        t=1;
    else {
        for (i = 0;i <= n-1;i++) {
        t += combine(n-1,i) * bl[i];
        }
    }
    bl[n]=t%MOD;
    return bl[n];
}

int main(void)
{
    int n = 0;
//    while (scanf("%d",&n) != EOF) {
    memset(vis,-1,sizeof(vis));
        for(n=0;n<100;n++)
        {
            uint64_t ans=bell(n);
            if(vis[ans]!=-1)
            {
                printf("%d %d\n",vis[ans],n);
            }
            vis[ans]=n;
//            printf("bell(%d) = %I64d\n",n,ans);
        }
//    }
}
