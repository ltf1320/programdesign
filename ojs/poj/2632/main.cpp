#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=200;

int ware[maxn][maxn];

bool skip;

struct robot
{
    static const int N=0,E=1,S=2,W=3;
    int x,y,direc,num;

    void reset(int n,int xx,int yy,char d)
    {
        x=xx;
        y=yy;
        ware[x][y]=n;
        num=n;
        switch(d)
        {
            case 'N':direc=N;break;
            case 'E':direc=E;break;
            case 'S':direc=S;break;
            case 'W':direc=W;break;
        }
    }
    void turn(char f,int times)
    {
        switch(f)
        {
            case 'L':
                direc-=times;
                if(direc<0) direc%=4;
                if(direc<0) direc+=4;
                break;
            case 'R':
                direc+=times;
                if(direc>4) direc%=4;
        }
    }
    void forword(int step)
    {
        int dx,dy;
        switch(direc)
        {
            case N:dy=1;dx=0;break;
            case E:dy=0;dx=1;break;
            case S:dy=-1;dx=0;break;
            case W:dy=0;dx=-1;break;
        }
        while(step--)
        {
            ware[x][y]=0;
            x+=dx;
            y+=dy;
            if(ware[x][y]>0)
            {
                printf("Robot %d crashes into robot %d\n",num,ware[x][y]);
                skip=1;
                break;
            }
            if(ware[x][y]==-1)
            {
                printf("Robot %d crashes into the wall\n",num);
                skip=1;
                break;
            }
            ware[x][y]=num;
        }
    }
}rob[maxn];


int main()
{
    freopen("in.txt","r",stdin);
    int K;
    int A,B;
    int M,N;
    int x,y;
    char direc;
    int num,step;
    char ctrl;
    for(int i=0;i<maxn;i++)
    {
        ware[i][0]=-1;
        ware[0][i]=-1;
    }
    scanf("%d",&K);
    while(K--)
    {
        scanf("%d%d",&A,&B);
        for(int i=1;i<=A;i++)   //Â©ÁËµÈÓÚºÅ,2A
            for(int j=1;j<=B;j++)
                ware[i][j]=0;
        for(int i=1;i<=A;i++)
            ware[i][B+1]=-1;
        for(int i=1;i<=B;i++)
            ware[A+1][i]=-1;
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d%c%c",&x,&y,&ctrl,&direc);//ctrl³Ôµô¿Õ¸ñ
            rob[i].reset(i,x,y,direc);
        }
        skip=0;
        for(int i=0;i<M;i++)
        {
            scanf("%d%c%c%d",&num,&direc,&ctrl,&step);//direc³Ôµô¿Õ¸ñ
            if(skip) continue;
            if(ctrl=='F')
            {
                rob[num].forword(step);
            }
            else rob[num].turn(ctrl,step);
        }
        if(skip) continue;
        printf("OK\n");
    }
    return 0;
}
