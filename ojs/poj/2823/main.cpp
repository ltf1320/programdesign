#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1000000+100;

int maxf,maxr,minf,minr,n,k;

struct Node
{
    int val,t;
    Node(int val_,int t_):val(val_),t(t_){}
    Node(){}
};
Node maxq[maxn];
Node minq[maxn];
int maxres[maxn];
int minres[maxn];

void push(int n,int t)
{
    if(maxq[maxf].t<t-k+1)
        maxf++;
    if(minq[minf].t<t-k+1)
        minf++;
    for(int i=maxr-1;i>=maxf;--i)
        if(maxq[i].val<n)
            maxr--;
        else break;
    for(int i=minr-1;i>=minf;--i)
        if(minq[i].val>n)
            minr--;
        else break;
    maxq[maxr++]=Node(n,t);
    minq[minr++]=Node(n,t);
}

int main()
{
    freopen("in.txt","r",stdin);
    int tem;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        maxf=minf=maxr=minr=1;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&tem);
            push(tem,i);
            if(i>k-2)
            {
                maxres[i-k+1]=maxq[maxf].val;
                minres[i-k+1]=minq[minf].val;
            }
        }
        for(int i=0;i<n-k;++i)
            printf("%d ",minres[i]);
        printf("%d\n",minres[n-k]);
        for(int i=0;i<n-k;++i)
            printf("%d ",maxres[i]);
        printf("%d\n",maxres[n-k]);
    }
    return 0;
}
