#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=20;
char isbn[maxn];


int main()
{
    freopen("in.txt","r",stdin);
    int sum,kn,mod;
    int res;
    while(~scanf("%s",isbn))
    {
        sum=0;
        for(int i=0;i<10;i++)
        {
            if(isbn[i]=='?')
            {
                kn=i;
            }
            else if(isbn[i]=='X')
            {
                sum+=(10-i)*10;
            }
            else sum+=(10-i)*(isbn[i]-'0');
        }
        mod=11-(sum%11);
        if(mod==11) mod=0;
        for(int i=0;i<=10;i++)
        {
            if((i*(10-kn))%11==mod)
            {
                res=i;
                break;
            }
        }
        if(res>10) printf("-1\n");
        else if(res==10)
        {
            if(kn==9)
                printf("X\n");
            else printf("-1\n");
        }
        else printf("%d\n",res);
    }
    return 0;
}
