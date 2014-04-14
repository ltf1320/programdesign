#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+100;
const int maxk=30+10;

int sum[maxn][maxk];
const int Pri=99997;
int N,K;


struct C
{
    int vv[maxk];
    int code;
    bool operator<(const C &a)const
    {
        for(int i=0;i<K;i++)
            if(vv[i]!=a.vv[i])
                return vv[i]<a.vv[i];
        return code<a.code;
    }
};
C c[maxn];

int fabs(const int &a){return a>0?a:-a;}

bool judge(int a,int b)
{
    for(int i=K-1;i>=0;i--)
        if(c[a].vv[i]!=c[b].vv[i])  return false;
    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    int now;
    int res;
    scanf("%d%d",&N,&K);
    for(int i=0; i<K; i++)
        sum[0][i]=0;
    res=0;
    memset(c[0].vv,0,sizeof(c[0].vv));
    c[0].code=0;
    for(int i=1; i<=N; i++)
    {
        scanf("%d",&now);
        for(int j=0; j<K; j++)
        {
            if(now&1)
                sum[i][j]=sum[i-1][j]+1;
            else sum[i][j]=sum[i-1][j];
            c[i].vv[j]=sum[i][j]-sum[i][0];
            c[i].code=i;
            now>>=1;
        }
    }
    /*
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<K;j++)
            printf("%d ",c[i][j]);
        putchar('\n');
    }
    */
    sort(c,c+N+1);
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<=N+1;j++)
        {
            if(j==N+1||c[j].vv[0]!=c[i].vv[0]||!judge(i,j))
            {
                if(c[j-1].code-c[i].code>res)
                    res=c[j-1].code-c[i].code;
                i=j-1;
                break;//
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
