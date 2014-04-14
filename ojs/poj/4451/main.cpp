#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=1000+10;
int N,M,K,P;

int CP[maxn];
bool PS[maxn][maxn];


int main()
{
    freopen("in.txt","r",stdin);
    char t1[20],t2[20];
    int n1,n2;
    int res;
    while(~scanf("%d%d%d",&N,&M,&K))
    {
        if(N==0&&M==0&&K==0) break;
        scanf("%d",&P);
        memset(PS,0,sizeof(PS));
        res=0;
        for(int i=1;i<=M;i++)
            CP[i]=N;
        for(int i=0;i<P;i++)
        {
            scanf("%s%d%s%d",t1,&n1,t2,&n2);
            if(t1[0]=='c')
                CP[n2]-=1;
            else PS[n1][n2]=1;
        }
        for(int i=1;i<=M;i++)
        {
            for(int j=1;j<=K;j++)
            {
                if(!PS[i][j])
                    res+=CP[i];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
