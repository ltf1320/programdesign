#include <iostream>
#include <cstdio>
#include <cstring>


int a[20]={2,
7,
5,
30,
169,
441,
1872,
7632,
1740,
93313,
459901,
1358657,
}

using namespace std;
const int maxn=30;
bool vis[maxn];

int k;

bool te(int m)
{
    int now=0;
    int cl=0;
    int kedn=0;
    memset(vis,0,sizeof(vis));
    vis[0]=true;
    while(true)
    {
        now++;
        if(now>2*k)
            now=1;
        if(!vis[now]) cl++;
        if(cl==m)
        {
            cl=0;
            vis[now]=1;
            kedn++;
            if(now<=k) return false;
        }
        if(kedn==k) return true;
    }
    return true;
}

int main()
{
 /*   freopen("in.txt","r",stdin);
    int res;
    while(~scanf("%d",&k))
    {
        if(k==0) break;
        res=1;
        while(!te(res++));
        printf("%d\n",res-1);
    }
*/
    int res;
    freopen("out.txt","w",stdout);
    k=13;
    {
//        if(k==0) break;
        res=1358657;
        while(!te(res++));
        printf("%d\n",res-1);
    }

    return 0;
}
