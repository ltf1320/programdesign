#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=30;

bool map[maxn][maxn];

int n,m;

bool vis[maxn];
bool nmap[maxn][maxn];
int sorted[maxn];

int TopoSort()
{
    int s;
    bool flag;
    bool res=1;
    memset(vis,0,sizeof(vis));
    memcpy(nmap,map,sizeof(map));
    for(int k=0; k<n; k++)
    {
        s=-1;
        for(int i=0; i<n; i++)
        {
            if(vis[i]) continue;
            flag=true;
            for(int j=0; j<n; j++)
            {
                if(i==j) continue;
                if(nmap[j][i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                if(s!=-1) res=0;  //注意这里不能直接return 0;因为第一次判断有多个头的时候可能之后会出现错误
                else s=i;
            }
        }
        if(s==-1)
        {
            return -1;
        }
        vis[s]=1;
        sorted[k]=s;
        for(int i=0; i<n; i++)
            nmap[s][i]=0;
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    char c1,c2;
    char tmp[maxn];
    bool skip;
    int res;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        skip=0;
        gets(tmp);
        memset(map,0,sizeof(map));
        for(int i=1; i<=m; i++)
        {
            scanf("%c<%c\n",&c1,&c2);
            map[c1-'A'][c2-'A']=1;
            if(!skip)
            {
                res=TopoSort();
                if(res==-1)
                {
                    printf("Inconsistency found after %d relations.\n",i);
                    skip=1;
                }
                else if(res==1)
                {
                    printf("Sorted sequence determined after %d relations: ",i);
                    for(int i=0; i<n; i++)
                        putchar(sorted[i]+'A');
                    printf(".\n");
                    skip=1;
                }
            }
        }
        if(!skip) printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
