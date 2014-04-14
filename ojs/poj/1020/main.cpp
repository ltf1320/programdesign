//dfs+剪枝
//首先是查找要从上往下，从左往右，从大到小找
//然后是记录的数组要是1维的
//再是一个剪枝（当确定放不下最大那块板时）

#include <iostream>
#include <cstdio>
#include<algorithm>
#include <cstring>
using namespace std;
const int maxn=200;
int s,n;

int cakes[20];
int oped[maxn];

bool able(int a,int b,int d)
{
    if(oped[a]+d>s) return false;
    if(a+d>s) return false;
    for(int i=a;i<a+d;i++)
    {
        if(oped[i]>b) return false;
    }
    return true;
}

bool dfs()
{
    int mx,my,maxi;
    bool flag=1;
    for(int i=0;i<s;i++)
    {
        if(oped[i]<s)
        {
            mx=i;
            my=oped[i];
            flag=0;
            break;
        }
    }
    if(flag)
        return true;
/*    for(int i=10;i>0;i--)
        if(cakes[i]>0) {maxi=i;break;}
    if(s-mx<cakes[maxi]) return false;
*/    for(int i=10;i>0;i--)
        if(cakes[i]>0&&able(mx,my,i))
        {
            for(int j=mx;j<mx+i;j++) oped[j]+=i;
            cakes[i]--;
            if(dfs()) return true;
            cakes[i]++;
            for(int j=mx;j<mx+i;j++) oped[j]-=i;
        }
    return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    int sum;
    int tmp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&s,&n);
        memset(cakes,0,sizeof(cakes));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            cakes[tmp]++;
        }
        sum=0;
        for(int i=1;i<=10;i++)
            sum+=cakes[i]*i*i;
        if(sum==s*s)
        {
            for(int i=0;i<s;i++)
                oped[i]=0;
            if(dfs()) printf("KHOOOOB!\n");
            else printf("HUTUTU!\n");
        }
        else printf("HUTUTU!\n");
    }
    return 0;
}
