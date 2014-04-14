#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    int n=71,m=1501;
    int nxt;
    int cnt=0;
    printf("%d %d\n",n,m);

    for(int i=0;i<n;i++)
        for(int j=0;j<22;j++)
        {
            nxt=j*2+!(i%2);
            if(i!=nxt)
            {
                cnt++;
                if(cnt>m)break;
                printf("%d %d\n",i,nxt);
            }
        }
  //  cout<<m<<endl;
    return 0;
}
