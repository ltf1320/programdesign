//先判断是dp，第一次开了两个1000000的数组，MLE了
//第二次开了一个，TLE了（地雷在1000000的时候）
//只开了一个10的一个3的数组，还是T了（同理）
//使用矩阵加速了，还是T(没有给num排序）
//排序了，还是T
//想到了数列递推公式，总是AC了...搞了半天不是dp是数学题..


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int num[11];


int main()
{
    freopen("in.txt","r",stdin);
    int n;
    double p;
    double res;
    while(~scanf("%d%lf",&n,&p))
    {
        res=1;
        num[0]=0;
        for(int i=1;i<=n;++i)
            scanf("%d",&num[i]);
        sort(num,num+n+1);
        for(int i=1;i<=n;++i)
            res=(1-p)*res*(1-pow(p-1,num[i]-num[i-1]-1))/(2-p);
        printf("%.7f\n",res);
    }
    return 0;
}
