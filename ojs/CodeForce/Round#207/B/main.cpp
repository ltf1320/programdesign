#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000*3+1000;
int N,M;
int res[maxn];

int main()
{
    scanf("%d%d",&N,&M);
    int p;
    int now[5];
    for(int i=0;i<M;i++)
    {
        p=1;
        scanf("%d%d%d",&now[0],&now[1],&now[2]);
        bool flag=0;
        for(int j=0;j<3;j++)
            if(res[now[j]])
            {
                flag=1;
                for(int k=0;k<3;k++)
                {
                    if(j==k) continue;
                    if(p==res[now[j]])p++;
                    res[now[k]]=p++;
                }
                break;
            }
        if(!flag)
        {
            for(int j=0;j<3;j++)
                res[now[j]]=j+1;
        }
    }
    printf("%d",res[1]);
    for(int i=2;i<=N;i++)
        printf(" %d",res[i]);
    puts("");
    return 0;
}
