#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
const int maxn=30+10;
const int inf=0x3f3f3f3f;
int N,M;
map<string,int> mp;

int dis[maxn][maxn];
int dp[300][maxn];
int goal[8];//4��Ŀ��
bool vis[maxn];

void floyd()
{
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

void work()
{
    floyd();
    int mx,mi;
    //��ʼ״̬
    for(int i=0;i<8;i++)
        for(int j=0;j<N;j++)
            dp[1<<i][j]=dis[goal[i]][j];

    for(int i=1;i<(1<<8);i++)
    {
        if(!(i&(i-1)))//��ʼ״̬���Թ�
            continue;
        for(int k=0;k<N;k++)
        {
            vis[k]=0;
            //ö����״̬������k������
            /*
            for(int j=0;j<i;j++)
            {
                if((i|j)==i)
                    dp[i][k]=min(dp[i][k],dp[i-j][k]+dp[j][k]);
            }
            */
            for(int j=i;j;j=(j-1)&i)
                dp[i][k]=min(dp[i][k],dp[i-j][k]+dp[j][k]);

        }
        //����ÿ��k��ֵ�����״̬���ܲ�����k�����Ӷ����������С������ͨ�����������ӣ�
        for(int j=0;j<N;j++)
        {
            mx=inf;
            for(int k=0;k<N;k++)
            {
                if(dp[i][k]<mx&&!vis[k])
                {
                    mx=dp[i][k];
                    mi=k;
                }
            }
            vis[mi]=1;
            for(int k=0;k<N;k++)
                dp[i][k]=min(dp[i][k],dp[i][mi]+dis[mi][k]);
        }
    }
    //ö��ÿ�ֿ��ܵĽ��
    int res=inf,nst,rt,nres;
    for(int i=0;i<(1<<8);i++)
    {
        nres=0;
        for(int j=0;j<4;j++) //��״̬��ͬ�Ĺ�Ϊһ��
        {
            nst=0;
            for(int k=0;k<8;k+=2)
            {
                if((i>>k&3)==j)
                {
                    nst+=3<<k;
                    rt=goal[k];
                }
            }
            if(nst)
                nres+=dp[nst][rt];
        }
        res=min(res,nres);
    }
    printf("%d\n",res);
}

void input()
{
    string f,t;
    int fr,to,d;
    for(int i=0;i<N;i++)
    {
        cin>>t;
        mp[t]=i;
    }
    for(int i=0;i<M;i++)
    {
        cin>>f>>t>>d;
        fr=mp[f];
        to=mp[t];
        dis[fr][to]=dis[to][fr]=min(dis[fr][to],d);
    }
    for(int i=0;i<8;i++)
    {
        cin>>f;
        goal[i]=mp[f];
    }
}

void init()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dis[i][j]=i==j?0:inf;
    for(int i=0;i<(1<<8);i++)
        for(int j=0;j<N;j++)
            dp[i][j]=inf;
    mp.clear();
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0)break;
        init();
        input();
        work();
    }
    return 0;
}
