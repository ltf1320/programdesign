#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=50000+100;
int N;
struct Node
{
    int x,y;
};

int fabs(int a)
{
    return a>0?a:-a;
}

bool cmp1(const Node &a,const Node &b)
{
    if(a.x==b.x)
        return a.y>b.y;
    return a.x<b.x;
}
bool cmp2(const Node &a,const Node &b)
{
    if(a.x==b.x)
        return a.y>b.y;
    return a.x>b.x;
}

Node nds[maxn];

int main()
{

    Node s1,s2,k1,k2;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d%d",&nds[i].x,&nds[i].y);\
    sort(nds,nds+N,cmp1);
    s1=nds[0];
    k2=nds[N-1];
    sort(nds,nds+N,cmp2);
    k1=nds[0];
    s2=nds[N-1];
    printf("%d\n",max(fabs(s1.x-k2.x)+fabs(s1.y-k2.y),fabs(s2.x-k1.x)+fabs(s2.y-k1.y)));
    return 0;
}
