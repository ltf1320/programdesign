#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXX = 500010;


int n, k, queue[MAXX];
__int64 sum[MAXX], f[MAXX], a[MAXX];

__int64 dy(int j1, int j2)
{
    return  (f[j1]-sum[j1]+a[j1+1]*j1) - (f[j2]-sum[j2]+a[j2+1]*j2);
}

__int64 dx(int j1, int j2)
{
    return  (a[j1+1] - a[j2+1]);
}

void dp()
{
    int i, j, head, tail, x, y, z;
    head = tail = 0;
    queue[0] = 0;
    for(i = 1; i <= n; i++)
    {
        while(head<tail && dy(queue[head], queue[head+1])>=i*dx(queue[head], queue[head+1]))
            head++;
        j = queue[head];
        f[i] = f[j] + sum[i] - sum[j] - a[j+1]*(i-j);
        if(i >= 2*k-1)    //实际上是i-k+1>=k
        {
            z = i-k+1;
            while(head < tail)
            {
                x = queue[tail-1];
                y = queue[tail];
                if(dy(x,y)*dx(y,z) >= dy(y,z)*dx(x,y))  tail--;
                else  break;
            }
            queue[++tail] = z;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int t, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        sum[0] = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%I64d", a+i);
            sum[i] = sum[i-1] + a[i];
        }
        dp();
        printf("%I64d\n", f[n]);
    }
    return 0;
}
