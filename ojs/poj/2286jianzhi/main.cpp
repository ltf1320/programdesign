//ids,Board.set was wrong ,which caused 1 hour to debug...

#include <iostream>
#include <cstdlib>
#include<cstring>
#include <cstdio>
using namespace std;

int maxd,center,num;
char result[10000];//zhan
const int size=7;
const int msize=24;
class Board
{
public:
    Board()
    {
        set();
        memset(tu,0,sizeof(tu));
    }
    Board(const Board &a)
    {
        set();
        memset(tu,0,sizeof(tu));
        for(int i=0; i<size; ++i)
            for(int j=0; j<size; ++j)
                tu[i][j]=a.tu[i][j];
    }
    void set()
    {
        int k=0;
        iter[k++]=&tu[0][2];
        iter[k++]=&tu[0][4];
        iter[k++]=&tu[1][2];
        iter[k++]=&tu[1][4];
        for(int i=0; i<size; ++i)
            iter[k++]=&tu[2][i];
        iter[k++]=&tu[3][2];
        iter[k++]=&tu[3][4];
        for(int i=0; i<size; ++i)
            iter[k++]=&tu[4][i];
        iter[k++]=&tu[5][2];
        iter[k++]=&tu[5][4];
        iter[k++]=&tu[6][2];
        iter[k++]=&tu[6][4];
    }
    bool read()
    {
        memset(tu,0,sizeof(tu));
        cin>>tu[0][2];
        if(tu[0][2]==0) return 0;
        for(int i=1; i<msize; ++i)
            cin>>*iter[i];
        return 1;
    }
    int tu[10][10];
    int *iter[25];
};

int count(const Board &a)
{
    int num[5]= {0};
    for(int i=0; i<3; ++i)
        num[a.tu[2][i+2]]++;
    num[a.tu[3][2]]++;
    num[a.tu[3][4]]++;
    for(int i=0; i<3; ++i)
        num[a.tu[4][i+2]]++;
    return max(max(num[1],num[2]),num[3]);
}

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



bool ids(int d,const Board &now,int pre)
{
    int maxn=count(now);
    if(d==maxd)
    {
        if(maxn==8)
        {
            center=now.tu[2][2];
            num=0;
            return 1;
        }
        else return 0;
    }
    if(maxd-d<8-maxn)
    {
        return 0;
    }
    for(int i=0; i<8; ++i)
    {
        if((i==0&&pre==5)||(pre==0&&i==5)) continue;
        if((i==1&&pre==4)||(pre==1&&i==4)) continue;
        if((i==2&&pre==7)||(pre==2&&i==7)) continue;
        if((i==3&&pre==6)||(pre==3&&i==6)) continue;
        Board next(move(now,i));
        if(ids(d+1,next,i))
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
        if(count(start)==8)
        {
            cout<<"No moves needed"<<endl;
            cout<<start.tu[2][2]<<endl;
            continue;
        }
        while(!ids(0,start,-100))
            maxd++;
        for(int i=num-1; i>=0; --i)
            cout<<result[i];
        cout<<endl<<center<<endl;
    }
    return 0;
}
