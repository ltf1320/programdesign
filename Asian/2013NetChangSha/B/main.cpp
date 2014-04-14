#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=10000+100;

int N,E,A,B;
int up[maxn],down[maxn];
int res[maxn];

int cnt;

void pre()
{
    for(int i=2;i<=10000;i++)
    {
        up[i]=i-1+up[i-1];
        down[i]=i-1+down[i/2]+down[(i-1)/2];
    }
}

bool dfs(int l,int r,int T)
{
    if(T>up[r-l+1]||T<down[r-l+1])
        return false;
    if(l>=r)
    {
        if(l==r)
        {
            res[l]=l+1;
            cnt++;
        }
        return true;
    }
    T-=r-l;
    for(int i=l;i<=(r+l)/2;i++)
    {
        if(up[i-l]+up[r-i]>=T&&down[i-l]+down[r-i]<=T)
        {
            int start=max(down[i-l],T-up[r-i]);
            int end=min(up[i-l],T-down[r-i]);
            for(int j=start;j<=end;j++)
            {
                if(dfs(l,i-1,j)&&dfs(i+1,r,T-j))
                {
                    swap(res[r],res[i]);
                    swap(res[(l*A+r*B)/(A+B)],res[r]);
                    res[(l*A+r*B)/(A+B)]=i+1;
                    cnt++;
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    pre();
    while(~scanf("%d%d%d%d",&N,&E,&A,&B))
    {
        cnt=0;
        if(dfs(0,N-1,E))
        {
            for(int i=0;i<N;i++)
            {
                if(i) putchar(' ');
                printf("%d",res[i]);
            }
            puts("");
        }
        else
            puts("NOWAY");
 //       cout<<cnt<<endl;
    }
    return 0;
}
