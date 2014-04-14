#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=30000+100;
int father[maxn];
int num[maxn];
int n,m;
void init()
{
    for(int i=0;i<n;++i)
        num[i]=1;
    for(int i=0;i<n;++i)
        father[i]=i;
}


int find(int a)
{
    while(father[a]!=a)
    {
        a=father[a];
    }
    return a;
}

void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
        return;
    father[a]=b;
    num[b]+=num[a];
    return;
}

int main()
{
    freopen("in.txt","r",stdin);
    int k,p,head;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0 && m==0) break;
        init();
        for(int i=0;i<m;++i)
        {
            scanf("%d",&k);
            scanf("%d",&head);
            for(int j=1;j<k;++j)
            {
                scanf("%d",&p);
                Union(head,p);
            }
        }
        printf("%d\n",num[find(0)]);
    }
    return 0;
}
