#include <iostream>
#include <cstdio>
using namespace std;
int N;
int main()
{
    int res,tmp;
    while(~scanf("%d",&N))
    {
        res=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&tmp);
            res+=tmp;
        }
        printf("%d\n",res);
    }
    return 0;
}
