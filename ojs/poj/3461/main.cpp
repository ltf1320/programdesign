#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxw=10000+10;
const int maxn=1000000+100;

char P[maxw];
char str[maxn];
int lenP,lenS;

int pi[maxw];

inline void init()
{
    memset(pi,0,sizeof(pi));
}

void pre()
{
    int p,k;
    k=-1;
    pi[0]=-1;
    for(p=1;p<=lenP;p++)
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
    int res=0;
    int k=-1;
    for(int i=0;i<lenS;i++)
    {
        while(k!=-1&&P[k+1]!=str[i])
            k=pi[k];
        if(P[k+1]==str[i])
            k++;
        if(k==lenP-1)
        {
            res++;
            k=pi[k];
        }
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%s%s",P,str);
        lenP=strlen(P);
        lenS=strlen(str);
        pre();
        printf("%d\n",work());
    }
    return 0;
}
