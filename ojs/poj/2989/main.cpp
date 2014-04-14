#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ULL;
const int maxn=150;
const int MOD=2000+100;

int N,M;

struct ST
{
    ULL a,b;
    bool flag;
    ST():a(0),b(0),flag(0){}
    int count()
    {
        int res=0;
        for(int i=0;i<64;i++)
        {
            if(a&((ULL)1<<i))
                res++;
            if(b&((ULL)1<<i))
                res++;
        }
        return res;
    }
    void clear()
    {
        a=0;b=0;flag=0;
    }
    bool operator==(const ST &st)const
    {
        return a==st.a&&b==st.b;
    }
    ST operator&(const ST &st)const
    {
        ST res;
        res.a=a&st.a;
        res.b=b&st.b;
        return res;
    }

    void add(int s)
    {
        if(s<64)
            a|=(ULL)1<<s;
        else
            b|=(ULL)1<<(s-64);
    }
    void del(int s)
    {
        if(s<64&&(a&((ULL)1<<s)))
            a^=(ULL)1<<s;
        else if(s>=64&&(b&((ULL)1<<(s-64))))
            b^=(ULL)1<<(s-64);
    }

    int getHas()
    {
        return (a^b)%MOD;
    }
};

struct HasNode
{
    ST now;
    HasNode *next;
    void reset()
    {
        if(next)
        {
            next->reset();
            delete next;
            next=0;
        }
    }
    HasNode():next(0){}
    HasNode(const ST &a):now(a),next(0){}
};

struct Has
{
    HasNode *has[MOD+100];
    Has()
    {
        memset(has,0,sizeof(has));
    }
    void reset()
    {
        for(int i=0;i<MOD+100;i++)
        {
            if(has[i])
            {
                has[i]->reset();
                delete has[i];
                has[i]=0;
            }
        }
    }
    bool insert(ST &a)
    {
        int h=a.getHas();
        if(has[h]==0)
        {
            has[h]=new HasNode(a);
        }
        else
        {
            HasNode *now=has[h];
            while(true)
            {
                if(a==now->now)
                    return false;
                if(!now->next)
                    break;
                now=now->next;
            }
            now->next=new HasNode(a);
        }
        return true;
    }
};
Has has;

ST map[maxn];

void input()
{
    int f,t;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&f,&t);
        f--;
        t--;
        map[f].add(t);
        map[t].add(f);
    }
}
int res;
void dfs(int now,ST st)
{
    if(res>1000)
        return;
    if(now==N)
    {
        if(st.count()<2||st.flag)
            return;
        if(has.insert(st))
            res++;
        return;
    }
    if((st&map[now])==st)
    {
        st.add(now);
        st.flag=0;
        dfs(now+1,st);
        st.del(now);
        st.flag=1;
    }
    dfs(now+1,st);
}

void work()
{
    dfs(0,ST());
    if(res>1000)
        printf("Too many maximal sets of friends\n");
    else
        printf("%d\n",res);
}

void init()
{
    has.reset();
    res=0;
    for(int i=0;i<N;i++)
        map[i].clear();
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        init();
        input();
        work();
    }
    return 0;
}
