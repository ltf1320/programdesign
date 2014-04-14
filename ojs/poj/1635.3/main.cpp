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
    int num;
    TREE(){}
    void get(bool *from,int start,int to)
    {
        memset(route,0,sizeof(route));
        for(int i=start;i<=to;i++)
            route[i-start]=from[i];
        num=to-start+1;
    }
    void reset()
    {
        num=0;
        memset(route,0,sizeof(route));
    }
    void read()
    {
        scanf("%s",tmp);
   //     cin>>tmp;
        num=strlen(tmp);
        for(int i=0; i<num; i++)
            route[i+1]=(tmp[i]=='1'?1:0);
        num+=2;
        route[0]=0;
        route[num-1]=1;
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
TREE *now;

struct SON
{
    int l,r;
    SON(int ll,int rr):l(ll),r(rr){}
    bool operator<(const SON &a) const
    {
        if(r-l!=a.r-a.l) return r-l<a.r-a.l;
        for(int i=0;i<=r-l;i++)
            if(now->route[l+i]!=now->route[a.l+i])
                return now->route[a.l+i];
        return 0;
    }
};

void sort(TREE &a,int l,int r)
{
    int n1=0,n0=0,f=l+1;
    vector<SON> son;
    for(int i=l+1;i<r;i++)
    {
        if(a.route[i]) n1++;
        else n0++;
        if(n1==n0)
        {
            n1=0;n0=0;
            sort(a,f,i);
            son.push_back(SON(f,i));
            f=i+1;
        }
    }
    sort(son.begin(),son.end());
    int k=l+1;
    for(vector<SON>::iterator iter=son.begin();iter!=son.end();iter++)
    {
        for(int i=iter->l;i<=iter->r;i++)
        {
            tmp[k++]=a.route[i];
        }
    }
    for(k=l+1;k<r;k++)
        a.route[k]=tmp[k];
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    TREE a,b;
    scanf("%d",&T);
    while(T--)
    {
        a.read();
        b.read();
        now=&a;
        sort(a,0,a.num);
        now=&b;
        sort(b,0,b.num);
 //       a.print();
 //       b.print();
        if(a==b) printf("same\n");
        else printf("different\n");
    }
    return 0;
}
