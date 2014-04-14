#include <iostream>
#include <cstdio>


using namespace std;
const int maxn=10;

int s,n;
int len;

bool ss[11][10]=
{
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1},
};
int nums[maxn];

int getlen(int n)
{
    int len=0;
    int tmp=n;
    while(tmp/=10)
    {
        len++;
    }
    nums[len]=n%10;
    for(int i=len-1; i>=0; i--)
        nums[i]=(n/=10)%10;
    return len+1;
}

void pline1(int n)
{
    for(int i=0; i<len; i++)
    {
        putchar(' ');
        for(int j=0; j<s; j++)
            if(ss[nums[i]][n])
                putchar('-');
            else putchar(' ');
        putchar(' ');
        putchar(' ');
    }
    putchar('\n');
}

void pline2(int n)
{
    for(int i=0; i<len; i++)
    {
        if(ss[nums[i]][n])
            putchar('|');
        else putchar(' ');
        for(int j=0;j<s;j++)
            putchar(' ');
        if(ss[nums[i]][n+1])
            putchar('|');
        else putchar(' ');
        putchar(' ');
    }
    putchar('\n');
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&s,&n))
    {
        if(s==0&&n==0) break;
        len=getlen(n);
        pline1(0);
        for(int i=0;i<s;i++)
            pline2(1);
        pline1(3);
        for(int i=0;i<s;i++)
            pline2(4);
        pline1(6);
        putchar('\n');
    }
    return 0;
}
