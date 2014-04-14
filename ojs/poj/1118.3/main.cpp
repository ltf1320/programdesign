#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
const long long maxn=700+10;
const long long maxh=maxn*maxn;
const long long Pri=99997;
long long res;
long long ent;
struct HasNode
{
    long long a,b,c;
    HasNode(long long aa,long long bb,long long cc):a(aa),b(bb),c(cc){}
    HasNode(){}
    bool operator<(const HasNode &p) const
    {
        if(a==p.a)
        {
            if(b==p.b)
                return c<p.c;
            return b<p.b;
        }
        return a<p.a;
    }
    bool operator==(const HasNode &p)
    {
        if(c!=p.c) return false;
        if(b!=p.b) return false;
        if(a!=p.a) return false;
        return true;
    }
};
HasNode Has[maxh];
//long long abs(long long a){return a>0?a:-a;}

void insert(long long a,long long b,long long c)
{
    Has[ent++]=HasNode(a,b,c);
}

long long gcd(long long a,long long b)
{
    long long t;
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
    long long x,y;
};
Node nds[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int N;
    long long a,b,c,g;
    while(~scanf("%d",&N))
    {
        if(N==0) break;
        res=0;
        ent=0;
        for(int i=0; i<N; i++)
            scanf("%I64d%I64d",&nds[i].x,&nds[i].y);
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
        sort(Has,Has+ent);
        for(int i=0;i<ent;i++)
        {
            long long d=1;
            for(int j=i+1;j<ent;j++)
            {
                if(Has[i]==Has[j])
                    d++;
                else
                {
                    if(d>res) res=d;
                    i=j-1;
                    break;
                }
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}
