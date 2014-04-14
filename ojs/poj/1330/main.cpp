#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10000+10;
int N;
int fa[maxn];
bool path[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int a,b,T;
    scanf("%d",&T);
    while(T--)
    {
        memset(fa,-1,sizeof(fa));
        memset(path,0,sizeof(path));
        scanf("%d",&N);
        for(int i=1;i<N;i++)
        {
            scanf("%d%d",&a,&b);
            fa[b]=a;
        }
        scanf("%d%d",&a,&b);
        path[b]=1;
        while(b!=-1)
            path[b=fa[b]]=1;
        while(!path[a])
            a=fa[a];
        printf("%d\n",a);
    }
    return 0;
}
