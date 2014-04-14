#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
const int inf=0x3f3f3f3f;
int dp[maxn];
int ways[maxn];

struct EDGE
{
    int next,to;
};
int box[maxn];

queue<int> que;
int dis[maxn];
bool in[maxn];
int spfa(int s)
{
    memset(in,0,sizeof(in));
    for(int i=0;i<N;i++)
        dp[i]=inf;
    que.push(s);
    dis[s]=0;
    in[s]=1;
    int now,next;
    int res=0;
    bool flag;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        res=max(res,dis[now]);
        for(int i=0; i<mtn; i++)
        {
            flag=1;
            next=now;
            for(int j=0; j<4; j++)
            {
                if(now&(1<<mts[i].pt[j]))
                {
                    flag=0;
                    break;
                }
                next|=(1<<mts[i].pt[j]);
            }
            if(flag)
            {
                dis[next]=max(dis[next],dis[now]+4);
                if(!in[next])
                {
                    in[next]=1;
                    que.push(next);
                }
            }
        }
        in[now]=0;
    }
    return res;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
