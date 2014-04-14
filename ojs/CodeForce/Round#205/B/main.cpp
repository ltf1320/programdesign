#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=200+10;
int num[maxn];
int c[maxn];
int res[maxn];
int r1,r2;
int k1,k2;
int main()
{
  //  freopen("in.txt","r",stdin);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N*2;i++)
    {
        scanf("%d",&num[i]);
        c[num[i]]++;
    }
    for(int i=0;i<N*2;i++)
    {
        if(c[num[i]]>1)
        {
            res[i]=1;
            r1++;
            k1++;
            c[num[i]]=-1;
        }
        else if(c[num[i]]==-1)
        {
            res[i]=2;
            r2++;
            k2++;
            c[num[i]]=-2;
        }
    }
    int ct=0;

    for(int i=0;i<2*N;i++)
    {
        if(c[num[i]]==1)
            ct++;
    }
    int ans;
    if(ct%2)
    {
        ans=(r1+ct/2)*(r2+ct/2+1);
    }
    else
        ans=(r1+ct/2)*(r2+ct/2);
    ct=ct/2;
    for(int i=0;i<2*N;i++)
    {
        if(c[num[i]]==1)
        {
            if(ct)
            {
                res[i]=1;
                r1++;
                ct--;
            }
            else
                res[i]=2;
        }
    }

    for(int i=0;i<N*2;i++)
    {
        if(!res[i])
        {
            if(r1<N)
            {
                res[i]=1;
                r1++;
                if(c[num[i]]!=-2)
                    k1++;
            }
            else
            {
                res[i]=2;
                if(c[num[i]]!=-2)
                    k2++;
            }
        }
    }
    printf("%d\n",ans);
    for(int i=0;i<2*N;i++)
    {
        if(i) putchar(' ');
        printf("%d",res[i]);
    }
    puts("");
    return 0;
}
