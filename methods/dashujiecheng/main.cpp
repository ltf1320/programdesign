#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=3000;
int num[maxn];

int main()
{
    int c,tem;
    freopen("out.txt","w",stdout);
    for(int n=1; n<1000; n++)
    {
        memset(num,0,sizeof(num));
        num[0]=1;
        for(int i=2; i<=n; ++i)
        {
            c=0;
            for(int j=0; j<maxn-1; ++j)
            {
                tem=num[j]*i+c;
                num[j]=tem%10;
                c=tem/10;
            }
        }
        int k;
        for(k=maxn-1; k>=0; k--)
            if(num[k]!=0) break;
//    cout<<num[0]<<num[1]<<num[2]<<endl;
        cout<<n<<"   ";
        for(int i=k; i>=0; i--)
            cout<<num[i];
        cout<<endl;
    }
    return 0;
}
