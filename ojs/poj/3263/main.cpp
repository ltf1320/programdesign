#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int maxn=10000+100;
int N,I,H,R;
set<pair<int,int> > st;
int res[maxn];


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d%d",&N,&I,&H,&R))
    {
        for(int i=1;i<=N;i++)
            res[i]=H;
        st.clear();
        int a,b;
        for(int i=0;i<R;i++)
        {
            scanf("%d%d",&a,&b);
            if(st.find(make_pair(a,b))==st.end())
            {
                st.insert(make_pair(a,b));
                for(int i=min(a,b)+1;i<max(a,b);i++)
                    res[i]--;
            }
        }
        for(int i=1;i<=N;i++)
            printf("%d\n",res[i]);
    }
    return 0;
}
