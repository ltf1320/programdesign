#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <ctype.h>
typedef long long LL;
using namespace std;
const double eps = 1e-6;
const double sqr2 = sqrt(2.0);
int n;
double mea;
bool ok(int m)
{
    if(sqr2*m-eps<mea) return true;
    return false;
}
int main()
{

    cin >> n;
    if(n==1)
    {
        puts("4");
        return 0;
    }
    if(n==0)
    {
        puts("1");
        return 0;
    }
    int l = n/sqr2;
    if(sqrt((double)l*l+(double)(l+1)*(l+1))-eps<n)
    {
        cout<<(LL)l*8+4<<endl;
    }
    else
    {
        l--;//cout<<l<<endl;
        cout<<(LL)l*8+8<<endl;
    }
    return 0;
}
