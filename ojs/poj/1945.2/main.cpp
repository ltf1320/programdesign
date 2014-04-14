//16875 19878

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;
const int maxn=20000+10;
const int inf=0x3f3f3f3f;
const int hasmax=9999997;

int N;
int kn;
void swap(int *a,int *b)
{
    if(*a<*b)
    {
        int t=*a;
        *a=*b;
        *b=t;
    }
}

int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    if(!a) a=1;
    return a;
}

int getS(int a,int b)
{
    if(a==N||b==N) return -inf;
    int tar=N;
    a=max(a,b);
    if(!a) a++;
    if(a>N)
    {
        tar=a-N;
        a=b;
    }
    int res=0,k=1;
    while(a*k<tar)
    {
        res++;
        k<<=1;
    }
    return res;
}


struct Node
{
    int a,b,d,s;
    Node(int aa,int bb,int dd)
    {
        a=aa;
        b=bb;
        d=dd;
        s=d+getS(a,b);
    }
    Node(){}
    bool operator<(const Node &a)const
    {
        if(s==a.s) return d<a.d;
        return s>a.s;
    }
};

priority_queue<Node> que;

struct Has
{
    int a,b,d;
    Has *next;
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

void hasInsert(int a,int b,int d)
{
    int k=getHas(a,b);
    Has* now=&has[k];
    while(now->next)
    {
        now=now->next;
        if(now)
        {
            if(now->a==a&&now->b==b)
                {now->d=d;return;}
        }
    }
    now->next=new Has();
    now=now->next;
    now->a=a;
    now->b=b;
    now->d=d;
}

int hasFind(int a,int b)
{
    int k=getHas(a,b);
    Has* now=has[k].next;
    while(now)
    {
        if(now->a==a&&now->b==b)
            return now->d;
        now=now->next;
    }
    return -1;
}

void DO(int a,int b,int d)
{
    swap(&a,&b);
    /*
    if(a==N||b==N)
    {
        printf("%d\n",d);
     //   printf("%d\n",kn);
        exit(0);
    }
    */
    if(b<=0) return;
    if(a==b) return;
  //  if(a>2*N) return;
   // if(b>N) return;
    if(N%gcd(a,b)) return;
    int k=hasFind(a,b);
    if(k!=-1&&d>=k) return;
    que.push(Node(a,b,d));
    hasInsert(a,b,d);
}


int work()
{
    Node now;
    que.push(Node(1,0,0));
    while(!que.empty())
    {
        now=que.top();
        que.pop();
        kn++;
  //      printf("%d %d %d %d\n",now.a,now.b,now.d,now.s);
        if(now.a==N||now.b==N) return now.d;
        DO(now.a*2,now.b,now.d+1);
        DO(now.a*2,now.a,now.d+1);
        DO(now.b*2,now.b,now.d+1);
        DO(now.b*2,now.a,now.d+1);
        DO(now.a+now.b,now.b,now.d+1);
        DO(now.a+now.b,now.a,now.d+1);
        //??
        DO(now.a-now.b,now.a,now.d+1);
        DO(now.a-now.b,now.b,now.d+1);
        DO(now.b-now.a,now.a,now.d+1);
        //??
        DO(now.b-now.a,now.b,now.d+1);
    }
    return -1;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&N);
    kn=0;
    printf("%d\n",work());
    printf("%d\n",kn);
    return 0;
}
