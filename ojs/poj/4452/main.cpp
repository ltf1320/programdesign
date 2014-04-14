#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N,ti,K;

const int dx[4]= {-1,0,1,0};
const int dy[4]= {0,1,0,-1};

int taround(int a)
{
    switch(a)
    {
    case 0:
        return 2;
    case 1:
        return 3;
    case 2:
        return 0;
    case 3:
        return 1;
    }
    return -1000;
}

int getDir(char ch)
{
    switch(ch)
    {
    case 'N':
        return 0;
    case 'E':
        return 1;
    case 'S':
        return 2;
    case 'W':
        return 3;
    }
    return -1000;
}

struct Man
{
    int x,y;
    int dir,s,t;
    void read(int xx,int yy)
    {
        x=xx;
        y=yy;
        char ch=getchar();
        scanf("%c",&ch);
        dir=getDir(ch);
        scanf("%d%d",&s,&t);
    }
    void go()
    {
        x+=s*dx[dir];
        if(x<=0)
        {
            x=2-x;
            dir=taround(dir);
        }
        if(x>=N+1)
        {
            x=2*N-x;
            dir=taround(dir);
        }
        y+=s*dy[dir];
        if(y<=0)
        {
            y=2-y;
            dir=taround(dir);
        }
        if(y>=N+1)
        {
            y=2*N-y;
            dir=taround((dir));
        }

    }
    void turnleft()
    {
        if(ti%t==0)
        {
            dir--;
            if(dir<0) dir+=4;
        }
    }
    bool same(Man &a)
    {
        if(x==a.x&&y==a.y) return true;
        return false;
    }
    void change(Man &a)
    {
        int t;
        t=dir;
        dir=a.dir;
        a.dir=t;
    }
    void print()
    {
        cout<<x<<" "<<y<<endl;
    }
};


int main()
{
    freopen("in.txt","r",stdin);
    Man ma,mb;
    while(~scanf("%d",&N))
    {
        if(!N) break;
        ma.read(1,1);
        mb.read(N,N);
        scanf("%d",&K);
        ti=0;
        while(ti<K)
        {
            ma.go();
            mb.go();
            ti++;
            if(ma.same(mb))
            {
                ma.change(mb);
                continue;
            }
            ma.turnleft();
            mb.turnleft();
        }
        ma.print();
        mb.print();
    }
    return 0;
}
