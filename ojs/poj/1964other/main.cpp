#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int NN=2000;
int pre[NN],stack[NN],stacknum,l[NN],r[NN],z;
bool xmap[NN][NN];
char tmp[10];
int T,n,m;
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j)
            {
                scanf("%s",&tmp);
                if (strcmp(tmp,"R")==0) xmap[i][j]=0;
                else xmap[i][j]=1;
            }
        memset(pre,0,sizeof(pre));
        int ans=0;
        for (int j=1; j<=m; ++j)
        {
            for (int i=1; i<=n; ++i)
                if (xmap[i][j]) ++pre[i];
                else pre[i]=0;
            memset(stack,0,sizeof(stack));
            memset(l,0,sizeof(l));
            memset(r,0,sizeof(r));
            l[0]=r[0]=l[n+1]=r[n+1]=-1;
            z=0;
            for (int i=1; i<=n; ++i)
            {
                while (z>0 && pre[stack[z-1]]>=pre[i]) --z;
                l[i]=stack[z-1];
                if (z==0) l[i]=0;
                stack[z]=i;
                ++z;
            }
            z=0;
            for(int i=n; i>=1; --i)
            {
                while (z>0 && pre[stack[z-1]]>=pre[i]) --z;
                r[i]=stack[z-1];
                if (z==0) r[i]=n+1;
                stack[z]=i;
                ++z;
            }
            for (int i=1; i<=n; ++i)
                if (ans<(r[i]-l[i]-1) * pre[i])
                    ans=pre[i]*(r[i]-l[i]-1);
        }
        printf("%d\n",ans*3);
    }
}
