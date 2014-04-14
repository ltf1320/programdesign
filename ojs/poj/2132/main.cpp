#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn=25+10;
int N;
int map[maxn][maxn];

int gcd(LL a,LL b)
{
    LL t;
    while(b)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}

LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}
struct FSO
{
    FSO(int g,int n,int f):gcd(g),now(n),from(f){}
    FSO(){}
    int gcd;
    int now,from;
};

queue<FSO> que;
LL lcms[maxn];

void work()
{
    FSO now;
    LL res=1;
    for(int i=2;i<=N;i++)
        if(map[1][i])
        {
            que.push(FSO(map[1][i],i,1));
        }
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(gcd(now.gcd,lcms[now.now])==now.gcd) continue;
        if(gcd(res,now.gcd)==now.gcd) continue;
        if(now.now==2)
        {
            res=lcm(res,now.gcd);
            continue;
        }
        for(int i=1;i<=N;i++)
        {
            if(i==now.from) continue;
            if(map[now.now][i])
            {
                que.push(FSO(gcd(now.gcd,map[now.now][i]),i,now.now));
            }
        }
        lcms[now.now]=lcm(lcms[now.now],now.gcd);
    }
    printf("%I64d\n",res);
}

void input()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            scanf("%d",&map[i][j]);
}

void init()
{
    while(!que.empty()) que.pop();
    for(int i=1;i<=N;i++)
        lcms[i]=1;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        init();
        input();
        work();
    }
    return 0;
}
