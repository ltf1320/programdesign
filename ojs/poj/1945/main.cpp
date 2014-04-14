#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define DO(a,b,d) if(Can(a,b,d)){que.push(State(a,b,d));}
using namespace std;
const int maxn=20000+10;
const int inf=0x3f3f3f3f;
const int hasmax=999997;
int N;
struct Has
{
    int a,b,d;
    Has *next;
    Has(){next=0;}
    void reset()
    {
        if(next)
            next->reset();
        delete next;
        next=0;
    }
};
Has has[hasmax+100];
int getHas(int a,int b)
{
   return ((a<<2)^b)%hasmax;
}
bool Hasfind(int a,int b,int d)
{
    if(a<b)
    {
        int t=a;
        a=b;
        b=t;
    }
    int k=getHas(a,b);
    Has* now=has[k].next;
    while(now)
    {
        if(now->a==a&&now->b==b)
        {
            if(d>=now->d) return 1;
            else return 0;
        }
        now=now->next;
    }
    return 0;
}

void HasInsert(int a,int b,int d)
{
    if(a<b)
    {
        int t=a;
        a=b;
        b=t;
    }
    int k=getHas(a,b);
    Has* now=&has[k];
    while(now->next)
    {
        now=now->next;
        if(now->a==a&&now->b==b)
            {now->d=min(now->d,d);return;}
    }
    now->next=new Has();
    now=now->next;
    now->a=a;
    now->b=b;
    now->d=d;
}

int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=a%b;
        a=b;
        b=t;
    }
    if(a==0) a=1;
    return a;
}

int getS(int a,int b)
{
    a=max(a,b);
    if(a==0) a=1;
    int res=0,k=1;
    while(a*k<N)
    {
        res++;
        k*=2;
    }
    return res;
}

struct State
{
    int a,b,s,d;
    State(int aa,int bb,int dd)
    {
        a=aa;
        b=bb;
        d=dd;
        s=d+getS(a,b);
    }
    State() {}
    bool operator<(const State &a)const
    {
        if(s==a.s) return d<a.d;
        return s>a.s;
    }
};
priority_queue<State> que;


bool Can(int a,int b,int d)
{
    if(a<0||b<0) return false;
    if(N%gcd(a,b)) return false;
    if(Hasfind(a,b,d)) return false;
    else HasInsert(a,b,d);
    return true;
}

int work()
{
    State now;
    int d;
    que.push(State(1,0,0));
    while(!que.empty())
    {
        now=que.top();
        que.pop();
        if(now.a==N||now.b==N)
        {
            while(!que.empty()) que.pop();
            return now.d;
        }
        d=now.d+1;
        DO(now.a*2,now.b,d);
        DO(now.a*2,now.a,d);
        DO(now.b*2,now.a,d);
        DO(now.b*2,now.b,d);
        DO(now.a+now.b,now.a,d);
        DO(now.a+now.b,now.b,d);
        DO(now.a-now.b,now.a,d);
        DO(now.a-now.b,now.b,d);
        DO(now.b-now.a,now.a,d);
        DO(now.b-now.a,now.b,d);
    }
    return -1;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        for(int i=0;i<hasmax;i++)
            has[i].reset();
        printf("%d\n",work());
    }
    return 0;
}
