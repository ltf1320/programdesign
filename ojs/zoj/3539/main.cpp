#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=5000+100;
const int maxN=50;
char str[maxn];
int sn[maxN];
int N,len;
int cnum[maxn][maxN];

bool judge(const char *s,int l,int start)
{
    for(int i=0; i<l; i++)
        if(s[i]!=str[i+start]) return false;
    return true;
}

void replace(const char *s,int l,int num)
{
    int i=0,j=0;
    int nlen;
    nlen=len;
    for(;i<=nlen-l+1;i++)
    {
        if(judge(s,l,i))
        {
            str[j++]=num+'0';
            i+=l-1;
            len=len-l+1;
        }
        else str[j++]=str[i];
    }
    for(;i<=nlen;i++)
        str[j++]=str[i];
}

void strds()
{
    char now[maxN];
    int maxi,maxf,maxl;
    for(int kk=N-1; kk>0; kk--)
    {
        memset(cnum,0,sizeof(cnum));
        int l=sn[kk];
        for(; l>1; l--)
        {
            for(int i=0; i<len-l+1; i++)
            {
                for(int j=0; j<l; j++)
                    now[j]=str[i+j];
                cnum[i][l]++;
                for(int k=i+l; k<len; k++)
                {
                    if(judge(now,l,k))
                    {
                        cnum[i][l]++;
                        k+=l-1;
                    }
                }
            }
        }
        maxf=maxi=maxl=0;
        for(l=sn[kk]; l>1; l--)
        {
            for(int i=0; i<len; i++)
                if(cnum[i][l]*(l-1)>maxf)
                {
                    maxf=cnum[i][l]*(l-1);
                    maxi=i;
                    maxl=l;
                }
        }
        if(maxl)
        {
            for(int j=0; j<maxl; j++)
                now[j]=str[maxi+j];
            replace(now,maxl,kk);
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        for(int i=0; i<N; i++)
            scanf("%d",&sn[i]);
        scanf("%s",str);
        len=strlen(str);
        strds();
        if(len<=sn[0]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
