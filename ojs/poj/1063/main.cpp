#include <iostream>
#include<cstdio>
using namespace std;

const int maxn=40;

int main()
{
    freopen("in.txt","r",stdin);
    int T,N;
    int num[maxn];
    int hn;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        hn=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&num[i]);
            if(num[i]) hn++;
        }
        if(N%2) printf("YES\n");
        else
        {
            for(int i=2;i<N;i++)
                if(num[i])
                {
                    int k=i;
                    while(!num[k-2]&&k>=2)
                    {
                        num[k-2]=1;
                        num[k]=0;
                        k=k-2;
                    }
                }
            for(int i=0;i<hn;i++)
            {
                if(!num[i])
                {
                    printf("NO\n");
                    break;
                }
                if(i==hn-1)
                {
                    printf("YES\n");
                }
            }
        }
    }
    return 0;
}
