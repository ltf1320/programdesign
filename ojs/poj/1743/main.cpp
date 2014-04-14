#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=20000+100;
int str[maxn];
int pi[maxn];
int rpi[maxn];
int N,res;

void pre(int start,int end)
{
    int k,p,q;
    k=start-1;
    q=end;
    pi[start]=k;
    rpi[end-1]=end;
    for(p=start+1;p<end;p++)
    {
        while(k!=start-1&&str[k+1]!=str[p])
            k=pi[k];
        if(str[k+1]==str[p])
            k++;
        pi[p]=k;
    }
    for(p=end-2;p>=start;p--)
    {
        while(q!=end&&str[q-1]!=str[p])
            q=rpi[q];
        if(str[q-1]==str[p])
            q--;
        rpi[p]=q;
    }
}

int judge(const int start,const int end)
{
    int now=0;
    int k,p,q;
    k=start-1;
    for(p=0;p<=N;p++)
    {
        while(k!=start-1&&str[k+1]!=str[p])
            k=pi[k];
        while(q!=end&&str[q-1]!=str[p])
            q=rpi[q];
        if(str[q-1]==str[p])
            q--;
        if(str[k+1]==str[p])
            k++;
        if(q==start||k==end-1)
        {
            now++;
            p++;
            k=start-1;
            q=end;
        }
    }
    return now;
}

int dfs(int deep)
{
    if(deep<5) return 0;
    int e;
    for(int i=0;i<=N-deep;i++)
    {
        pre(i,i+deep);
        e=judge(i,i+deep);
        if(e>1) return deep;
    }
    return dfs(deep-1);
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(!N) break;
        for(int i=0;i<N;i++)
            scanf("%d",&str[i]);
        for(int i=0;i<N-1;i++)
            str[i]=str[i+1]-str[i]+88;
        N--;
        printf("%d\n",dfs(N/2));
    }
    return 0;
}
