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
    ST():a(0),b(0){}
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
        a=0;b=0;
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
    ST operator|(const ST &st)const
    {
        ST res;
        res.a=a|st.a;
        res.b=b|st.b;
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


struct Has
{
    ST has[MOD];
    int hn;
    void reset()
    {
        hn=0;
    }
    bool insert(ST &a)
    {
        for(int i=0;i<hn;i++)
        {
            if((a|has[i])==has[i])
                return false;
        }
        has[hn++]=a;
        return true;
    }
    ST find(ST &a)
    {
        for(int i=0;i<hn;i++)
        {
            if((a|has[i])==has[i])
                return has[i];
        }
        return ST();
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
    //    cout<<f<<" "<<t<<endl;
        f--;
        t--;
        map[f].add(t);
        map[t].add(f);
    }
}
int res,cnt;
void dfs(int now,ST st)
{
    ST fd=has.find(st);
    if(fd.a&&fd.b)
    {
        bool flag=0;
        ST momo;
        for(int i=0;i<64;i++)
        {
            if(st.a&((ULL)1<<i))
                momo=momo|map[i];
            if(st.b&((ULL)1<<i))
                momo=momo|map[i+64];
        }
        if((momo|fd)==fd) return;
    }

    if(res>1000)
        return;
    if(now==N)
    {
        cnt++;
        if(st.count()<2)
            return;
        if(has.insert(st))
            res++;
        return;
    }
    if((st&map[now])==st)
    {
        st.add(now);
        dfs(now+1,st);
        st.del(now);
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
    cnt=res=0;
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
