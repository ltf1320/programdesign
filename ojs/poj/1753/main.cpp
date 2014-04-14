#include<cstdio>

using namespace std;

bool game[10][10];
int step;

void flip(int x,int y)
{
    for(int i=x-1; i<=x+1; i++)
        game[i][y]^=1;
    game[x][y+1]^=1;
    game[x][y-1]^=1;
}

bool allOne()
{
    bool w=1;
    bool b=1;
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=4; j++)
        {
            if(game[i][j]!=0)
            {
                w=0;
            }
            if(game[i][j]!=1)
            {
                b=0;
            }
        }
        if(w==0&&b==0) break;
    }
    return w|b;
}

bool dfs(int x,int y,int st)
{

    if(step==st)
    {
        return allOne();
    }
    if(y>4) return false;
    flip(x,y);
    if(x<4)
    {
        if(dfs(x+1,y,st+1))return true;
    }
    else if(dfs(1,y+1,st+1)) return true;
    flip(x,y);
    if(x<4)
    {
        if(dfs(x+1,y,st))return true;
    }
    else if(dfs(1,y+1,st)) return true;
    return false;
}

bool input()
{
    char ch;
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
        {
            if(scanf("%c",&ch)==EOF) return false;
            if(ch=='\n') scanf("%c",&ch);
            if(ch=='b')
                game[i][j]=1;
            if(ch=='w')
                game[i][j]=0;
        }
    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(input())
    {
        bool flag=1;
        for(step=0; step<=16; step++)
        {
            if(dfs(1,1,0))
            {
                printf("%d\n",step);
                flag=0;
                break;
            }
        }
        if(flag) printf("Impossible");
    }
    return 0;
}
