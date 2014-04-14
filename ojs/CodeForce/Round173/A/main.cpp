#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int N;
    char s[5];
    int res;
    while(~scanf("%d",&N))
    {
        res=0;
        while(N--)
        {
            scanf("%s",s);
            if(s[1]=='-')
                res--;
            else res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
