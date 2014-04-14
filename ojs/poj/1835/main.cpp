//蛋疼的模拟题，9A
//空间想象比较麻烦

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int dd[6][3]={{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
struct At
{
    int x,y,z;
    int dir,ndir;
    void reset()
    {
        dir=0;
        ndir=2;
        x=y=z=0;
    }
    void turn(string drec)
    {
        if(drec==string("back"))
        {
            dir+=3;
            dir%=6;
        }
        if(drec==string("right"))
        {
            if(ndir>=3)
            {
                ndir-=3;
                turn(string("left"));
                ndir+=3;
                return;
            }
            if(ndir!=1&&ndir!=4)
            {
                dir+=1;
                if(dir==6) dir=0;
                if(dir==ndir||dir==ndir+3||dir==ndir-3)
                    dir+=1;
                if(dir==6) dir=0;
            }
            else
            {
                dir-=1;
                if(dir<0) dir+=6;
                if(dir==ndir||dir==ndir+3||dir==ndir-3)
                    dir-=1;
                if(dir<0) dir+=6;
            }
        }
        if(drec==string("left"))
        {
            if(ndir>=3)
            {
                ndir-=3;
                turn(string("right"));
                ndir+=3;
                return;
            }
            if(ndir!=1&&ndir!=4)
            {
                dir-=1;
                if(dir<0) dir+=6;
                if(dir==ndir||dir==ndir+3||dir==ndir-3)
                    dir-=1;
                if(dir<0) dir+=6;
            }
            else
            {
                dir+=1;
                if(dir==6) dir=0;
                if(dir==ndir||dir==ndir+3||dir==ndir-3)
                    dir+=1;
                if(dir==6) dir=0;
            }
        }
        if(drec==string("up"))
        {
            int tmp;
            tmp=dir+3;
            tmp%=6;
            dir=ndir;
            ndir=tmp;
        }
        if(drec==string("down"))
        {
            int tmp;
            tmp=ndir+3;
            tmp%=6;
            ndir=dir;
            dir=tmp;
        }
    }
    void forword(int n)
    {
        x+=n*dd[dir][0];
        y+=n*dd[dir][1];
        z+=n*dd[dir][2];
    }
};
At as;

int main()
{
    freopen("in.txt","r",stdin);
    int T,n;
    scanf("%d",&T);
    string tmp;
    int step;
    while(T--)
    {
        scanf("%d",&n);
        as.reset();
        while(n--)
        {
            cin>>tmp;
            scanf("%d",&step);
            as.turn(tmp);
            as.forword(step);
        }
        printf("%d %d %d %d\n",as.x,as.y,as.z,as.dir);
    }
    return 0;
}
