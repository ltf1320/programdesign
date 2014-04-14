#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+100;
int data[maxn];
int N;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(~scanf("%d",&N))
    {
        for(int i=0; i<N; i++)
            scanf("%d",&data[i]);
        sort(data,data+N);
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(data[N-i+j-1]<=data[j]*2)
                {
                    printf("%d\n",i);
                    return 0;
                }
            }
        }
    }
    return 0;
}
