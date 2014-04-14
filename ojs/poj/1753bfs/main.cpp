#include<cstdio>
#include<queue>
using namespace std;


struct Ga
{
    bool game[10][10];
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
};



queue<Ga> que;


void bfs(int x,int y,int dp)
{

}



int main()
{
    freopen("in.txt","r",stdin);
    while(input())
    {
        bool flag=1;

    }
    return 0;
}
