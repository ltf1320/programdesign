#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int map[30][30];
int ansa[30],ansb[30];
int n,ans;
bool f[30];
int yy(int a[],int aa)
{
    int ans=0;
    for (int i=1;i<=aa;i++)
    {
        int sum=0;
        for (int j=1;j<=aa;j++)
        if (!map[a[i]][a[j]]) sum++;
        if (sum>ans) ans=sum;
    }
    return ans;
}
void re_ans()
{
    int a[30],b[30],aa=0,bb=0;
    for (int i=1;i<=n;i++)
    {
        if (f[i])
        {
            aa++;
            a[aa]=i;
        }
        else
        {
            bb++;
            b[bb]=i;
        }
    }
    int p1=yy(a,aa),p2=yy(b,bb);
    if (p1<ans&&p2<ans)
    {
        ans=max(p1,p2);
        ansa[0]=aa;
        for (int i=1;i<=aa;i++)
        ansa[i]=a[i];
        ansb[0]=bb;
        for (int i=1;i<=bb;i++)
        ansb[i]=b[i];
    }

}
void dfs(int k,int sum)
{
    if (sum+n-k<n/2)
    return ;
    if (sum==n/2)
    {
        re_ans();
        return;
    }
    for (int i=k+1;i<=n;i++)
    {
        f[i]=1;
        dfs(i,sum+1);
        f[i]=0;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    while (~scanf("%d",&n))
    {
        memset(map,0,sizeof(map));
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        map[i][i]=1;

        int num,t,a;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&num,&t);
            while (t--)
            {
                scanf("%d",&a);
                map[num][a]=map[a][num]=1;
            }
        }

        ans=12;
        dfs(0,0);
        cout<<ans<<endl;

        for (int i=0;i<ansa[0];i++)
        printf("%d ",ansa[i]);
        printf("%d\n",ansa[ansa[0]]);
        for (int i=0;i<ansb[0];i++)
        printf("%d ",ansb[i]);
        printf("%d\n",ansb[ansb[0]]);
        cout<<endl;

    }
    return 0;
}
