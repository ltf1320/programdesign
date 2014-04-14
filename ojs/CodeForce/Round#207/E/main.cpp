#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N;
int num[5];
int main()
{
    int t;
    scanf("%d",&N);
    for(int i=0; i<N; i++)
    {
        scanf("%d",&t);
        num[t]++;
    }
    int res=0;
    t=min(num[1],num[2]);
    num[1]-=t;
    num[2]-=t;
    num[3]+=t;
    res+=t;
    if(num[2])
    {
        t=num[2]/3;
        num[2]=num[2]%3;
        num[3]+=2*t;
        res+=2*t;

        if(num[2]==2)
        {
            res+=2;
            num[4]+=1;
            num[2]=0;
        }
        else if(num[2]==1)
        {
            if(num[4])
            {
                num[4]-=1;
                res+=1;
                num[2]=0;
            }
            else if(num[3]>=2)
            {
                res+=2;
                num[3]-=2;
                num[4]+=2;
                num[2]=0;
            }
            else
            {
                res=-1;
            }
        }
    }
    else if(num[1])
    {
        t=num[1]/3;
        num[1]=num[1]%3;
        num[3]+=t;
        res+=2*t;

        if(num[1]==2)
        {
            if(num[3]>=2)
            {
                num[4]+=2;
                num[3]-=2;
                num[1]=0;
                res+=2;
            }
            else if(num[4])
            {
                num[3]+=2;
                num[4]--;
                num[1]=0;
                res+=2;
            }
            else
            {
                res=-1;
            }
        }
        else if(num[1]==1)
        {
            if(num[3])
            {
                num[3]--;
                num[4]++;
                num[1]=0;
                res+=1;
            }
            else if(num[4]>=2)
            {
                res+=2;
                num[4]-=2;
                num[3]+=3;
                num[1]=0;
            }
            else res=-1;
        }
    }
    printf("%d\n",res);
    return 0;
}
