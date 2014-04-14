#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=1000+100;
int N,P,C;
int ps[maxn];


int main()
{
    freopen("in.txt","r",stdin);
    int tmp,res;
    while(~scanf("%d%d%d",&N,&P,&C))
    {
        memset(ps,0,sizeof(ps));
        for(int i=0;i<N;i++)
        {
            scanf("%d",&tmp);
            ps[tmp]++;
        }
        tmp=0;res=0;
        for(int i=1;i<P;i++)
        {
            int j;
            tmp=0;
            for(j=i;j<P;j++)
            {
                if(tmp+ps[j]<=C)
                    tmp+=ps[j];
                else break;
            }
            res=max(res,j-i);
        }
        printf("%d\n",res);
    }
    return 0;
}
