#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=10000+100;
bool is[maxn];
int pri[maxn];
int sum[maxn];
int pn;

void pre()
{
    for(int i=2;i<maxn;i+=2)
        is[i]=1;
    pri[pn]=2;
    sum[pn++]=2;
    for(int i=3;i<maxn;i++)
    {
        if(!is[i])
        {
            pri[pn]=i;
            sum[pn]=sum[pn-1]+i;
            pn++;
            for(int j=i;j<maxn;j+=2*i)
                is[i]=1;
        }
        else is[i]=0;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
