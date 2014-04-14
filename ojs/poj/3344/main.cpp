#include <iostream>
#include <cstdio>

using namespace std;
const int maxn=10;
char board[maxn][maxn];
int nx,ny,drec;//0 for up 1 for right 2 for down 3 for left
int dx[5]= {-1,0,1,0};
int dy[5]= {0,1,0,-1};

bool input()
{
    char tmp;
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            scanf("%c",&tmp);
            if(tmp=='\n')
            {
                j--;
                continue;
            }
            if(tmp=='-') return 0;
            switch(tmp)
            {
            case '.':
                board[i][j]=0;
                break;
            case '^':
                drec=0;
                nx=i;
                ny=j;
                board[i][j]='^';
                break;
            case 'v':
                drec=2;
                nx=i;
                ny=j;
                board[i][j]='v';
                break;
            case '<':
                drec=3;
                nx=i;
                ny=j;
                board[i][j]='<';
                break;
            case '>':
                drec=1;
                nx=i;
                ny=j;
                board[i][j]='>';
                break;
            default :
                board[i][j]=tmp;
            }
        }
    return 1;
}

void turn(char *cmd)
{
    switch(cmd[0])
    {
    case 'l':
        drec--;
        break;
    case 'r':
        drec++;
        break;
    case 'b':
        drec+=2;
        break;
    }
    if(drec<0) drec+=4;
    if(drec>3) drec-=4;
    switch(drec)
    {
        case 0:board[nx][ny]='^';break;
        case 1:board[nx][ny]='>';break;
        case 2:board[nx][ny]='v';break;
        case 3:board[nx][ny]='<';break;
    }
}

bool moveOne()
{
    int kx=nx,ky=ny;
    char t1=0,t2;
    if(nx+dx[drec]>7||nx+dx[drec]<0) return 0;
    if(ny+dy[drec]>7||ny+dy[drec]<0) return 0;
    while(1)
    {
        t2=board[kx][ky];
        board[kx][ky]=t1;
        t1=t2;
        kx+=dx[drec];
        ky+=dy[drec];
        if(kx<0||kx>7||ky<0||ky>7) break;
        if(board[kx][ky]==0)
        {
            board[kx][ky]=t1;
            break;
        }
    }
    nx+=dx[drec];
    ny+=dy[drec];
    return true;
}

void print()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(board[i][j])
                putchar(board[i][j]);
            else putchar('.');
        }
        putchar('\n');
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    char tmp[10];
    int step;
    while(input())
    {
        while(1)
        {
            scanf("%s",tmp);
            if(tmp[0]=='#') break;
            if(tmp[0]=='m')
            {
                scanf("%d",&step);
                while(step--) moveOne();
            }
            else
            {
                scanf("%s",tmp);
                turn(tmp);
            }

        }
        print();
        putchar('\n');
    }
    return 0;
}
