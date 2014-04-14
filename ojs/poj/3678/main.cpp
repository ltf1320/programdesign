#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2000+100;
int N,M;
int map[maxn][maxn];

int dfn[maxn],low[maxn];
int fl[maxn],fln;
int stack[maxn],top;
bool in[maxn];
int time;

void tarjan(int now)
{
    dfn[now]=low[now]=time++;
    stack[++top]=now;
    in[now]=1;
    for(int i=0; i<2*N; i++)
    {
        if(map[now][i])
        {
            if(!dfn[i])
            {
                tarjan(i);
                low[now]=min(low[now],low[i]);
            }
            else if(in[i])
                low[now]=min(low[now],dfn[i]);
        }
    }
    int nd;
    if(dfn[now]==low[now])
    {
        while(top!=-1)
        {
            nd=stack[top];
            top--;
            fl[nd]=fln;
            in[nd]=0;
            if(nd==now) break;
        }
        fln++;
    }
}

void initTarjan()
{
    memset(dfn,0,sizeof(dfn));
    memset(in,0,sizeof(in));
    top=-1;
    time=1;
    fln=0;
}

void work()
{
    for(int i=0;i<2*N;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=0;i<N;i++)
        if(fl[i*2]==fl[i*2+1])
        {
            printf("NO\n");
            return;
        }
    printf("YES\n");
}

void input()
{
    int f,t,c;
    char op[10];
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d%s",&f,&t,&c,op);
        switch(op[0])
        {
            case 'A':
                if(c)
                {
                    map[f*2+1][t*2+1]=1;
                    map[t*2+1][f*2+1]=1;
                    map[f*2][f*2+1]=1;
                    map[t*2][t*2+1]=1;
                }
                else
                {
                    map[f*2+1][t*2]=1;
                    map[t*2+1][f*2]=1;
                }
                break;
            case 'O':
                if(c)
                {
                    map[f*2][t*2+1]=1;
                    map[t*2][f*2+1]=1;
                }
                else
                {
                    map[f*2][t*2]=1;
                    map[t*2][f*2]=1;
                    map[f*2+1][f*2]=1;
                    map[t*2+1][t*2]=1;
                }
                break;
            case 'X':
                if(c)
                {
                    map[t*2][f*2+1]=1;
                    map[t*2+1][f*2]=1;
                    map[f*2][t*2+1]=1;
                    map[f*2+1][t*2]=1;
                }
                else
                {
                    map[t*2][f*2]=1;
                    map[t*2+1][f*2+1]=1;
                    map[f*2][t*2]=1;
                    map[f*2+1][t*2+1]=1;
                }
                break;
        }
    }
}

void init()
{
    memset(map,0,sizeof(map));
    initTarjan();
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
