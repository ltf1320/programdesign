#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5;
int board[maxn][maxn];
bool end;
//0 for .,1for X, 2for Y,3for T;

void input()
{
    end=1;
    char tmp;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            scanf("%c",&tmp);
            switch(tmp)
            {
            case '.':
                board[i][j]=0;
                end=0;
                break;
            case 'X':
                board[i][j]=1;
                break;
            case 'O':
                board[i][j]=2;
                break;
            case 'T':
                board[i][j]=3;
                break;
            case '\n':
                j--;
                break;
            }
        }
}

int judger(int a)
{
    for(int i=0; i<4; i++)
    {
        if(board[a][i]!=1&&board[a][i]!=3) break;
        if(i==3) return 1;
    }
    for(int i=0; i<4; i++)
    {
        if(board[a][i]!=2&&board[a][i]!=3) break;
        if(i==3) return 2;
    }
    return 0;
}

int judgec(int a)
{
    for(int i=0; i<4; i++)
    {
        if(board[i][a]!=1&&board[i][a]!=3) break;
        if(i==3) return 1;
    }
    for(int i=0; i<4; i++)
    {
        if(board[i][a]!=2&&board[i][a]!=3) break;
        if(i==3) return 2;
    }
    return 0;
}

int judgedj()
{
    for(int i=0; i<4; i++)
    {
        if(board[i][i]!=1&&board[i][i]!=3) break;
        if(i==3) return 1;
    }
    for(int i=0; i<4; i++)
    {
        if(board[i][i]!=2&&board[i][i]!=3) break;
        if(i==3) return 2;
    }
    for(int i=0; i<4; i++)
    {
        if(board[i][3-i]!=1&&board[i][3-i]!=3) break;
        if(i==3) return 1;
    }
    for(int i=0; i<4; i++)
    {
        if(board[i][3-i]!=2&&board[i][3-i]!=3) break;
        if(i==3) return 2;
    }
    return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    int res,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        res=0;
        cas++;
        input();
        for(int i=0; i<4; i++)
        {
            if(res=judgec(i))
                break;
            if(res=judger(i))
                break;
        }
        if(!res) res=judgedj();
        if(res)
        {
            if(res==1) printf("Case #%d: X won\n",cas);
            else if(res==2) printf("Case #%d: O won\n",cas);
        }
        else if(end==0) printf("Case #%d: Game has not completed\n",cas);
        else printf("Case #%d: Draw\n",cas);
    }
    return 0;
}
