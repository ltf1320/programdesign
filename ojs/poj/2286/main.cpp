#include <iostream>
#include <cstdlib>
#include<cstring>
#include <cstdio>
using namespace std;

int maxd,center,num;
char result[10000];//Êä³öÕ»
const int size=7;

class Board
{
public:
    Board()
    {
        memset(tu,0,sizeof(tu));
    }
    Board(const Board &a)
    {
        memset(tu,0,sizeof(tu));
        for(int i=0; i<size; ++i)
            for(int j=0; j<size; ++j)
                tu[i][j]=a.tu[i][j];
    }
    bool read()
    {
        memset(tu,0,sizeof(tu));
        cin>>tu[0][2];
        if(tu[0][2]==0) return 0;
        cin>>tu[0][4]>>tu[1][2]>>tu[1][4];
        for(int i=0; i<size; ++i)
            cin>>tu[2][i];
        cin>>tu[3][2]>>tu[3][4];
        for(int i=0; i<size; ++i)
            cin>>tu[4][i];
        cin>>tu[5][2]>>tu[5][4]>>tu[6][2]>>tu[6][4];
        return 1;
    }
    int tu[10][10];
};

Board move(const Board &front,const int type)
{
    int temp;
    Board now(front);
    switch(type)
    {
    case 0:
        temp=now.tu[0][2];
        for(int i=0; i<6; ++i)
        {
            now.tu[i][2]=now.tu[i+1][2];
        }
        now.tu[6][2]=temp;
        break;
    case 1:
        temp=now.tu[0][4];
        for(int i=0; i<6; ++i)
        {
            now.tu[i][4]=now.tu[i+1][4];
        }
        now.tu[6][4]=temp;
        break;
    case 2:
        temp=now.tu[2][6];
        for(int i=6; i>0; --i)
        {
            now.tu[2][i]=now.tu[2][i-1];
        }
        now.tu[2][0]=temp;
        break;
    case 3:
        temp=now.tu[4][6];
        for(int i=6; i>0; --i)
        {
            now.tu[4][i]=now.tu[4][i-1];
        }
        now.tu[4][0]=temp;
        break;
    case 4:
        temp=now.tu[6][4];
        for(int i=6; i>0; --i)
        {
            now.tu[i][4]=now.tu[i-1][4];
        }
        now.tu[0][4]=temp;
        break;
    case 5:
        temp=now.tu[6][2];
        for(int i=6; i>0; --i)
        {
            now.tu[i][2]=now.tu[i-1][2];
        }
        now.tu[0][2]=temp;
        break;
    case 6:
        temp=now.tu[4][0];
        for(int i=0; i<6; ++i)
        {
            now.tu[4][i]=now.tu[4][i+1];
        }
        now.tu[4][6]=temp;
        break;
    case 7:
        temp=now.tu[2][0];
        for(int i=0; i<6; ++i)
        {
            now.tu[2][i]=now.tu[2][i+1];
        }
        now.tu[2][6]=temp;
        break;
    default:
        cout<<"error:move()"<<endl;
        exit(-1);
    }
    return now;
}

int cor(const Board &a)
{
    int r=a.tu[2][2];
    bool ok(1);
    if(a.tu[2][3]!=r||a.tu[2][4]!=r) ok=0;
    if(a.tu[3][2]!=r||a.tu[3][4]!=r) ok=0;
    for(int i=2; i<5; ++i)
        if(a.tu[4][i]!=r) ok=0;
    if(ok)
        return r;
    else return 0;
}


bool ids(int d,const Board &now)
{
    if(d==maxd)
    {
        center=cor(now);
        if(center)
        {
            num=0;
            return 1;
        }
        else return 0;
    }
    for(int i=0; i<8; ++i)
    {
        Board next(move(now,i));
        if(ids(d+1,next))
        {
            result[num++]='A'+i;
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(1)
    {
        maxd=1;
        Board start;
        if(!start.read()) return 0;
        center=cor(start);
        if(center)
        {
            cout<<"No moves needed"<<endl;
            cout<<center<<endl;
            continue;
        }
        while(!ids(0,start))
            maxd++;
        for(int i=num-1; i>=0; --i)
            cout<<result[i];
        cout<<endl<<center<<endl;
    }
    return 0;
}
