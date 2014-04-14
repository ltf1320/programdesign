#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#define maxn 105
#define mod 1000000000
#define INF 0x3f3f3f3f
using namespace std;

int n,m,ans;
int c[maxn];
int city[maxn][maxn];
queue<int>q;

bool bfs(int pos)
{
    int i,j,nx;
    while(!q.empty()) q.pop();
    q.push(pos);
    while(!q.empty())
    {
        nx=q.front();
        q.pop();
        for(i=1;i<=n;i++)
        {
            if(i==nx||city[i][nx]&&city[nx][i]) continue ;// ��nx��������ʱ��ȷ���������ĸ�����
            if(c[i]==-1)    // ����nx�����ѿ϶�������һ������
            {
                c[i]=c[nx]^1;
                q.push(i);
            }
            else if(c[i]==c[nx]) return true ; // ����nx���ѵ���������ͬһ���ϾͲ���������
        }
    }
    return false ;
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,j,u,v;
    while(~scanf("%d",&n))
    {
        memset(city,0,sizeof(city));
        for(i=1;i<=n;i++)
        {
            while(scanf("%d",&v),v)
            {
                city[i][v]=1;
            }
        }
        memset(c,-1,sizeof(c));
        for(i=1;i<=n;i++)
        {
            if(c[i]==-1)
            {
                c[i]=0;    // Ĭ���ڼ���0 ������ʾ����֤���������ᣩ
                if(bfs(i)) break ;
            }
        }
        if(i<=n) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
