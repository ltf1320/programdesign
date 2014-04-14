#include <iostream>
#include <cstring>
using namespace std;

struct Areas
{
    Areas():num(1)
    {
        memset(block,0,sizeof(block));
    }
    int block[30];
    int num;
};

struct Blocks
{
    Blocks():area(0),seq(1) {}
    int area;
    int seq;
    void movetoinitial(Blocks block[],Areas areas[])
    {
        areas[area].block[seq]=0;
        areas[area].num--;
    }
    void moveonto(int target,Blocks blocks[],Areas areas[])
    {
        if(block1==target||blocks[block1].area==blocks[target].area)
            break;
        int ar=blocks[block1].area;                         //
        for(int i=areas[ar].num-1; i>blocks[block1].seq; --i)
        {
            blocks[areas[ar].block[i]].movetoinitial(Blocks block[],Areas areas[]);
        }
        areas[ar].num--;

    }
};


int main()
{
    int n;
    cin>>n;
    Blocks blocks[30];
    Areas areas[30];
    for(int i=0; i<n; ++i)
        blocks[i].area=i;
    string cmd;
    cin>>cmd;
    int block1,block2;
    while(cmd!=string("quit"))
    {
        if(cmd==string("move"))
        {
            cin>>block1>>cmd;
            if(cmd==string("onto"))
            {
                cin>>block2;
                blocks[block1].moveonto(block2,blocks,areas);
            }
        }
    }
    return 0;
}
