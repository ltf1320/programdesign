#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e4;
int ba[maxn][maxn];
int lowbit(int x)
{
    return x&(-x);
}
void update(int a,int b,int x)
{
    for(int i=a;i<=maxn;i+=lowbit(i))
    {
        for(int j=b;j<=maxn;j+=lowbit(j))
        {
            ba[i][j]+=x;
        }
    }
}
int getsum(int a,int b,int x)
{
    int sum=0;
    for(int i=a;i>0;i-=lowbit(i))
        for(int j=b;j>0;j-=lowbit(j))
    {
        sum+=ba[i][j];
    }
    return sum;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
