#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
char tmp[maxn];

int G[maxn],S[maxn];
int cnt;
int fs[maxn];
int n,m;

void getGS(char *tmp,int l)
{
    for(int i=0;i<m;i++)
    {
        if(tmp[i]=='G')
            G[l]=i;
        if(tmp[i]=='S')
            S[l]=i;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    gets(tmp);
    for(int i=0;i<n;i++)
    {
        gets(tmp);
        getGS(tmp,i);
        if(G[i]>S[i])
        {
            puts("-1");
            return 0;
        }
        else
        {
            fs[cnt++]=S[i]-G[i];
        }
    }
    sort(fs,fs+cnt);
    printf("%d\n",unique(fs,fs+cnt)-fs);
    return 0;
}
