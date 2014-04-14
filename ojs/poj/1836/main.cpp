#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=1000+100;
const int inf =maxn;
float h[maxn];
float d[maxn];
int N,res;
int usi;
int find1(int from,int to,float v)
{
    int i;
    int l,r;
    l=from;
    r=to;
    while(r-l>1)
    {
        i=(l+r)>>1;
        if(d[i]<v)
            l=i; //!!居然可以写反
        else r=i;
    }
    return l;
}

int lrs(int end)
{
    for(int i=0; i<N; i++)
        d[i]=inf;
    int j;
    int len=0;
    d[0]=0;
    for(int i=0; i<end; i++)
    {
        if(h[i]>d[len])
        {
            len++;
            d[len]=h[i];
        }
        else
        {
            j=find1(0,len,h[i]);
            if(h[i]>=d[j]) j++; //!!原来写成h[i]!=d[j]了。。。
            if(d[j]>h[i]) d[j]=h[i];
        }
    }
    if(h[end]>d[len])
    {
        len++;
        usi++;
    }
    return len;
}


int lds(int start)
{
    for(int i=0; i<N; i++)
        d[i]=inf;
    int j;
    int len=0;
    d[0]=0;
    for(int i=N-1; i>start; i--)
    {
        if(h[i]>d[len])
        {
            len++;
            d[len]=h[i];
        }
        else
        {
            j=find1(0,len,h[i]);
            if(h[i]>=d[j]) j++;
            if(d[j]>h[i]) d[j]=h[i];
        }
    }
    if(h[start]>d[len])
    {
        len++;
        usi++;
    }
    return len;
}

void work()
{
    int tmp1,tmp2;
    for(int i=0; i<N; i++)
    {
        usi=0;  //之前没考虑到相同最高的情况
        tmp1=lrs(i);
        tmp2=lds(i);
        if(usi==2) tmp1--;
        if(tmp1+tmp2>res) res=tmp1+tmp2;
    }
    res=N-res;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        for(int i=0; i<N; i++)
            scanf("%f",&h[i]);
        work();
        printf("%d\n",res);
    }
    return 0;
}
