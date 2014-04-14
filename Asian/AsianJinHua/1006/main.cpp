#include <cstring>
#include <cstdio>
#define maxn 100010
using namespace std;
int f[maxn];
double step[maxn];
double w[maxn];
int n,m;
using namespace std;

void init()
{
    for(int i=0;i<n;i++)
    {
        step[i]=0;
        w[i]=0;
        f[i]=0;
    }
    w[0]=1.0;
}
void add(int from,int to)
{
    f[from]=to;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&m))
    {
        init();
        if(n==0&&m==0) break;

        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
        }

        for(int i=0;i<n;i++)
        {
            if(f[i]!=0)
            {
                int k=f[i];
                double a1=w[i],a2=w[k];
                double b1=step[i],b2=step[k];
                w[k]=a1+a2;
                step[k]=(a1*b1+a2*b2)/(a1+a2);
 //               continue;
            }
            for(int j=1;j<=6;j++)
            {
                double a1=w[i]/6.0;
                double a2=w[i+j];
                double b1=step[i]+1,b2=step[i+j];
                w[i+j]=a1+a2;
                step[i+j]=(a1*b1+a2*b2)/(a1+a2);
            }
        }

        double ans=(double)0;
        for(int i=0;i<=5;i++)
            ans+=w[n+i]*step[n+i];
//        printf("%.4f\n",w[n]*step[n]);
        printf("%.4lf\n",ans);

    }
    return 0;
}
