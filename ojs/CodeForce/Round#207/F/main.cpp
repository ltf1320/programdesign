#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=70000+100;
int N,S;
vector<int> res[maxn];
bool used[maxn];
bool can[2*maxn];
int pre[2*maxn];

struct FSO
{
    int id,v;
    bool operator<(const FSO &a)const
    {
        return v>a.v;
    }
};
FSO fnum[maxn];
int num[maxn];

int main()
{
    scanf("%d%d",&N,&S);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&num[i]);
        fnum[i].id=i;
        fnum[i].v=num[i];
    }
    sort(fnum,fnum+N);
    if(fnum[0].v>S)
    {
        printf("-1\n");
        return 0;
    }
    can[0]=1;
    pre[0]=-1;
    int mx=0;
    for(int i=0;i<N;i++)
    {
        for(int j=mx;j>=0;j--)
            if(can[j]&&!can[j+fnum[i].v])
            {
                can[j+fnum[i].v]=1;
                pre[j+fnum[i].v]=i;
                mx=max(mx,j+fnum[i].v);
                mx=min(S,mx);
                if(can[S]) break;
            }
        if(can[S]) break;
    }
    if(!can[S])
        printf("-1\n");
    else
    {
        int mid=0;
        mx=0;
        int now=S;
        while(now)
        {
            used[fnum[pre[now]].id]=1;
            if(fnum[pre[now]].v>mx)
            {
                mx=fnum[pre[now]].v;
                mid=fnum[pre[now]].id;
            }
            now-=fnum[pre[now]].v;
        }
        for(int i=0;i<N;i++)
        {
            if(used[fnum[i].id]) continue;
            if(fnum[i].v>mx)
            {
                printf("-1");
                return 0;
            }
            num[mid]-=fnum[i].v;
            res[mid].push_back(fnum[i].id+1);
            mid=fnum[i].id;
        }

        for(int i=0;i<N;i++)
        {
            printf("%d %d",num[i],(int)res[i].size());
            for(int j=0;j<(int)res[i].size();j++)
                printf(" %d",res[i][j]);
            puts("");
        }
    }
    return 0;
}
