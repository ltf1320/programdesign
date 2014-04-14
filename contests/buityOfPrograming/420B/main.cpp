#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50+10;

int dp[2][maxn*maxn][maxn][maxn];
struct PEO
{
    int c1,c2,q1,q2;
    void read()
    {
        scanf("%d%d%d%d",&q1,&c1,&q2,&c2);
    }
};
PEO peo[maxn];

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
