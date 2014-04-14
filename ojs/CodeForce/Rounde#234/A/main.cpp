#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=12;
char tmp[maxn];
bool yes[maxn];
int ans[maxn];

int main()
{
  //  freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    int cnt,p;
    gets(tmp);
    while(t--)
    {
        cnt=0;
        gets(tmp);
        for(int i=1;i<=12;i++)
            if(12%i==0)
            {
                memset(yes,-1,sizeof(yes));
                p=0;
                for(int j=0;j<i;j++)
                    for(int k=0;k<12/i;k++)
                    {
                        if(tmp[p]=='O')
                            yes[k]=0;
                        p++;
                    }
                for(int k=0;k<12/i;k++)
                    if(yes[k])
                    {
                        ans[cnt++]=i;
                        break;
                    }
            }
        printf("%d",cnt);
        for(int i=0;i<cnt;i++)
            printf(" %dx%d",ans[i],12/ans[i]);
        puts("");
    }
    return 0;
}
