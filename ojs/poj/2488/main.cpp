#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=10;
int p,q;
bool vis[maxn][maxn];
struct Point
{
    int x,y;
    Point(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
    Point() {}
};
Point route[30];
int top;
const int dx[8]= {-2,-2,-1,-1,1,1,2,2};
const int dy[8]= {-1,1,-2,2,-2,2,-1,1};


bool dfs()
{
    Point& now(route[top-1]);
    if(top==p*q) return true;
    for(int i=0; i<8; i++)
    {
        if(now.x+dx[i]>0&&now.x+dx[i]<=q&&now.y+dy[i]>0&&now.y+dy[i]<=p&&!vis[now.x+dx[i]][now.y+dy[i]])
        {
            vis[now.x+dx[i]][now.y+dy[i]]=1;
            route[top].x=now.x+dx[i];
            route[top++].y=now.y+dy[i];
            if(dfs())return true;
            vis[now.x+dx[i]][now.y+dy[i]]=0;
            top--;
        }
    }
    return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    bool flag;
    int cas=1;
    while(T--)
    {
        scanf("%d%d",&p,&q);
        flag=0;
        memset(vis,0,sizeof(vis));
        vis[1][1]=1;
        top=0;
        route[top].x=1;
        route[top].y=1;
        top++;
        printf("Scenario #%d:\n",cas++);
        if(dfs())
        {
            for(int i=0; i<top; i++)
                printf("%c%d",route[i].x+'A'-1,route[i].y);
            printf("\n");
        }
        else  printf("impossible\n");
        printf("\n");
    }
    return 0;
}
