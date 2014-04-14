#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
const int MOD=95041567;


/*该函数是用来计算组合函数的即 n! / (m! * (n-m)!)*/

double lnchoose(int n, int m)
{
    if (m > n)
    {
        return 0;
    }
    if (m < n/2.0)
    {
        m = n-m;
    }
    double s1 = 0;
    for (int i=m+1; i<=n; i++)
    {
        s1 += log((double)i);
    }
    double s2 = 0;
    int ub = n-m;
    for (int i=2; i<=ub; i++)
    {
        s2 += log((double)i);
    }
    return s1-s2;
}

double combine(int n, int m)
{
    if (m > n)
    {
        return 0;
    }
    return exp(lnchoose(n, m));
}


int bell(int n)
{
    uint64_t t = 0;
    int i;

    if (n == 0)
        t=1;
    else
    {
        for (i = 0; i <= n-1; i++)
        {
            t += round(combine(n-1,i) * bell(i));
        }
    }
    return t%MOD;
}

int main(void)
{
    int n = 0;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        int ans=bell(n);
        printf("%d\n",ans);
    }
}
