#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=31;
int a,b;
int p10[10];


void pre()
{
    p10[0]=1;
    for(int i=1;i<10;i++)
        p10[i]=p10[i-1]*10;
}

int divi(int n)
{
   int p=0;
   while(n)
   {
       n/=10;
       p++;
   }
   return p;
}

void getNum(int n,int res[])
{
    int len=divi(n);
    int now=0,last=0,has=n;
    for(int i=1;i<=len;i++)
    {
        if(i>1)
            last=now*p10[i-2]+last;
        now=has%10;
        has/=10;
        for(int j=0;j<10;j++)
        {
            res[j]+=(has-1)*p10[i-1];//j在中间的
           if(j)
                res[j]+=p10[i-1]; //j开头的
            if(j<now) //多出一次j在中间的
                res[j]+=p10[i-1];
            else if(j==now)
                res[j]+=last+1;
        }
    }
}

int ar[maxn],br[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    pre();
    while(~scanf("%d%d",&a,&b)&&a&&b)
    {
        if(a>b)
        {
            int t=a;
            a=b;
            b=t;
        }
        memset(ar,0,sizeof(ar));
        memset(br,0,sizeof(br));
        getNum(a-1,ar);
        getNum(b,br);
        for(int i=0;i<10;i++)
        {
            if(i)
                putchar(' ');
            printf("%d",br[i]-ar[i]);
        }
        puts("");
    }
    return 0;
}
