#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
    LL N;
    LL tmp;
    LL res;
    while(cin>>N)
    {
        if(N==0) break;
        res=0;
        while(N--)
        {
            cin>>tmp;
            res+=tmp*tmp;
        }
        cout<<res<<endl;
    }
    return 0;
}
