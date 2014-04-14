#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5;
int mat[maxn][maxn];
int mat2[maxn][maxn];

bool used[20];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,r1,r2;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(used,0,sizeof(used));
        scanf("%d",&r1);
        r1--;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                scanf("%d",&mat[i][j]);
        for(int i=0;i<4;i++)
            used[mat[r1][i]]=1;
        scanf("%d",&r2);
        r2--;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                scanf("%d",&mat2[i][j]);
        int res,cnt=0;
        for(int i=0;i<4;i++)
            if(used[mat2[r2][i]])
            {
                res=mat2[r2][i];
                cnt++;
            }
        printf("Case #%d: ",cas);
        if(cnt==0)
            printf("Volunteer cheated!");
        else if(cnt==1)
            printf("%d",res);
        else printf("Bad magician!");
        puts("");
    }
    return 0;
}
