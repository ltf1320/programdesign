#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
int N;
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
    int x,y,z;
};
Node nds[maxn];

bool judge(Node &a,Node &b)
{
    int gc=gcd(a.x,b.x);
    int l=a.y-b.z,r=a.z-b.y;
    if(l/gc!=r/gc||r%gc==0||l%gc==0)
        return true;
    return false;
}

void work()
{
    for(int i=0; i<N; i++)
        for(int j=i+1; j<N; j++)
        {
            if(judge(nds[i],nds[j]))
            {
                puts("Cannot Take off");
                return;
            }
        }
    puts("Can Take off");
}

void input()
{
    for(int i=0;i<N;i++)
        scanf("%d%d%d",&nds[i].x,&nds[i].y,&nds[i].z);
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        input();
        work();
    }
    return 0;
}
