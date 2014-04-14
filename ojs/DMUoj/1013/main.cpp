#include <cstdio>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    bool q=1;
    while(~scanf("%d",&n))
    {
        if(n==-1) break;
        if(!q) printf("\n");
        if(n==0)
        {
            printf("1");
            q=0;
            continue;
        }
        q=0;
        printf("5");
        for(int i=1;i<n;++i)
            printf("0");
        printf("5");
        for(int i=1;i<n;++i)
            printf("0");
    }
    return 0;
}
