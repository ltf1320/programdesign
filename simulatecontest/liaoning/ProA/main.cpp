#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int err=1E-7;
int main()
{
    long long n;
    float b,s;
    bool Y;
    while(~scanf("%I64d",&n))
    {
        Y=0;
        s=sqrt(n);
        for(int i=0;i<=s;++i)
        {
            b=sqrt(static_cast<float>(n)-i*i);
            if((b+err)>=floor(b) && (b-err)<=floor(b))
            {
                Y=1;
                break;
            }
        }
        if(Y) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
