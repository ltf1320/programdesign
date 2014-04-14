#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=400+10;
const int inf=0x3f3f3f3f;
int N,F,D;
struct EDGE
{
    int next,to;
    int v;
};
EDGE edge[maxn*maxn];
int box[maxn];
int ent;

void _add(int f,int t,int cap)
{
    edge[ent].to=t;
    edge[ent].v=cap;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int cap)
{
    _add(f,t,cap);
    _add(t,f,0);
}

int dis[maxn],pre[maxn];
int cur[maxn],aug[maxn];
int gap[maxn];

int sap(int s, int e, int n)
{
    int max_flow = 0, v, u = s;
    int id, mindis;
    aug[s] = inf;
    pre[s] = -1;
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    gap[0] = n;
    for (int i = 0; i <= n; ++i){//��ʼ����ǰ��Ϊ��һ����
        cur[i] = box[i];
    }

    while (dis[s] < n)
    {
        bool flag = false;
        if (u == e)
        {
            max_flow += aug[e];
            for (v = pre[e]; v != -1; v = pre[v])//·�����ݸ��²�������
            {
                id = cur[v];
                edge[id].v -= aug[e];
                edge[id^1].v += aug[e];
                aug[v] -= aug[e]; //�޸Ŀ����������Ժ���õ�
                if (edge[id].v == 0) u = v; //�����˵�Դ�㣬�����˵�����Ϊ0�Ļ��Ļ�β
            }
        }
        for (id = cur[u]; id != -1; id = edge[id].next)
        {   // �ӵ�ǰ����ʼ��������
            v = edge[id].to;
            if (edge[id].v > 0 && dis[u] == dis[v] + 1) //�ҵ�����
            {
                flag = true;
                pre[v] = u;
                cur[u] = id;
                aug[v] = min(aug[u], edge[id].v);
                u = v;
                break;
            }
        }
        if (flag == false)
        {
            if (--gap[dis[u]] == 0) break; /*gap�Ż���������ֶϲ�������㷨*/
            mindis = n;
            cur[u] = box[u];
            for (id = box[u]; id != -1; id = edge[id].next)
            {
                v = edge[id].to;
                if (edge[id].v > 0 && dis[v] < mindis)
                {
                    mindis = dis[v];
                    cur[u] = id; //�޸ı�ŵ�ͬʱ�޸ĵ�ǰ��
                }
            }
            dis[u] = mindis + 1;
            gap[dis[u]]++;
            if (u != s) u = pre[u]; //���ݼ���Ѱ������
        }
    }
    return max_flow;
}


void input()
{
    int f,d;
    int tt;
    for(int i=0;i<F;i++)
    {
        add(0,2+2*N+i,1);
    }
    for(int i=0;i<D;i++)
        add(2+2*N+F+i,1,1);
    for(int i=0;i<N;i++)
        add(2+i,2+N+i,1);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&f,&d);
        for(int j=0;j<f;j++)
        {
            scanf("%d",&tt);
            add(tt+2*N+1,2+i,1);
        }
        for(int j=0;j<d;j++)
        {
            scanf("%d",&tt);
            add(2+N+i,tt+2*N+F+1,1);
        }
    }
}

void work()
{
    printf("%d\n",sap(0,1,400));
}

void init()
{
    memset(box,-1,sizeof(box));
    ent=0;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    scanf("%d%d%d",&N,&F,&D);
    init();
    input();
    work();
    return 0;
}
