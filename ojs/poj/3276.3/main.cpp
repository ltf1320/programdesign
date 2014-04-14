#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=5000+100;
const int inf=0x3f3f3f3f;
int N;
bool ori[maxn]; //1 for B,0 for forward

int resk,resm;

queue<int> que;
void judge(int k)
{
    int nowm=0;
    while(!que.empty())
        que.pop();
    for(int i=1;i<=N;i++)
    {
        if(!que.empty()&&i-que.front()>=k)
            que.pop();
        if((que.size()^ori[i])&1)
        {
            if(i+k-1>N)
                return;
            que.push(i);
            nowm++;
        }
    }
    if(nowm<resm)
    {
        resk=k;
        resm=nowm;
    }
}

void input()
{
    char ch;
    for(int i=1;i<=N;i++)
    {
        scanf("%c",&ch);
        if(ch==' '||ch=='\n')
        {
            i--;continue;
        }
        if(ch=='B')
            ori[i]=1;
        else ori[i]=0;
    }
}

void work()
{
    resm=inf;
    for(int i=1;i<=N;i++)
        judge(i);
    printf("%d %d\n",resk,resm);
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    input();
    work();
    return 0;
}
