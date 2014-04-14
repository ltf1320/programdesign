#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N;
const int maxn=500*2+10;
const int maxk=32;
const int maxm=500*250*4;


int b[maxn][maxn];

struct EDGE
{
    int to,next;
};
EDGE edge[maxm];
int box[maxn];
int ent;

void add(int f,int t)
{
    if(ent==634)
    {
        ent++;
        ent--;
    }
    if(f==630)
    {
        ent++;
        ent--;
    }
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

int dfn[maxn],low[maxn];
int fl[maxn],fln;
int stack[maxn],top;
bool in[maxn];
int ti;

void tarjan(int now)
{
    dfn[now]=low[now]=ti++;
    stack[++top]=now;
    in[now]=1;
    for(int i=box[now]; i!=-1; i=edge[i].next)
    {
        if(now==630&&edge[i].next>maxm)
        {
            now++;
            now--;
        }
        if(!dfn[edge[i].to])
        {
            tarjan(edge[i].to);
            low[now]=min(low[now],low[edge[i].to]);
        }
        else if(in[edge[i].to])
            low[now]=min(low[now],dfn[edge[i].to]);
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
    fln=0;
}

void initMap()
{
    memset(box,-1,sizeof(box));
    ent=0;
}

void work()
{
    for(int i=0; i<N; i++)
        for(int j=i; j<N; j++)
        {
            if(i==j)
            {
                if(b[i][j]!=0)
                {
                    printf("NO\n");
                    return;
                }
            }
            else
            {
                if(b[i][j]!=b[j][i])
                {
                    printf("NO\n");
                    return;
                }
            }
        }
    for(int k=0; k<32; k++)
    {
        initMap();
        for(int i=0; i<N; i++)
            for(int j=i+1; j<N; j++)
            {
                if(i%2==1&&j%2==1) //|
                {
                    if(b[i][j]&(1<<k))
                    {
                        add(i*2,j*2+1);
                        add(j*2,i*2+1);
                    }
                    else
                    {
                        add(i*2+1,i*2);
                        add(j*2+1,j*2);
                    }
                }
                else if(i%2==0&&j%2==0)//&
                {
                    if(b[i][j]&(1<<k))
                    {
                        add(i*2,i*2+1);
                        add(j*2,j*2+1);
                    }
                    else
                    {
                        add(i*2+1,j*2);
                        add(j*2+1,i*2);
                    }
                }
                else
                {
                    //^
                    if(b[i][j]&(1<<k))
                    {
                        add(i*2,j*2+1);
                        add(i*2+1,j*2);
                        add(j*2,i*2+1);
                        add(j*2+1,i*2);
                    }
                    else
                    {
                        add(i*2,j*2);
                        add(i*2+1,j*2+1);
                        add(j*2,i*2);
                        add(j*2+1,i*2+1);
                    }
                }
            }
        initTarjan();
        for(int i=0; i<N*2; i++)
            if(!dfn[i])
                tarjan(i);
        for(int i=0; i<N; i++)
            if(fl[i*2]==fl[i*2+1])
            {
                printf("NO\n");
                return;
            }
    }
    printf("YES\n");
}

void input()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            scanf("%d",&b[i][j]);
        }
}



int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        input();
        work();
    }
//    cout<<ent<<endl;
    return 0;
}
