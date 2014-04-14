#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=50000+10;
char P[maxn];
char str[maxn];
int lenP,lenS;

int pi[maxn];
void pre()
{
    int p,k;
    k=-1;
    pi[0]=-1;
    for(p=1; p<=lenP; p++)
    {
        while(k!=-1&&P[k+1]!=P[p])
            k=pi[k];
        if(P[k+1]==P[p])
            k=k+1;
        pi[p]=k;
    }
}

int work()
{
    int k=-1;
    int now;
    int res=inf;
    for(int i=0; i<lenS-lenP+1; i++)
    {
        while(k!=-1&&P[k+1]!=str[i])
        {
            now=0;
            for(int j=k+1; j<lenP; j++)
            {
                if(P[j]!=str[i+j-k-1]) now++;
            }
            res=min(now,res);
            k=pi[k];
        }
        if(P[k+1]==str[i])
            k++;
            now=0;
            for(int j=k+1; j<lenP; j++)
            {
                if(P[j]!=str[i+j-k-1]) now++;
            }
            res=min(now,res);
        if(k==lenP-1)
            return 0;
    }
    return res;
}


int main()
{
    freopen("in.txt","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        scanf("%s",str);
        scanf("%s",P);
        lenS=strlen(str);
        lenP=strlen(P);
        pre();
        printf("Case #%d: %d\n",cas,work());
    }
    return 0;
}
