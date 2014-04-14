#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50;
const int maxc=50;
int Num[maxn];
int Sum[maxn];

char* get(int n,int k)
{
    int j,sum=0;
    for(j=0;j<n;j++)
    {
        if((sum+Num[n-j-1]*Num[j])>=k) break;
        else sum+=Num[n-j-1]*Num[j];
    }
    char *right(0),*left(0);
    if(n-j-1)
 //       right=get(n-j-1,(k-sum)%Num[n-j-1]==0?Num[n-j-1]:(k-sum)%Num[n-j-1]);
            right=get(n-j-1,(k-sum-1)%Num[n-j-1]+1); //!!
    if(j)
        left=get(j,(k-sum-1)/Num[n-j-1]+1);
    char *ans=new char[maxc];
    ans[0]=0;
    if(left)
    {
        strcat(ans,"(");
        strcat(ans,left);
        strcat(ans,")");
        delete [] left;
    }
    strcat(ans,"X");
    if(right)
    {
        strcat(ans,"(");
        strcat(ans,right);
        strcat(ans,")");
        delete [] right;
    }
    return ans;
}

int main()
{
    freopen("in.txt","r",stdin);
    memset(Num,0,sizeof(Num));
    Num[0]=Num[1]=Sum[1]=1;
    for(int i=2;Sum[i-1]<500000000;i++)
    {
        for(int j=0;j<i;j++)
        {
            Num[i]+=Num[i-j-1]*Num[j];
            Sum[i]=Sum[i-1]+Num[i];
        }
    }
    int n,k;
    char *res;
    while(~scanf("%d",&n)&&n)
    {
        for(k=1;;k++)
            if(Sum[k]>=n) break;
        res=get(k,n-Sum[k-1]);
        printf("%s\n",res);
        delete [] res;
    }
    return 0;
}
