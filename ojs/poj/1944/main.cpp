#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int maxP=10000+100;
int rt[maxn];
int N,P;

struct MNC
{
    int l,r,dis;
    void reset(int l,int r)
    {
        if(r>l){
        this->l=l;
        this->r=r;
        }
        else
        {
            this->l=r;
        this->r=l;
        }
        dis=min(r-l,N-r+l);
    }
    bool operator<(const MNC &a)const
    {
        return dis<a.dis;
    }
};
MNC mnc[maxP];



int main()
{
    freopen("in.txt","r",stdin);
    int l,r;
    int sum1,sum2,res;
    while(~scanf("%d%d",&N,&P))
    {
        for(int i=1; i<=N; i++)
            rt[i]=i;
        for(int i=0; i<P; i++)
        {
            scanf("%d%d",&l,&r);
            mnc[i].reset(l,r);
        }
        sort(mnc,mnc+P);
        if(mnc[0].r-mnc[0].l<N-mnc[0].r+mnc[0].l)
        {
            for(int i=mnc[0].l; i<=mnc[0].r; i++)
            {
                rt[i]=mnc[0].r;
            }
        }
        else
        {
            for(int i=1; i<=mnc[0].l; i++)
            {
                rt[i]=mnc[0].l;
            }
            for(int i=mnc[0].r; i<=N; i++)
            {
                 rt[i]=mnc[0].l;
            }
        }
        for(int i=1; i<P; i++)
        {
            sum1=0;
            for(int j=mnc[i].l; j<=mnc[i].r; j++)
            {
                j=rt[j];
                if(j>=mnc[i].r||j<mnc[i].l) break;
                sum1++;
            }
            sum2=0;
            for(int j=mnc[i].r; j>=mnc[i].r||j<mnc[i].l; j++)
            {
                j=rt[j];
                if(j<mnc[i].r&&j>=mnc[i].l) break;
                sum2++;
                if(j==N)j=0;
            }
            if(sum1<sum2)
            {
                for(int j=mnc[i].l; j<=mnc[i].r; j++)
                {
                    if(rt[j]<mnc[i].r)
                        rt[j]=mnc[i].r;
                 }
            }
            else
            {
                for(int j=mnc[i].r; j<mnc[i].l||j>=mnc[i].r; j++)
                {
                    if(rt[j]<mnc[i].l||rt[j]>=mnc[i].r)
                        rt[j]=mnc[i].l;
                     if(j==N) j=0;
                }
            }
        }
        res=0;
        for(int i=1;i<=N;i++)
        {
            if(rt[i]>=i)
                res+=rt[i]-i;
            else
            {
                res+=N-i+rt[i];
                break;
            }
            i=rt[i];
        }
        printf("%d\n",res);
    }
    return 0;
}
