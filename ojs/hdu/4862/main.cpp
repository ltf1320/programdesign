#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=11;
const int maxk=101;

int N,M,K;
int res=-0x3f3f3f3f;
char arr[maxn][maxn];
struct state
{
    bool vis[maxn][maxn];
    bool findXY(int &x,int &y)
    {
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if(!vis[i][j])
                {
                    x=i;
                    y=j;
                    return true;
                }
        return false;
    }

};
void dfs(state st,int k,int energy);
void jump(state st,int x,int y,int k,int energy)
{
    for(int i=x+1; i<N; i++)
        if(!st.vis[i][y])
        {
            state nst(st);
            nst.vis[i][y]=1;
            int ne=energy-(i-x-1);
            if(arr[i][y]==arr[x][y])
                ne+=arr[x][y]-'0';
            jump(nst,i,y,k,ne);
        }
    for(int i=y+1; i<M; i++)
        if(!st.vis[x][i])
        {
            state nst(st);
            nst.vis[x][i]=1;
            int ne=energy-(i-y-1);
            if(arr[x][i]==arr[x][y])
                ne+=arr[x][y]-'0';
            jump(nst,x,i,k,ne);
        }
    dfs(st,k+1,energy);
}

void dfs(state st,int k,int energy)
{
    int x,y;
    if(!st.findXY(x,y))
    {
        res=max(res,energy);
        return;
    }
    if(k==K)
        return ;
    st.vis[x][y]=1;
    return jump(st,x,y,k,energy);
}


int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        res=-0x3f3f3f3f;
        printf("Case %d : ",cas);
        scanf("%d%d%d",&N,&M,&K);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin>>arr[i][j];
        if(K<min(N,M))
        {
            printf("-1\n");
            continue;
        }
        state st;
        memset(st.vis,0,sizeof(st.vis));
        dfs(st,0,0);
        printf("%d\n",res);
    }
    return 0;
}
