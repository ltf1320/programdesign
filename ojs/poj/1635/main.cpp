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
    TREE *son[maxn];
    int sn,num;
    TREE(){}
    TREE(bool *from,int start,int to)
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
        {
            son[i]->reset();
            delete son[i];
        }
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

bool cmp(const TREE *a,const TREE *b)
{
    if(a->num!=b->num) return a->num<b->num;
    for(int i=0; i<a->num; i++)
    {
        if(a->route[i]!=b->route[i])
        {
            return b->route[i];
        }
    }
    return 0;
}

void sort(TREE *a)
{
    int n1=0,n0=0;
    int l=1;
    for(int i=1;i<a->num-1;i++)
    {
        if(a->route[i]) n1++;
        else n0++;
        if(n1==n0)
        {
            n1=0;n0=0;
            a->son[a->sn++]=new TREE(a->route,l,i);
            l=i+1;
        }
    }
    for(int i=0;i<a->sn;i++)
        sort(a->son[i]);
    sort(a->son,a->son+a->sn,cmp);
    int k=1;
    for(int i=0;i<a->sn;i++)
    {
        for(int j=0;j<a->son[i]->num;j++)
        {
            a->route[k++]=a->son[i]->route[j];
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    TREE a,b;
    while(T--)
    {
        a.read();
        b.read();
        sort(&a);
        sort(&b);
 //       a.print();
 //       b.print();
        if(a==b) printf("same\n");
        else printf("different\n");
    }
    return 0;
}
