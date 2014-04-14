#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int next[310000],ans[310000],pre[310000];
int main()
{

    int n,m;
    scanf("%d%d",&n,&m);


    for(int i=1;i<=n;i++)
    {
        pre[i]=i-1;
        next[i]=i+1;
    }
    memset(ans,0,sizeof(ans));
    int l,r,x;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&l,&r,&x);
        int p=l;
        while (p<=r)
        {
            if (ans[p]==0&&p!=x)
            {
                ans[p]=x;
                int s=pre[p];
                int t=next[p];
                pre[t]=s;
                next[s]=t;
                p=t;
            }
            else p=next[p];
        }
    }
        for (int i=1;i<=n;i++)
        printf("%d ",ans[i]);
        printf("\n");



    return 0;
}
