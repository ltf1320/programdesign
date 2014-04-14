#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=50+10;
int N;
bool map[maxn][maxn];

void input()
{
    char tmp[maxn];
    gets(tmp);
    for(int i=0;i<N;i++)
    {
        gets(tmp);
        for(int j=0;j<N;j++)
            if(tmp[j]=='#') map[i][j]=1;
            else map[i][j]=0;
    }
}

void print()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

bool pd(int a,int b,int l)
{
    if(l==0) return false;
    for(int i=a-1;i>=a-l;i--)
        if(map[i][b]&&!map[i][b-1]&&!map[i][b+1])
            continue;
        else return false;
    if(a-l-1>=0&&map[a-l-1][b]) return false;

    for(int i=a+1;i<=a+l;i++)
        if(map[i][b]&&!map[i][b-1]&&!map[i][b+1])
            continue;
        else return false;
    if(a+l+1<N&&map[a+l+1][b]) return false;

    for(int i=b-1;i>=b-l;i--)
        if(map[a][i]&&!map[a+1][i]&&!map[a-1][i])
            continue;
        else return false;
    if(b-l-1>=0&&map[a][b-l-1]) return false;

    for(int i=b+1;i<=b+l;i++)
        if(map[a][i]&&!map[a+1][i]&&!map[a-1][i])
            continue;
        else return false;
    if(b+l+1<N&&map[a][b+l+1]) return false;
    return true;
}

bool judge(int a,int b)
{
    int maxr=min(a,b);
    if(N-a-1<maxr) maxr=N-a-1;
    if(N-b-1<maxr) maxr=N-b-1;
    for(int i=1;i<=maxr;i++)
    {
        if(map[a][b]&&pd(a,b,i)) return true;
    }
    return false;
}


int work()
{
    int res=0;
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            if(judge(i,j)) res++;
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(!N) break;
        input();
//        print();
        printf("%d\n",work());
    }
    return 0;
}
