#include <cstdio>

using namespace std;

const int maxn=1000000+100;
int A[maxn];
int G[maxn];
char res[maxn];
int main()
{
 //   freopen("in.txt","r",stdin);
    int N;
    int balance=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d%d",&A[i],&G[i]);
    for(int i=0;i<N;i++)
    {
        if(balance+A[i]>500)
        {
            balance-=G[i];
            res[i]='G';
        }
        else
        {
            balance+=A[i];
            res[i]='A';
        }
    }
    res[N]=0;
    printf("%s\n",res);
}
