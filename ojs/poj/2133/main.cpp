#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1<<17;
const int maxe=110;
const int inf=0x3f3f3f3f;
int B,E;
int sts[maxe];
int step[maxn];
int goal;
char restr[maxe];

char tmp[maxe];

int ston(char *str)
{
    int res=0;
    for(int i=0;i<B;i++)
    {
        if(tmp[i]=='1')
            res|=(1<<(B-i-1));
    }
    return res;
}

void ntos(int num,char *str)
{
    for(int i=0;i<B;i++)
    {
        if(num&(1<<(B-i-1)))
            str[i]='1';
        else str[i]='0';
    }
    str[B]=0;
}

void input()
{
    scanf("%s",tmp);
    goal=ston(tmp);
    for(int i=0;i<E;i++)
    {
        scanf("%s",tmp);
        sts[i]=ston(tmp);
    }
}

struct FSO
{
    int dep,v;
    FSO(int d,int vv):dep(d),v(vv){}
    FSO(){}
    bool operator<(const FSO &a)const
    {
        if(a.dep==dep)
            return v>a.v;
        return a.dep>dep;
    }
};
bool in[maxn];

void findres()
{
    queue<FSO> que;
    memset(in,0,sizeof(in));
    FSO now;
    que.push(FSO(0,goal));
    in[goal]=1;
    int res=-1,rdep=inf;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(now.dep>rdep)
        {
            break;
        }
        if(step[now.v]!=inf)
        {
            rdep=now.dep;
            if(res==-1||step[res]>step[now.v])
            {
                res=now.v;
            }
        }
        for(int i=B-1;i>=0;i--)
            if(now.v&(1<<i))
                if(!in[now.v^(1<<i)])
                {
                    in[now.v^(1<<i)]=1;
                    que.push(FSO(now.dep+1,now.v^(1<<i)));
                }
        for(int i=0;i<B;i++)
            if(!(now.v&(1<<i)))
                if(!in[now.v^(1<<i)])
                {
                    in[now.v^(1<<i)]=1;
                    que.push(FSO(now.dep+1,now.v^(1<<i)));
                }
    }
    printf("%d\n",step[res]);
    ntos(res,tmp);
    printf("%s\n",tmp);
    while(!que.empty()) que.pop();
}

void work()
{
    queue<int> que;
    int now,nxt;
    for(int i=0;i<(1<<(B+1));i++)
        step[i]=inf;
    memset(in,0,sizeof(in));
    for(int i=0;i<E;i++)
    {
        step[sts[i]]=0;
        que.push(sts[i]);
        in[sts[i]]=1;
    }
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<E;i++)
        {
            nxt=now^sts[i];
            if(step[now]+1<step[nxt])
            {
                step[nxt]=step[now]+1;
                if(!in[nxt])
                {
                    que.push(nxt);
                    in[nxt]=1;
                }
            }
        }
        in[now]=0;
    }
    for(int i=0;i<E;i++)
    {
        step[sts[i]]=2;
    }
    findres();
    while(!que.empty()) que.pop();
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&B,&E))
    {
        input();
        work();
    }
    return 0;
}
