#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50+10;
int N;
int num[maxn];
int du[maxn];
char r[4*maxn];

struct EDGE
{
    int to,next;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;
void _add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t)
{
    _add(f,t);
    _add(t,f);
}

void read()
{
    char *tr=r;
    while(~sscanf(tr,"%d",&num[N]))
    {
        du[num[N]]++;
        N++;
        while(*tr<='9'&&*tr>='0')
            tr++;
        while(*tr==' ')
            tr++;
    }
}

void buildTree()
{
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(num[i]==j) continue;
            if(du[j]==0)
            {
                du[j]--;
                du[num[i]]--;
                add(num[i],j);
                break;
            }
        }
    }
}

void readTree(int now,int from)
{
    printf("(%d",now);
    for(int i=box[now];i!=-1;i=edge[i].next)
    {
        if(edge[i].to==from) continue;
        printf(" ");
        readTree(edge[i].to,now);
    }
    printf(")");
}

void init()
{
    ent=0;
    memset(box,-1,sizeof(box));
    memset(du,0,sizeof(du));
    N=1;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(gets(r))
    {
        init();
        read();
        buildTree();
        readTree(N,-1);
        putchar('\n');
    }
    return 0;
}
