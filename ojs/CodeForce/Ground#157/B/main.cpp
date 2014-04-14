#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int sq[5][5];

int x[5];
int y[5];
int t,ks;
int find()
{
    int res;
    for(int i=0; i<3; i++)
    {
        res=0;
        for(int j=0; j<3; j++)
        {
            if(sq[i][j]==0) break;
            res+=sq[i][j];
            if(j==2) return res;
        }
    }
    for(int i=0; i<3; i++)
    {
        res=0;
        for(int j=0; j<3; j++)
        {
            if(sq[j][i]==0) break;
            res+=sq[j][i];
            if(j==2) return res;
        }
    }
    return 0;
}

void fillx(int x,int y)
{
    if(sq[x][y]) return;
    bool k=0;
    int ss=ks;
    for(int i=0; i<3; i++)
        if(sq[i][y]==0)
        {
            if(k) return;
            k=1;
        }
        else ss-=sq[i][y];
    sq[x][y]=ss;
}

void filly(int x,int y)
{
    if(sq[x][y]) return;
    bool k=0;
    int ss=ks;
    for(int i=0; i<3; i++)
        if(sq[x][i]==0)
        {
            if(k) return;
            k=1;
        }
        else ss-=sq[x][i];
    sq[x][y]=ss;
}

void print()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
            printf("%d ",sq[i][j]);
        printf("%d\n",sq[i][2]);
    }
}

int main()
{
    int sum=0;
  //  freopen("in.txt","r",stdin);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            scanf("%d",&sq[i][j]);
            sum+=sq[i][j];
            if(sq[i][j]==0)
            {
                x[t]=i;
                y[t++]=j;
            }
        }
    if(sq[0][0]==0&&sq[1][1]==0&&sq[2][2]==0)
    {
        sq[0][0]=(sq[0][2]+sq[2][0]+sq[1][2]-sq[0][1])/2;
        ks=find();
        fillx(1,1);
        filly(2,2);
    }
    else if(sq[0][2]==0&&sq[1][1]==0&&sq[2][0]==0)
    {
        sq[0][2]=(sq[1][0]+sq[0][0]+sq[2][2]-sq[0][1])/2;
        ks=find();
        fillx(1,1);
        filly(2,0);
    }
    else
    {
        ks=find();
        for(int i=0; i<3; i++)
        {
            fillx(x[i],y[i]);
        }
        for(int i=0; i<3; i++)
        {
            filly(x[i],y[i]);
        }
    }
    print();
    return 0;
}
