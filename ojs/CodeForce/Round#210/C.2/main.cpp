#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=5000+10;
const int inf=1E9;
int N,M;
int num[maxn];
bool used[maxn];
int add[maxn];


struct Qury
{
    int type,l,r,k;
};
Qury qry[maxn];

int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
        scanf("%d%d%d%d",&qry[i].type,&qry[i].l,&qry[i].r,&qry[i].k);
    for(int i=M-1;i>=0;i--)
    {
        if(qry[i].type==2)
        {
            for(int j=qry[i].l;j<=qry[i].r;j++)
            {
                if(used[j])
                {
                    if(qry[i].k<num[j])
                    {
                        num[j]=qry[i].k;
                    }
                }
                else
                {
                    num[j]=qry[i].k;
                    used[j]=1;
                }
            }
        }
        else
        {
            for(int j=qry[i].l;j<=qry[i].r;j++)
            {
                if(used[j])
                    num[j]-=qry[i].k;
            }
        }
    }
    int mx;
    for(int i=0;i<M;i++)
    {
        if(qry[i].type==2)
        {
            mx=-inf;
            for(int j=qry[i].l;j<=qry[i].r;j++)
            {
                if(num[j]+add[j]>mx)
                    mx=num[j]+add[j];
            }
            if(mx!=qry[i].k)
            {
                puts("NO");
                return 0;
            }
        }
        else
        {
            for(int j=qry[i].l;j<=qry[i].r;j++)
            {
                add[j]+=qry[i].k;
            }
        }
    }
    puts("YES");
    for(int i=1;i<=N;i++)
    {
        if(i>1)
            putchar(' ');
        if(used[i])
            printf("%d",num[i]);
        else printf("%d",0);
    }
    puts("");
    return 0;
}
