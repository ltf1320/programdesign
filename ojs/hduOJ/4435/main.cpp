#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef unsigned long long LL;
const int maxn=200;
int map[maxn][maxn];

struct CO
{
    LL a,b;
    bool operator<(const CO &s)
    {
        if(a==s.a)
            return b<s.b;
        return a<s.a;
    }
};

struct Node
{
    int x,y;
};
Node nds[maxn];
int getDis(const Node &a,const Node &b)
{
    int s=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    int l=0,r=s;
    int m;
    while(r-l>1)
    {
        m=(l+r)>>1;
        if(m*m==s) return m;
        if(m*m>s)
            r=m;
        else l=m;
    }
    return r;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
