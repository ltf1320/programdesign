#include <iostream>
#include <time.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long LL;
const int maxn=10000000+100;
int seq[maxn];
double w[maxn];
int N;

template <typename T>
int Partion(T seq[],int p,int r)
{
    T key=seq[r];
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(seq[j]<=key)
        {
            i++;
            T temp=seq[i];
            seq[i]=seq[j];
            seq[j]=temp;
        }
    }
    T temp=seq[i+1];
    seq[i+1]=seq[r];
    seq[r]=temp;
    return i+1;
}

template <typename T>
int RandPartion(T seq[],int p,int r)
{
    //srand((unsigned int)time(NULL));
    int rd=p+rand()%(r-p+1);
    T temp=seq[rd];
    seq[rd]=seq[r];
    seq[r]=temp;
    return Partion(seq,p,r);
}

template <typename T>
T WeightedMedian(T seq[],double weight[],int p,int r)
{
    int q=RandPartion(seq,p,r);
    double WL=0.0,WR=0.0;
    for(int i=p;i<q;i++)
        WL+=weight[i];
    for(int i=q+1;i<=r;i++)
        WR+=weight[i];
    if(WL<0.5 && WR<=0.5)
        return seq[q];
    else if(WL>0.5)
    {
        weight[q]+=WR;
        return WeightedMedian(seq,weight,p,q);
    }
    else
    {
        weight[q]+=WL;
        return WeightedMedian(seq,weight,q,r);
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        double S=0;
        for(int i=0;i<N;i++)
            scanf("%d",&seq[i]);
        for(int i=0;i<N;i++)
        {
            scanf("%lf",&w[i]);
            S+=w[i];
        }
        for(int i=0;i<N;i++)
            w[i]/=S;
    cout<<WeightedMedian(seq,w,0,N-1)<<endl;
    }
 return 0;
}
