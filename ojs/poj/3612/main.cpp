#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
const int maxh=100+10;

int N,C;
int height[maxn];

inline int mabs(int a)
{
    return a>0?a:-a;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&height[i]);
    }
    int res=0,dh;
    if(height[0]<height[1])
    {
        dh=min(height[0]+C/2,height[1]);
        res+=(height[0]-dh)*(height[0]-dh);
        height[0]=dh;
    }
    for(int i=1;i<N-1;i++)
    {
        if(height[i]<height[i-1]&&height[i]<height[i+1])
        {
            dh=min(height[i]+C,min(height[i-1],height[i+1]));
            res+=(height[i]-dh)*(height[i]-dh);
            height[i]=dh;
        }
    }
    if(height[N-1]<height[N-2])
    {
        dh=min(height[N-1]+C/2,height[N-2]);
        res+=(height[N-1]-dh)*(height[N-1]-dh);
        height[N-1]=dh;
    }
    for(int i=0;i<N-1;i++)
        res+=C*mabs(height[i]-height[i+1]);
    printf("%d\n",res);
    return 0;
}
