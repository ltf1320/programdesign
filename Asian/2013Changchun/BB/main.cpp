#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=500;
int a[maxn+10]={1,2,314};
int main()
{
    freopen("out.txt","w",stdout);
    int N=500;
    printf("%d\n",N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j)
                printf("0 ");
            else if(i%2==1&&j%2==1)
                printf("%d ",a[i]|a[j]);
            else if(i%2==0&&j%2==0)
                printf("%d ",a[i]&a[j]);
            else printf("%d ",a[i]^a[j]);
        }
        puts("");
    }
    return 0;
}
