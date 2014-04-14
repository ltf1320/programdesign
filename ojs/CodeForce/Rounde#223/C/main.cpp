#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=1000000+10;
int nl=0,nr=0;
char str[maxn];
int len;
int has[maxn];
int ll[maxn],rr[maxn];
int main()
{
  //  freopen("in.txt","r",stdin);
    gets(str+1);
    len=strlen(str+1);
    for(int i=1;i<=len;i++)
    {
        has[i]=has[i-1];
        ll[i]=ll[i-1];
        rr[i]=rr[i-1];
        if(str[i]==')')
        {
            rr[i]++;
            if(nl)
            {
                nl--;
                has[i]++;
            }
            else nr++;
        }
        else
        {
            ll[i]++;
            nl++;
        }
    }
    int m,l,r;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&l,&r);
        int res=has[r]-has[l-1]-min(rr[r]-rr[l-1],ll[l-1]-has[l-1]);
        printf("%d\n",res*2);
    }
    return 0;
}
