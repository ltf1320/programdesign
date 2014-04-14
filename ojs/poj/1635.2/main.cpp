#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=3000+10;
char tmp[maxn];
struct TREE
{
    bool route[maxn];
    int son[maxn];
    int sn,num;
    TREE(){}
    void get(bool *from,int start,int to)
    {
        memset(route,0,sizeof(route));
        for(int i=start;i<=to;i++)
            route[i-start]=from[i];
        num=to-start+1;
        sn=0;
        memset(son,0,sizeof(son));
    }
    void reset()
    {
        for(int i=0; i<sn; i++)
            son[i]=-1;
        sn=0;
        num=0;
        memset(route,0,sizeof(route));
        memset(son,0,sizeof(son));
    }
    void read()
    {
        scanf("%s",tmp);
        num=strlen(tmp);
        for(int i=0; i<num; i++)
            route[i+1]=(tmp[i]=='1'?1:0);
        num+=2;
        route[0]=0;
        route[num-1]=1;
        sn=0;
    }
    bool operator==(const TREE &a)
    {
        if(num!=a.num) return 0;
        for(int i=0;i<num;i++)
        {
            if(route[i]!=a.route[i])
                return false;
        }
        return true;
    }
    void print()
    {
        for(int i=0;i<num;i++)
            printf("%d ",route[i]);
            putchar('\n');
    }
};
TREE ts[maxn];
int ent;
bool cmp(int a,int b)
{
    if(ts[a].num!=ts[b].num) return ts[a].num<ts[b].num;
    for(int i=0; i<ts[a].num; i++)
    {
        if(ts[a].route[i]!=ts[b].route[i])
        {
            return ts[b].route[i];
        }
    }
    return 0;
}

void sort(int a)
{
    int n1=0,n0=0;
    int l=1;
    for(int i=1;i<ts[a].num-1;i++)
    {
        if(ts[a].route[i]) n1++;
        else n0++;
        if(n1==n0)
        {
            n1=0;n0=0;
            ts[a].son[ts[a].sn++]=ent;
            ts[ent].get(ts[a].route,l,i);
            ent++;
            l=i+1;
        }
    }
    for(int i=0;i<ts[a].sn;i++)
        sort(ts[a].son[i]);
    sort(ts[a].son,ts[a].son+ts[a].sn,cmp);
    int k=1;
    for(int i=0;i<ts[a].sn;i++)
    {
        for(int j=0;j<ts[ts[a].son[i]].num;j++)
        {
            ts[a].route[k++]=ts[ts[a].son[i]].route[j];
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ent=2;
        ts[0].read();
        ts[1].read();
        sort(0);
        sort(1);
        ts[0].print();
        ts[1].print();
        if(ts[0]==ts[1]) printf("same\n");
        else printf("different\n");
    }
    return 0;
}
