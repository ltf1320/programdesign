#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=10000+100;
int N,K;

struct EDGE
{
    int to,next,l;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;

void _add(int f,int t,int l)
{
    edge[ent].to=t;
    edge[ent].l=l;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t,int l)
{
    _add(f,t,l);
    _add(t,f,l);
}

void input()
{
    int f,t,l;
    for(int i=0;i<N-1;i++)
    {
        scanf("%d%d%d",&f,&t,&l);
        add(f,t,l);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
