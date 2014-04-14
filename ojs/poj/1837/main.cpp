/*
一个动态规划：背包的问题，借鉴了网上的经验才做出
首先应该考虑分阶段的问题，因为钩玛上的重物数量不同，而重物只能挂一次，则选每一次挂重物作为一个阶段考虑
其次是初始状态与最终状态的确定：
    最开始没有任何重物，所以天平是平衡的；
    最后的状态也是平衡的；
    而中间每次挂钩码的状态未知；
状态表示方法的确定：
    可以想到用一个数组来表示天平的状态，以数组中央为1表示初始时的平衡
    然后以此数组表示中间各个可以达到的状态的个数
    最后得到数组中央的值便得结果

状态转移方程:f[i][v]+=f[i-1][v+gouma[k]*zhong[i]]
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
    int C,G;
    int gouma[35],zhong[30];
    cin>>C>>G;
    for(int i=0;i<C;++i)
        cin>>gouma[i];
    for(int i=0;i<G;++i)
        cin>>zhong[i];
    int balance[30002],tem[30002];
    memset(balance,0,sizeof(balance));
    balance[15000]=1;
    for(int i=0;i<G;++i)
    {
        memcpy(tem,balance,sizeof(balance));
        memset(balance,0,sizeof(balance));
        for(int j=-5000;j<=5000;++j)
            for(int k=0;k<C;++k)
                balance[j+15000]+=tem[j+15000-zhong[i]*gouma[k]];
    }
    cout<<balance[15000]<<endl;
    return 0;
}

