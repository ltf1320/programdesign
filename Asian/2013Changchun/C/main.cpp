#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N;
int mush[10];
int sum;

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        sum=0;
        for(int i=0; i<N; i++)
        {
            scanf("%d",&mush[i]);
            sum+=mush[i];
        }
        if(N<=3)
        {
            printf("1024\n");
        }
        if(N==4)
        {
            bool flag=1;
            for(int i=0; i<4; i++)
            {
                if((sum-mush[i])%1024==0)
                {
                    flag=0;
                    printf("1024\n");
                    break;
                }
            }
            if(flag)
            {
                int now,res=0;
                for(int i=0; i<4; i++)
                    for(int j=i+1; j<4; j++)
                    {
                        now=mush[i]+mush[j];
                        while(now>1024)
                            now-=1024;
                        res=max(res,now);
                    }
                printf("%d\n",res);
            }
        }
        if(N==5)
        {
            int now,res=0;
            for(int i=0; i<5; i++)
                for(int j=i+1; j<5; j++)
                {
                    if((sum-mush[i]-mush[j])%1024)
                        continue;
                    now=mush[i]+mush[j];
                    while(now>1024)
                        now-=1024;
                    res=max(res,now);
                }
            printf("%d\n",res);
        }
    }
    return 0;
}
