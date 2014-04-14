#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
int num[2]; //0 for 25 ,1 for 50
int N;
int main()
{
    scanf("%d",&N);
    int now;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&now);
        if(now==25)
        {
            num[0]++;
        }
        else if(now==50)
        {
            if(num[0])
            {
                num[1]++;
                num[0]--;
            }
            else
            {
                printf("NO\n");
                return 0;
            }
        }
        else
        {
            if(num[1])
            {
                now-=50;
                num[1]--;
            }
            if(now!=0)
            {
                if(now/25-1<=num[0])
                {
                    num[0]-=now/25-1;
                }
                else
                {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");
    return 0;
}
