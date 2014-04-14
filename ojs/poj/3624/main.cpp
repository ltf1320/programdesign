#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int N,M,w,d;
    int br[12881]={0};
 //   freopen("in.txt","r",stdin);
    cin>>N>>M;
    for(int i=0;i<N;++i)
    {
        cin>>w>>d;
        for(int j=M;j>=w;--j)
        {
            br[j]=max(br[j],br[j-w]+d);
        }
    }
    cout<<br[M];
    return 0;
}
