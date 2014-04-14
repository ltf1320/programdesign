#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=100+10;
const int maxm=2*2000+10;
const int maxk=5;

int N,M,Nm,Nb,Nj,Nw,S;
int BX[maxk],MF[maxk],JS[maxk],WL[maxk];
int st[maxn];

struct EDGE
{
    int to,next,len;
};
EDGE edge[maxm];
int box[maxn];
int ent;
void add(int f,int t,int len)
{
    edge[ent].to=t;
    edge[ent].len=len;
    edge[ent].next=box[f];
    box[f]=ent++;
}

struct State
{
    int now,sp;
    float t;
    int bx[maxk],js[maxk],wl[maxk],mf[maxk];
    bool operator<(const State &a)const
    {
        return t>a.t;
    }
};

void input()
{
    int f,t,l;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&f,&t,&l);
        add(f,t,l);
        add(t,f,l);
    }
    scanf("%d",&Nm);
    for(int i=0;i<Nm;i++)
        scanf("%d",&MF[i]);
    scanf("%d",&Nb);
    for(int i=0;i<Nb;i++)
        scanf("%d",&BX[i]);
    scanf("%d",&Nj);
    for(int i=0;i<Nj;i++)
        scanf("%d",&JS[i]);
    scanf("%d",&Nw);
    for(int i=0;i<Nw;i++)
        scanf("%d",&WL[i]);
    scanf("%d",&S);
}
priority_queue<State> que;
float work()
{
    State now;
    now.now=S;
    for(int i=0;i<Nm;i++)
        now.mf[i]=MF[i];
    for(int i=0;i<Nb;i++)
        now.bx[i]=BX[i];
    for(int i=0;i<Nj;i++)
        now.js[i]=JS[i];
    for(int i=0;i<Nw;i++)
        now.wl[i]=WL[i];
    now.t=0;
    que.push(now);
    while(!que.empty())
    {
        now=que.top();
        que.pop();

    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
