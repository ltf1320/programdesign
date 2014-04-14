#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10;
int map[maxn][maxn];
bool ted[maxn][maxn];
int uc[maxn][maxn];
int ur[maxn][maxn];
int us[maxn][maxn];

int tn;

int ges(int i,int j)
{
    return i/3*3+j/3;
}

bool find(int i,int j,int n)
{
    if(n==tn)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                printf("%d",map[i][j]);
            }
            putchar('\n');
        }
        return true;
    }
    if(j>=9)
    {
        i++;
        j=0;
    }
    if(i>=9) return false;
    if(ted[i][j])
    {
        for(int k=1;k<10;k++)
        {
            if(!uc[i][k]&&!ur[j][k]&&!us[ges(i,j)][k])
            {
                uc[i][k]=1;
                ur[j][k]=1;
                us[ges(i,j)][k]=1;
                map[i][j]=k;
                if(find(i,j+1,n+1)) return true;
                uc[i][k]=0;
                ur[j][k]=0;
                us[ges(i,j)][k]=0;
                map[i][j]=0;
            }
        }
    }
    else if(find(i,j+1,n)) return true;
    return false;
}

void input()
{
    char tmp;
    int tt;
    tn=0;
    memset(ted,0,sizeof(ted));
    memset(uc,0,sizeof(uc));
    memset(ur,0,sizeof(ur));
    memset(us,0,sizeof(us));
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            scanf("%c",&tmp);
            if(tmp=='\n')
            {
                j--;
                continue;
            }
            tt=tmp-'0';
            map[i][j]=tt;
            if(tt)
            {
                uc[i][tt]=1;
                ur[j][tt]=1;
                us[ges(i,j)][tt]=1;
            }
            else
            {
                tn++;
                ted[i][j]=1;
            }
        }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        find(0,0,0);
    }
    return 0;
}
