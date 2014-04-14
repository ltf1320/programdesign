#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 20010
#define maxm 1800000
const int inf=(1<<29);
struct EDGE{
    int v,next;
    int cap;
}ee[maxm];
int head[maxn],gap[maxn]; //dep[maxn];
int n,m,src,des,siz;//src=start,des=end;
void init(){
    siz=0;
    memset(head,-1,sizeof head);
}
void addedge(int u,int v,int cap){
    ee[siz].v=v,ee[siz].cap=cap;
    ee[siz].next=head[u];
    head[u]=siz++;

    ee[siz].v=u,ee[siz].cap=0;
    ee[siz].next=head[v];
    head[v]=siz++;
}
int dis[maxn],pre[maxn];
int cur[maxn],aug[maxn];

int SAP(int s, int e, int n)
{
    int max_flow = 0, v, u = s;
    int id, mindis;
    aug[s] = inf;
    pre[s] = -1;
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    gap[0] = n;
    for (int i = 0; i <= n; ++i){//��ʼ����ǰ��Ϊ��һ����
        cur[i] = head[i];
    }

    while (dis[s] < n)
    {
        cout<<dis[s]<<endl;
        bool flag = false;
        if (u == e)
        {
            max_flow += aug[e];
            for (v = pre[e]; v != -1; v = pre[v])//·�����ݸ��²�������
            {
                id = cur[v];
                ee[id].cap -= aug[e];
                ee[id^1].cap += aug[e];
                aug[v] -= aug[e]; //�޸Ŀ����������Ժ���õ�
                if (ee[id].cap == 0) u = v; //�����˵�Դ�㣬�����˵�����Ϊ0�Ļ��Ļ�β
            }
        }
        for (id = cur[u]; id != -1; id = ee[id].next)
        {   // �ӵ�ǰ����ʼ��������
            v = ee[id].v;
            if (ee[id].cap > 0 && dis[u] == dis[v] + 1) //�ҵ�����
            {
                flag = true;
                pre[v] = u;
                cur[u] = id;
                aug[v] = min(aug[u], ee[id].cap);
                u = v;
                break;
            }
        }
        if (flag == false)
        {
            if (--gap[dis[u]] == 0) break; /*gap�Ż���������ֶϲ�������㷨*/
            mindis = n;
            cur[u] = head[u];
            for (id = head[u]; id != -1; id = ee[id].next)
            {
                v = ee[id].v;
                if (ee[id].cap > 0 && dis[v] < mindis)
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



int main()
{
    freopen("in.txt","r",stdin);
    while (scanf("%d%d",&n,&m) != EOF)
    {
        init();
        int a,b,w;
        int source=1,sink=n+2;
        for(int i=2;i<=n+1;i++){
            scanf("%d%d",&a,&b);
            addedge(source,i,a);
            addedge(i,sink,b);
        }
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&w);
            a++,b++;
            addedge(a,b,w);
            addedge(b,a,w);
        }
        printf("%d\n", SAP(source, sink, sink+1));
    }
    return 0;
}
