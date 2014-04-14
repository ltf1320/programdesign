#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int maxn=100000+100;
typedef long long LL;
int N,M;

multiset<int> st;

struct Grass
{
    int cost,green;
    bool operator<(const Grass &a)const
    {
        if(green==a.green)
            return cost>a.cost;
        return green>a.green;
    }
};
Grass nds[maxn];
Grass hs[maxn];


void work()
{
    int now=0;
    LL res=0;
    sort(nds,nds+N);
    sort(hs,hs+M);
    multiset<int>::iterator iter;
    for(int i=0;i<N;i++)
    {
        while(now<M&&hs[now].green>=nds[i].green)
        {
            st.insert(hs[now].cost);
            now++;
        }
        iter=st.lower_bound(nds[i].cost);
        if(iter==st.end())
        {
            printf("-1\n");
            return;
        }
        res+=*iter;
        st.erase(iter);
    }
    printf("%I64d\n",res);
}

void input()
{
    for(int i=0;i<N;i++)
        scanf("%d%d",&nds[i].cost,&nds[i].green);
    for(int i=0;i<M;i++)
        scanf("%d%d",&hs[i].cost,&hs[i].green);
}

void init()
{
    st.clear();
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
