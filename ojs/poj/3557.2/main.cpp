#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=20+5;

double dp[maxn][1<<21];
queue<int> que[2];

int count(int st)
{
    int res=0;
    for(int i=0;i<N;i++)
        if(st&(1<<i))
            res++;
    return res;
}

void work()
{
    dp[0][1]=1;
    int now,nst;
    int cnt;
    for(int i=0;i<N;i++)
    {
        int base=1<<i;
        for(int st=(1<<i)-1;st<(1<<N);st+=base)
        {
            int end=(1<<(N-i));
            for(int nxt=0;nxt<end;nxt++)
            {
                nxt<<=i+1;
                cnt=count(nxt);
                nst=st|nxt;
                dp[i+1][nst]=dp[i][st]*pp[]
            }
        }
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
