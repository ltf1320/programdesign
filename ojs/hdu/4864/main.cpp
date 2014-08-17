#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn=100000+100;
int N,M;
struct Node
{
    int x,y;
    bool operator<(const Node &a)const
    {
        if(x==a.x)
            return y>a.y;
        else return x>a.x;
    }
};
multiset<int> mc[110];
Node ts[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    LL  res,cnt;
    while(~scanf("%d%d",&N,&M))
    {
        for(int i=0;i<=100;i++)
            mc[i].clear();
        cnt=res=0;
        Node tn;
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&tn.x,&tn.y);
            mc[tn.y].insert(tn.x);
        }
        for(int i=0;i<M;i++)
        {
            scanf("%d%d",&tn.x,&tn.y);
            ts[i]=tn;
        }
        sort(ts,ts+M);
        for(int i=0;i<M;i++)
        {
            for(int y=ts[i].y;y<=100;y++)
            {
                set<int>::iterator iter= mc[y].lower_bound(ts[i].x);
                if(iter!=mc[y].end())
                {
                    res+=ts[i].x*500+ts[i].y*2;
                    cnt++;
            //        cout<<*iter<<" "<<y<<endl;
            //        cout<<ts[i].x<<" "<<ts[i].y<<endl<<endl;
                    mc[y].erase(iter);
                    break;
                }
            }
        }
        cout<<cnt<<" "<<res<<endl;
    }
    return 0;
}
