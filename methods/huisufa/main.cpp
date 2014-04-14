//lrj竞赛入门P123,回溯法

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int n=8;
bool result[10][10];
int C[10];
int num=0;
void huisu(int now)
{
    if(now==n)
    {
        num++;
        for(int i=0;i<n;++i)
            result[C[i]][i]=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                cout<<result[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        memset(result,0,sizeof(result));
    }
    for(int i=0;i<n;++i)
    {
        bool ok=1;
        for(int j=0;j<now;++j)
            if(C[j]==i||C[j]-j==i-now||C[j]+j==i+now) ok=0;
        if(ok)
        {
            C[now]=i;
            huisu(now+1);
        }
    }
}

int main()
{
    freopen("out.txt","w",stdout);
    memset(result,0,sizeof(result));
    huisu(0);
    cout<<num<<endl;
    return 0;
}
