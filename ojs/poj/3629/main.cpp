#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=100+10;
int N,K,P;
queue<int> que;
int ans[1000000+100];
int ansn;
int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&K,&P))
    {
        while(!que.empty()) que.pop();
        for(int i=1;i<=K;i++)
            que.push(i);
        ansn=K/N;
        for(int i=0;i<ansn;i++)
        {
            for(int j=1;j<N;j++)
            {
                que.pop();
                for(int k=0;k<P;k++)
                {
                    que.push(que.front());
                    que.pop();
                }
            }
            ans[i]=que.front();
            que.pop();
            for(int k=0;k<P;k++)
            {
                que.push(que.front());
                que.pop();
            }
        }
        sort(ans,ans+ansn);
        for(int i=0;i<ansn;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
