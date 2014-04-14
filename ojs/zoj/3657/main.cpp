#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5+3;
int mush[maxn];
int n;
int work()
{
    int res;
    if(n<4) return 1024;
    int sum=0;
    for(int i=0;i<n;i++)
            sum+=mush[i];
    if(n==4)
    {
        res=0;
        for(int i=0;i<3;i++)
            for(int j=i+1;j<4;j++)
            {
                if((mush[i]+mush[j])%1024>res)
                    res=(mush[i]+mush[j])%1024;
                if((mush[i]+mush[j])>0&&(mush[i]+mush[j])%1024==0)
                    return 1024;
            }
        for(int i=0;i<2;i++)
            for(int j=i+1;j<3;j++)
                for(int k=j+1;k<4;k++)
                {
                    if((mush[i]+mush[j]+mush[k])%1024==0)
                    {
                        return 1024;
                    }
                }
    }
    else
    {
        res=0;
        for(int i=0;i<3;i++)
            for(int j=i+1;j<4;j++)
                for(int k=j+1;k<5;k++)
                {
                    if((mush[i]+mush[j]+mush[k])%1024==0)
                    {
                        if((sum-mush[i]-mush[j]-mush[k])%1024>res)
                            res=(sum-mush[i]-mush[j]-mush[k])%1024;
                        if((sum-mush[i]-mush[j]-mush[k])>0&&(sum-mush[i]-mush[j]-mush[k])%1024==0)
                            return 1024;
                    }
                }
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&mush[i]);
        printf("%d\n",work());
    }
    return 0;
}
