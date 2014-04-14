#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int maxn=10000*2+100;
int N;
bool c[maxn];
int fa[maxn];
int num[maxn];
int ent;
map<int,int> mp;

int getE(int a)
{
    if(mp.count(a))
        return mp[a];
    else
    {
        mp[a]=ent;
        num[ent]=a;
        return ent++;
    }
}

int getFather(int a)
{
    int t;
    if(fa[fa[a]]!=fa[a])
    {
        t=fa[a];  //!
        fa[a]=getFather(fa[a]);
        c[a]=c[t]^c[a];
    }
    return fa[a];
}

int work()
{
    int l,r;
    int lc,rc,lf,rf;
    bool v;
    char tmp[10];
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%s",&l,&r,tmp);
        if(l>r){int t=r;r=l;l=t;}
        r++;
        v=!(tmp[0]=='e');
        lc=getE(l);rc=getE(r);
        lf=getFather(lc);rf=getFather(rc);
        if(lf==rf)
        {
            if(c[lc]^c[rc]^v)
                return i;
        }
        else
        {
            if(num[lf]<num[rf])
            {
                fa[rf]=lf;
                c[rf]=c[lc]^c[rc]^v;
            }
            else
            {
                fa[lf]=rf;
                c[lf]=c[lc]^c[rc]^v;
            }
        }
    }
    return N;
}

void init()
{
    for(int i=0;i<maxn;i++)
        fa[i]=i;
    ent=0;
    mp.clear();
    memset(c,0,sizeof(c));
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    scanf("%d",&N);
    init();
    printf("%d\n",work());
    return 0;
}
