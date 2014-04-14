#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
const int maxn=700+100;
const int maxh=100000;
const int Pri=99997;
int res;
struct HasNode
{
    int a,b,c;
    HasNode *next;
    int n;
    HasNode(int aa,int bb,int cc):a(aa),b(bb),c(cc){next=NULL;n=1;}
    HasNode(){n=0;next=NULL;}
    void reset()
    {
        if(next!=NULL)
        {
            next->reset();
            delete next;
            next=NULL;
        }
    }
};
HasNode Has[maxh];
int abs(int a){return a>0?a:-a;}
int getHash(int &a,int &b,int &c)
{
    return abs(a<<1|b<<2|c<<3)%Pri;
}

void insert(int a,int b,int c)
{
    int g=getHash(a,b,c);
    HasNode *now;
    for(now=&Has[g];now->next!=NULL;now=now->next)
    {
        if(now->next->a==a&&now->next->b==b&&now->next->c==c)
        {
            now->next->n++;
            if(now->next->n>res) res=now->next->n;
            return ;
        }
    }
    now->next=new HasNode(a,b,c);
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
    return a;
}

struct Node
{
    int x,y;
};
Node nds[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int N;
    int a,b,c,g;
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        res=0;
        for(int i=0;i<maxh;i++)
            Has[i].reset();
        for(int i=0; i<N; i++)
            scanf("%d%d",&nds[i].x,&nds[i].y);
        for(int i=0; i<N; i++)
            for(int j=i+1; j<N; j++)
            {
                a=nds[j].y-nds[i].y;
                b=-(nds[j].x-nds[i].x);
                c=-(nds[j].y-nds[i].y)*nds[i].x+(nds[j].x-nds[i].x)*nds[i].y;
                if(a==0)
                {
 //                   if(b==0) return a/0;
                    if(b<0)
                    {
                        b=-b;
                        c=-c;
                    }
                    g=abs(gcd(b,c));
                    b/=g;
                    c/=g;
                    insert(0,b,c);
                }
                else
                {
                    if(a<0)
                    {
                        a=-a;
                        b=-b;
                        c=-c;
                    }
                    g=abs(gcd(gcd(a,b),c));
                    a/=g;
                    b/=g;
                    c/=g;
                    insert(a,b,c);
                }
            }
        printf("%d\n",res);
    }
    return 0;
}
