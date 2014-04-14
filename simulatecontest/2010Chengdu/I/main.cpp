#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50000+100;
typedef long long LL;
const LL inf=(LL)50000*50000+1000000000+10000; //1E9 for double
int N,K;
LL m[maxn];
LL start;
LL p2[maxn];
bool judge(LL p)
{
    int nk=0;
    LL np;  //for int
    for(int i=N-1;i>=0;)
    {
        nk++;
        if(nk>K)
            return false;
        if(p>m[i])
        {
            if(i==0) return true;
            for(int j=i-1;j>=0;j--)
            {
                np=p-p2[i-j];
                if(np>m[j])
                {
                    if(j==0)
                        return true;
                }
                else
                {
                    i=j;break;
                }

            }
        }
        else return false;
    }
    return true;
}

LL work()
{
    LL l=start,r=inf,m;
 //   printf("%I64d\n",p2[49999]+1000000000);
    while(r>=l)
    {
        m=(l+r)>>1;
        if(judge(m))
            r=m-1;
        else l=m+1;
    }
    return r+1;
}

void input()
{
    start=0;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
    {
        scanf("%I64d",&m[i]);
        start=max(start,m[i]);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    for(int i=0;i<maxn;i++)
        p2[i]=(LL)i*i;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        printf("%I64d\n",work());
    }
    return 0;
}
