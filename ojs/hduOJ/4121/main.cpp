#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=12;
int N;
int map[maxn][maxn];
//1 for ½«£¬2 for ³µ£¬3 for Âí£¬4 for ÅÜ
int getType(char ch)
{
    switch(ch)
    {
    case 'G':
        return 1;
    case 'R':
        return 2;
    case 'H':
        return 3;
    case 'C':
        return 4;
    }
    return -100;
}
struct Piece
{
    int type,x,y;
};
Piece pes[maxn];

int cgo[maxn][maxn];
void sigh(int type,int x,int y)
{
    switch(type)
    {
    case 1:
        for(int i=x-1; i>=1; i--)
        {
            cgo[i][y]=2;
            if(map[i][y]) break;
        }
        break;
    case 2:
        for(int i=x+1; i<=10; i++)
        {
            cgo[i][y]=1;
            if(map[i][y]) break;
        }
        for(int i=x-1; i>=1; i--)
        {
            cgo[i][y]=1;
            if(map[i][y]) break;
        }
        for(int i=y+1; i<=9; i++)
        {
            cgo[x][i]=1;
            if(map[x][i]) break;
        }
        for(int i=y-1; i>=1; i--)
        {
            cgo[x][i]=1;
            if(map[x][i]) break;
        }
        break;
    case 3:
        if(x>2&&!map[x-1][y])
            cgo[x-2][y+1]=cgo[x-2][y-1]=1;
        if(x<9&&!map[x+1][y])
            cgo[x+2][y+1]=cgo[x+2][y-1]=1;
        if(y<8&&!map[x][y+1])
            cgo[x+1][y+2]=cgo[x-1][y+2]=1;
        if(y>2&&!map[x][y-1])
            cgo[x+1][y-2]=cgo[x-1][y-2]=1;
        break;
    case 4:
        bool g=0;
        for(int i=x+1; i<=10; i++)
        {
            if(g)
                cgo[i][y]=1;
            if(map[i][y])
            {
                if(!g) g=1;
                else break;
            }
        }
        g=0;
        for(int i=x-1; i>=1; i--)
        {
            if(g)
                cgo[i][y]=1;
            if(map[i][y])
            {
                if(!g) g=1;
                else break;
            }
        }
        g=0;
        for(int i=y+1; i<=9; i++)
        {
            if(g)
                cgo[x][i]=1;
            if(map[x][i])
            {
                if(!g) g=1;
                else break;
            }
        }
        g=0;
        for(int i=y-1; i>=1; i--)
        {
            if(g)
                cgo[x][i]=1;
            if(map[x][i])
            {
                if(!g) g=1;
                else break;
            }
        }
        break;
    }
}

bool work()
{
    for(int i=1; i<=N; i++)
    {
        sigh(pes[i].type,pes[i].x,pes[i].y);
        if(cgo[pes[0].x][pes[0].y]==2) return 1;
    }
    if(pes[0].x>1)
        if(!cgo[pes[0].x-1][pes[0].y]) return 1;
    if(pes[0].x<3)
        if(!cgo[pes[0].x+1][pes[0].y]) return 1;
    if(pes[0].y<6)
        if(!cgo[pes[0].x][pes[0].y+1]) return 1;
    if(pes[0].y>4)
        if(!cgo[pes[0].x][pes[0].y-1]) return 1;
    return 0;
}

void input()
{
    char ch;
    char tmp[100];
    gets(tmp);
    for(int i=1; i<=N; i++)
    {
        while((ch=getchar())==' ');
        scanf("%d%d",&pes[i].x,&pes[i].y);
        map[pes[i].x][pes[i].y]=pes[i].type=getType(ch);
        gets(tmp);
    }
}

void init()
{
    memset(map,0,sizeof(map));
    memset(cgo,0,sizeof(cgo));
}

void printmap()
{
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=9; j++)
        {
            if(i==pes[0].x&&j==pes[0].y)
            {
                printf("J ");
                continue;
            }
            if(map[i][j]) printf("%d ",map[i][j]);
            else if(cgo[i][j]) printf("* ");
            else printf(". ");
        }
        putchar('\n');
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&pes[0].x,&pes[0].y))
    {
        if(N==0&&pes[0].x==0&&pes[0].y==0) break;
        init();
        input();
        if(!work()) printf("YES\n");
        else printf("NO\n");
        printmap();
    }
    return 0;
}
