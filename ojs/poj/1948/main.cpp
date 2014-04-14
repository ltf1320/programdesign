#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=50;
int N;
int L[maxn];
int res;
int sum;
int kn;

bool canF(int a,int b,int c)
{
    if(!(a&&b&&c))return 0;
    if(a+b>c&&b+c>a&&a+c>b) return true;
    return false;
}

int getAera(int a,int b,int c)
{
    int s=(a+b+c)/2;
    double res=sqrt(1.0*s*(s-a)*(s-b)*(s-c));
    return static_cast<int>(res*100);
}

void dfs(int i,int a,int b)
{
    if(i==N) return;
    int are=-1;
    kn++;
    bool cc(0);
    if(canF(a,b,sum-a-b)) {are=getAera(a,b,sum-a-b);cc=1;}
  //  if(cc) printf("%d %d %d\n",a,b,sum-a-b);
    res=max(are,res);
    int c=sum-a-b;
    if(a+L[i]>c-L[i]&&b+L[i]>c-L[i]) return;
    if(b+L[i]>c-L[i]&&a+L[i]>b) return;
    if(c-L[i]<b) return;
    if(sum-a>a&&a+L[i]<=c-L[i]&&b<=c-L[i]&&a+L[i]<=b)
        dfs(i+1,a+L[i],b);
    if(sum-b>b&&b+L[i]<=c-L[i]&&a<=c-L[i])
        dfs(i+1,a,b+L[i]);
    if(sum-a-b<a+b&&cc)
        dfs(i+1,a,b);

}

int main()
{
    freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    scanf("%d",&N);
    sum=0;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&L[i]);
        sum+=L[i];
    }
    sort(L,L+N);
    dfs(0,0,0);
    printf("%d\n",res);
    printf("%d\n",kn);
    return 0;
}
