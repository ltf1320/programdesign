#include <iostream>
#include <cstdio>
#define MAXN 100000
using namespace std;
int lt[MAXN*4];
int lazy[MAXN*4];
void PushUp(int s)
{
    lt[s]=lt[s<<1]|lt[s<<1|1];
}
void PushDown(int s)
{
    if(lazy[s])
    {
        lazy[s<<1]=lazy[s<<1|1]=lazy[s];
        lt[s<<1]=lt[s<<1|1]=lt[s];
        lazy[s]=0;
    }
}
void Build(int l,int r,int s)
{
    lt[s]=1;
    lazy[s]=0;
    if(l==r)return;
    int m=(l+r)>>1;
    Build(l,m,s<<1);
    Build(m+1,r,s<<1|1);
    PushUp(s);
}
void UpDate(int L,int R,int c,int l,int r,int s)
{
    if(L<=l && r<=R)
    {
        lt[s]=1<<(c-1);
        lazy[s]=c;
        return;
    }
    PushDown(s);
    int m=(l+r)>>1;
    if(m>=L)UpDate(L,R,c,l,m,s<<1);
    if(m<R)UpDate(L,R,c,m+1,r,s<<1|1);
    PushUp(s);
}
int Query(int L,int R,int l,int r,int s)
{
    if(L<=l && r<=R)return lt[s];
    PushDown(s);
    int m=(l+r)>>1;
    int ret=0;
    if(m>=L)ret|=Query(L,R,l,m,s<<1);
    if(m<R)ret|=Query(L,R,m+1,r,s<<1|1);
    return ret;
}
int Change(int sum)
{
    int k=0;
    while(sum)
    {
        if(sum&1)k++;
        sum=sum>>1;
    }
    return k;
}
void IncSort(int &a,int &b)
{
    if(a>b)
    {
        int t=a;
        a=b;
        b=t;
    }
}
int main()
{
    int L,T,O;
    int a,b,c;
    char op[2];
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d%d%d",&L,&T,&O);
    Build(1,L,1);
    for(int i=0;i<O;i++)
    {
        scanf("%s",op);
        if(op[0]=='C')
        {
            scanf("%d%d%d",&a,&b,&c);
            IncSort(a,b);
            UpDate(a,b,c,1,L,1);
        }
        else
        {
            scanf("%d%d",&a,&b);
            IncSort(a,b);
            int sum=Query(a,b,1,L,1);
            sum=Change(sum);
            printf("%d\n",sum);
        }

    }
    return 0;
}
