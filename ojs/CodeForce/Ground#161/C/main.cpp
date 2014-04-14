#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=100000+1000;
int N;
int rel[maxn][5];
int p[maxn];
int mark[maxn];
int que1[maxn];
int que2[maxn];
int p1,p2;

int find(int a,int b,int c)
{
    memset(mark,0,sizeof(mark));
    queue<int> que;
    int now;
    for(int i=0;i<4;i++)
    {
        mark[rel[a][i]]++;
        que.push(rel[a][i]);
    }
    for(int i=0;i<4;i++)
    {
        mark[rel[b][i]]++;
        que.push(rel[b][i]);
    }
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(mark[now]==2&&now!=c)
            return now;
    }
    return -1;
}


int main()
{
    int a,b;
    bool flag;
    scanf("%d",&N);
    for(int i=0;i<2*N;i++)
    {
        scanf("%d%d",&a,&b);
        rel[a][p[a]++]=b;
        rel[b][p[b]++]=a;
    }
    for(int i=1;i<=N;i++)
        sort(rel[i],rel[i]+4);
    que1[p1++]=1;
    que2[p2++]=1;
    for(int i=0;i<4;i++)
    {
 //       mark[rel[1][i]]++;
        for(int j=0;j<4;j++)
        {
            mark[rel[rel[1][i]][j]]++;
        }
    }
    flag=0;
    for(int i=1;i<=N;i++)
        if(mark[i]==3)
        {
            if(!flag)
            {
                que1[p1++]=i;
                flag=1;
            }
            else
            {
                que2[p2++]=i;
                break;
            }
        }
    que1[p1++]=find(1,que1[1],que2[1]);
    que2[p2++]=find(1,que2[1],que1[1]);
    while(p1+p2-1<N)
    {
        a=find(que1[p1-1],que1[p1-2],que1[p1-3]);
        if(a==-1){printf("-1\n");return 0;}
        que1[p1++]=a;
        if(p1+p2-1==N) break;
        a=find(que2[p2-1],que2[p2-2],que2[p2-3]);
        if(a==-1){printf("-1\n");return 0;}
        que1[p2++]=a;
    }
    for(int i=0;i<p1;i++)
        printf("%d ",que1[i]);
    for(int i=p2-1;i>1;i--)
        printf("%d ",que2[i]);
    printf("%d\n",que2[1]);
    return 0;
}
