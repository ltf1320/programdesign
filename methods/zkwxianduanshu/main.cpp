#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn=100000+100;

int sum[4*maxn];
int level;
int data[maxn];

int mid(const int a,const int b)
{
    return (a+b)>>1;
}

void buildtree()
{
    int first;
    for(int i=level-1;i>0;--i)
    {
        first=1<<i;
        for(int j=0;j<(int)pow(2,i);++j)
            sum[j]=sum[1<<j]+sum[1<<j|1];
    }
}

void read(int L)
{
    int first=1<<level;
    for(int i=first+1; i<first+L+1; ++i)
        scanf("%d",&sum[first+i+1]);
}
int getlevel(int n)
{
    double exp=1e-7;
    return floor(log(n)/log(2)+exp);
}
void change(int a,int b,int val)
{
    int l=(a<<level)-1,r=(b<<level)+1;
    while(1)
    {
        if((l>>1)==(r>>1)) break;
        if((l&1)==0)
            sum[l+1]+=val*pow(2.0,getlevel(l+1));
        if((r&1)==1)
            sum[r-1]+=val*pow(2.0,getlevel(r-1));
        l>>=1;
        r>>=1;
    }
}

int query(int a,int b)
{
    int l=(a<<level)-1,r=(b<<level)+1;
    int res=0;
    while(1)
    {
        if((l>>1)==(r>>1)) break;
        if((l&1)==0)
            res+=sum[l+1];
        if((r&1)==1)
            res+=sum[r-1];
        l>>=1;
        r>>=1;
    }
    res+=sum[l]+sum[r];
    while(l)
    {
        l>>=1;
        res+=sum[l];
    }
    return res;
}

void printtree(int L)
{
    int first=1<<level;
    cout<<"tree:"<<endl;
    for(int i=0; i<first+L; ++i)
        cout<<sum[first+i+1]<<" ";
    cout<<endl;
}

int main()
{
    freopen("in.txt","r",stdin);
    int L;
    memset(sum,0,sizeof(sum));
    scanf("%d",&L);
    level=getlevel(L);
    cout<<level<<endl;
    read(L);
    printtree(L);
    int Q;
    scanf("%d",&Q);
    for(int i=0; i<Q; ++i)
    {
        int a,b,val;
        char ch;
        cin>>ch;
        if(ch=='P')
        {
            scanf("%d%d",&a,&b);
            cout<<query(a,b)<<endl;
        }
        else if(ch=='C')
        {
            scanf("%d%d%d",&a,&b,&val);
            printtree(L);
        }
        else i--;
    }
    return 0;
}

