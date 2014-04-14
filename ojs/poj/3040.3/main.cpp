#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=20+10;
const int inf=0x3f3f3f3f;
int N,C;
LL res;
struct DEM
{
    int v,b;
    bool operator<(const DEM &a)const
    {
        return v>a.v;
    }
};
DEM des[maxn];
int use[maxn];
void work()
{
    res=0;
    sort(des,des+N);
    int last,minc;
    bool flag;
    while(true)
    {
        last=C;
        for(int i=0;i<N;i++)
        {
            if(last==0) break;
            use[i]=min(des[i].b,last/des[i].v);
            last-=use[i]*des[i].v;
        }
        if(last==0)
        {
            minc=inf;
            for(int i=0;i<N;i++)
                if(use[i])
                    minc=min(minc,des[i].b/use[i]);
            for(int i=0;i<N;i++)
                if(use[i])
                    des[i].b-=use[i]*minc;
            res+=minc;
        }
        else
        {
            flag=0;
            for(int i=N-1;i>=0;i--)
            {
                if(des[i].b-use[i]>=last/des[i].v+1)
                {
                    flag=1;
                    use[i]+=last/des[i].v+1;
                    break;
                }
                else
                {
                    use[i]+=des[i].b-use[i];
                }
            }
            if(!flag) break;
            minc=inf;
            for(int i=0;i<N;i++)
                if(use[i])
                    minc=min(minc,des[i].b/use[i]);
            for(int i=0;i<N;i++)
                des[i].b-=use[i]*minc;
            res+=minc;
        }
    }
    printf("%I64d\n",res);
}

void input()
{
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&des[i].v,&des[i].b);
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&C))
    {
        input();
        work();
    }
    return 0;
}


