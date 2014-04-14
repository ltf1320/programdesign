#include <iostream>
#include <cstdio>
#include <cstring>
#include <algoritm>

using namespace std;
const int maxn=100000;

struct Node
{
    int h,c;
    bool operator<(const Node &a)
    {
        return h<a.h;
    }
};
Node nds[maxn];

void input()
{
    for(int i=0;i<N;i++)
    {
        nds[i].c=i;
        scanf("%d",&nds[i].h);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        scanf("%d%d",&N,&M);
        input();
        sort(nds,nds+N);
        printf("Case %d:\n",cas++);
        while(M--)
        {
            scanf("%d%d%d",&ql,&qr,&H);
            printf("%d\n",query(1,N,1));
        }
    }
    return 0;
}
