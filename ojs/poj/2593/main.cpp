#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100000+1000;

int n,k;
int maxf,maxr,minf,minr;

struct maxNode
{
    maxNode(int val_,int num_):num(num_),val(val_){}
    maxNode(){}
    int num,val;
};

struct minNode
{
    minNode(){}
    minNode(int val_,int num_):num(num_),val(val_){}
    int num,val;
};

maxNode maxq[maxn];
minNode minq[maxn];
int resmax[maxn];
int resmin[maxn];

void push(int n,int now)
{
    int i;
    if(maxq[maxf].num<now-k+1)
        maxf++;
    if(minq[minf].num<now-k+1)
        minf++;
    for(i=maxr-1;i>=maxf;--i)
        if(maxq[i].val<n)
            maxr--;
        else break;
    maxq[maxr++]=maxNode(n,now);
    for(i=minr-1;i>=minf;--i)
        if(minq[i].val>n)
            minr--;
        else break;
    minq[minr++]=minNode(n,now);
}



int main()
{
    freopen("in.txt","r",stdin);
    int tem;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        maxf=minf=maxr=minr=1;
        maxq[1].num=minq[1].num=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&tem);
            push(tem,i);
            if(i>=k-1)
            {
                resmax[i-k+1]=maxq[maxf].val;
                resmin[i-k+1]=minq[minf].val;
            }
        }
        for(int i=0;i<n-k;++i)
            printf("%d ",resmin[i]);
        printf("%d\n",resmin[n-k]);
        for(int i=0;i<n-k;++i)
            printf("%d ",resmax[i]);
        printf("%d\n",resmax[n-k]);
    }
    return 0;
}
