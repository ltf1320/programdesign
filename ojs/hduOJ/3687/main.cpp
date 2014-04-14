#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100;
const int maxm=300;
const int inf=0x3f3f3f3f;
int N,M;
int people[maxn][maxn];
int pn[maxn];
int sum;

int cal(int start)
{
    int res=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<N;j++)
        {
            res+=abs(people[i][j]-(start+j));
        }
    }
    return res;
}

int work()
{
//    int avg=sum/(N*N);
    int res=inf;
    for(int i=1;i<=M-N+1;i++)
        res=min(res,cal(i));
    return res;
}


void input()
{
    int a,b;
    memset(pn,0,sizeof(pn));
    sum=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d%d",&a,&b);
            people[a][pn[a]++]=b;
            sum+=b;
        }
    }
    for(int i=1;i<=N;i++)
        sort(people[i],people[i]+N);
}

int main()
{
    cout<<225*1024*32<<endl;
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0) break;
        input();
        printf("%d\n",work());
    }
    return 0;
}
