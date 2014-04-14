#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=80000+10;
int st[maxn];
int p;
int N;

int main()
{
    freopen("in.txt","r",stdin);
    int tmp;
    LL res;
    while(~scanf("%d",&N))
    {
        p=0;
        res=0;
        scanf("%d",&tmp);
        st[p++]=tmp;
        for(int i=1; i<N; i++)
        {
            scanf("%d",&tmp);
            while(p>0&&st[p-1]<=tmp)
                p--;
            res+=p;
            st[p++]=tmp;
        }
        cout<<res<<endl;
    }
    return 0;
}
