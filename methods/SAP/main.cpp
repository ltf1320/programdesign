#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int INT_MAX=0x3f3f3f3f;
const int maxn=220;
const int maxm=maxn*maxn;
int numh[maxn],h[maxn],curedges[maxn],pre[maxn];
struct Node
{
    int c,next,to;
};
Node edge[maxn];
int box[maxn];

int ent;
void add(int from,int to,int c)
{
    edge[ent].to=to;
    edge[ent].next=box[from];
    edge[ent].c=c;
    box[from]=ent++;
}
int SAP_Max_Flow(int start,int end,int N)
{
    int cur_flow,flow_ans=0,u,tmp,neck,i;
    memset(h,0,sizeof(h));
    memset(numh,0,sizeof(numh));
    memset(pre,-1,sizeof(pre));
    for(i=0; i<=N; ++i)
        curedges[i]=box[i];
    numh[0]=N;
    u=start;
    while(h[start]<N)
    {
        if(u==end)
        {
            cur_flow=INT_MAX;
            for(i=start; i!=end; i=edge[curedges[i]].to)
            {
                if(cur_flow>edge[curedges[i]].c)
                {
                    neck=i;
                    cur_flow=edge[curedges[i]].c;
                }
            }
            for(i=start; i!=end; i=edge[curedges[i]].to)
            {
                tmp=curedges[i];
                edge[tmp].c-=cur_flow;
                edge[tmp^1].c+=cur_flow;
            }
            flow_ans+=cur_flow;
            u=neck;
        }

        for(i=curedges[u]; i!=-1; i=edge[i].next)
            if(edge[i].c && h[u]==h[edge[i].to]+1)
                break;
        if(i!=-1)
        {
            curedges[u]=i;
            pre[edge[i].to]=u;
            u=edge[i].to;
        }
        else
        {
            if(0==--numh[h[u]]) break;
            curedges[u]=box[u];
            for(tmp=N,i=box[u]; i!=-1; i=edge[i].next)
                if(edge[i].c)
                    tmp=min(tmp,h[edge[i].to]);
            h[u]=tmp+1;
            ++numh[h[u]];
            if(u!=start) u=pre[u];
        }
    }
    return flow_ans;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    int from,to,f;
    int res;
    while(~scanf("%d%d",&n,&m))
    {
        ent=0;
        memset(box,-1,sizeof(box));
        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d",&from,&to,&f);
            add(from,to,f);
            add(to,from,0);
        }
        res=SAP_Max_Flow(1,m,ent);
        printf("%d\n",res);
    }
    return 0;
}
