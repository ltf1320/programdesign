#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=50000+10;
const int maxk=100+10;
const int inf=0x3f3f3f3f;
int N,K;
struct Node
{
    int w,l;
    bool operator<(const Node &a)const
    {
        if(w==a.w)
            return l>a.w;
        return w>a.w;
    }
};
Node Rec[maxn],Hol[maxk];
int hn;
int main()
{
    freopen("in.txt","r",stdin);
    int mx,mj,tmp;
    int res;
    while(~scanf("%d%d",&N,&K))
    {
        for(int i=0;i<N;i++)
            scanf("%d%d",&Rec[i].w,&Rec[i].l);
        sort(Rec,Rec+N);
        hn=0;
        memset(Hol,0,sizeof(Hol));
        for(int i=0;i<N;i++)
        {
            mx=inf;
            for(int j=0;j<hn;j++)
            {
                tmp=(max(Hol[j].w,Rec[i].w)*max(Hol[j].l,Rec[i].l))-Hol[j].w*Hol[j].l;
                if(tmp<mx)
                {
                    mx=tmp;
                    mj=j;
                }
            }
            tmp=Rec[i].w*Rec[i].l;
            if(hn<K)
            {
                if(tmp<mx)
                {
                    Hol[hn].w=Rec[i].w;
                    Hol[hn].l=Rec[i].l;
                    hn++;
                }
                else
                {
                    Hol[mj].w=max(Rec[i].w,Hol[mj].w);
                    Hol[mj].l=max(Rec[i].l,Hol[mj].l);
                }
            }
            else
            {
                Hol[mj].w=max(Rec[i].w,Hol[mj].w);
                Hol[mj].l=max(Rec[i].l,Hol[mj].l);
            }
        }
        int k;
        res=0;
        for(int i=0;i<hn;i++)
        {
            k=i+1;
            while(Hol[k].l<=Hol[i].l&&Hol[k].w<=Hol[i].w)
                k++;
            res+=Hol[i].l*Hol[i].w;
            i=k-1;
        }
        printf("%d\n",res);
    }
}
