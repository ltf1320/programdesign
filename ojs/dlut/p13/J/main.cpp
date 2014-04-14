#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10;

int num[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int res;
    int cas=0;
    while(T--)
    {
        cas++;
        for(int i=0;i<9;i++)
            scanf("%d",&num[i]);
        sort(num,num+9);
        res=0;
        for(int i=0;i<3;i++)
            res+=num[i]*5;
        res+=num[3]*6;
        for(int i=4;i<8;i++)
            res+=num[i]*7;
        res+=num[8]*8;
        printf("Test #%d\n",cas);
        printf("%d\n\n",res);
    }
    return 0;
}
