#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxr=10000+10;
const int maxc=100;
char grid[maxr][maxc];
int pi[maxr][maxc];
int R,C;

void pre()
{
    int p,k;
    for(int i=0;i<R;i++)
    {
        k=-1;
        pi[i][0]=-1;
        for(p=1;p<C;p++)
        {
            while(k!=-1&&grid[0][k+1]!=grid[i][p])
                k=pi[i][k];
            if(grid[0][k+1]==grid[i][p])
                k++;
            pi[i][p]=k;
        }
    }
}

void input()
{
    for(int i=0;i<R;i++)
        scanf("%d",&grid[i]);
}

int main()
{
    while(~scanf("%d%d",&R,&C))
    {
        input();
    }
    return 0;
}
