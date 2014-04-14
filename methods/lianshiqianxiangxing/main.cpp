#include <iostream>
#include<cstdio>
#include <cstring>
using namespace std;

const int MAXN=1000;
const int INF=(unsigned int)~0>>1;

struct Node
{
    int to,next;
};

Node edge[MAXN];
int box[MAXN];
int ent=1;
void makeMap(int from,int to)
{
    edge[ent].to=to;
    edge[ent].next=box[from];
    box[from]=ent++;
}

void edgefrom(int n)
{
    for(int j=0; j<10; ++j)
        for(int i=box[j]; i; i=edge[i].next)
        {
            cout<<j<<"to"<<edge[i].to<<endl;
        }
}

int main()
{
    freopen("in.txt","r",stdin);
    memset(box,0,sizeof(box));
    memset(edge,0,sizeof(edge));
    int from,to;
    int n=0;
    while(scanf("%d%d",&from,&to)!=EOF)
    {
        n++;
        makeMap(from,to);
    }
    for(int i=0;i<n;++i)
        edgefrom(i);
    return 0;
}
