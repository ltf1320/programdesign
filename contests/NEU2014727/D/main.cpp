#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=100000+100;

struct Node
{
    int l,r;
    int add;
    LL sum;
    bool clear;
};
Node tree[4*maxn];

void pl1()
{
    tree[1].sum+=tree[1].r-tree[1].l+1;
    tree[1].add+=1;
    tree[1].clear=false;
}

LL change(int l,int r)

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
