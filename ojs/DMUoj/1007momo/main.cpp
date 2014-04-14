#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int Maxn=50020;
const int inf=Maxn;
const int PP=Maxn-10;
struct HeapElement
{
    int key;
    int value;
};
struct MinHeap
{
    HeapElement H[Maxn];
    int size;
    int position[Maxn];
    void init()
    {
        H[size=0].value=-inf;
        H[0].key=0;
    }
    void decrease(int key,int value)
    {
        key=position[key];
        if(value>H[key].value) return;
        H[key].value=value;
        while(key>1&&(H[key/2].value>H[key].value))
        {
            swap(H[key/2].value,H[key].value);
            swap(position[H[key/2].key],position[H[key].key]);
            swap(H[key/2].key,H[key].key);
            key=key/2;
        }
    }
    void ins(int key,int value)
    {
        size++;
        H[key].value=value;
        H[key].key=key;
        position[key]=key;
        while(key>1&&H[key/2].value>H[key].value)
        {
            swap(H[key/2].value,H[key].value);
            swap(position[H[key/2].key],position[H[key].key]);
            swap(H[key/2].key,H[key].key);
            key=key/2;
        }
    }
    void delmin()
    {
//        if(size<1) return;
        size--;
        H[1].value=H[size].value;
        position[H[size].key]=1;
        H[1].key=H[size].key;
        int p=1;
        while(p<=size&&((H[p].value>H[p<<1].value)||(H[p].value>H[(p<<1)+1].value)))
        {
            if(H[p<<1].value<H[(p<<1)+1].value)
            {
                swap(H[p].value,H[p<<1].value);
                swap(position[H[p].key],position[H[p<<1].key]);
                swap(H[p].key,H[p<<1].key);
                p=p<<1;
            }
            else if(H[(p<<1)+1].value<=H[p<<1].value)
            {
                swap(H[p].value,H[(p<<1)+1].value);
                swap(position[H[p].key],position[H[(p<<1)+1].key]);
                swap(H[p].key,H[(p<<1)+1].key);
                p=(p<<1)+1;
            }
        }
    }
} H;
struct EdgeNode
{
    int to;
    int w;
    int next;
};
EdgeNode edge[2*Maxn];
int head[2*Maxn];
int dist[2*Maxn];
int  N,M;
void dijkstra()
{
    int i,j,k;
    H.init();
    for(int i=1; i<=N; i++)
    {
        H.ins(i,inf);
        dist[i]=inf;
    }
    dist[PP]=0;
    H.decrease(PP,0);
    for(i=PP;H.size;i=H.H[1].key)
    {
        H.delmin();
        for(k=head[i]; k!=-1; k=edge[k].next)
        {
            if(dist[i]<dist[j=edge[k].to]-edge[k].w)
            {
                dist[j]=dist[i]+edge[k].w;
                H.decrease(j,dist[j]);
            }
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int q;
    while(scanf("%d%d%d",&N,&M,&q),N||M||q)
    {
        memset(head,-1,sizeof(head));
//        memset(edge,0,sizeof(edge));
        int k;
        for(k=0; k<M; k++)
        {
            int i,j;
            scanf("%d%d",&i,&j);
            edge[k].to=j;
            edge[k].next=head[i];
            edge[k].w=1;
            head[i]=k;
        }
        N++;
        for(int i=0; i<q; i++)
        {
            int j;
            scanf("%d",&j);
            edge[k].to=j;
            edge[k].w=1;
            edge[k].next=head[PP];
            head[PP]=k;
            k++;
        }
        dijkstra();
        if(dist[1]==inf) printf("Emmm..");
        else printf("%d",(dist[1]-1));
        printf("\n");
    }
    return 0;
}
