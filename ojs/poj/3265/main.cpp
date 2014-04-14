#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=300+10;
int P,M;

struct Problem
{
    int now,next;
};
Problem prs[maxn];
int day;

int main()
{
    freopen("in.txt","r",stdin);
    int nowleft,nextleft;
    while(~scanf("%d%d",&M,&P))
    {
        for(int i=0;i<P;i++)
            scanf("%d%d",&prs[i].now,&prs[i].next);
        day=2;
        nowleft=nextleft=M;
        for(int i=0;i<P;)
        {
            if(nowleft>=prs[i].now&&nextleft>=prs[i].next)
            {
                nowleft-=prs[i].now;
                nextleft-=prs[i].next;
                i++;
            }
            else
            {
                day++;
                nowleft=nextleft;
                nextleft=M;
            }
        }
        if(nextleft!=M) day++;
        printf("%d\n",day);
    }

    return 0;
}
