#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=500000;
int N;
double X[maxn];
double Y2[maxn];
double getD(double x,int a)
{
    return (x-X[a])*(x-X[a])+Y2[a];
}

double getX(int a,int b)
{
    double x=((1.0*X[a]*X[a]+1.0*Y2[a])-(1.0*X[b]*X[b]+1.0*Y2[b]))/(2.0*(X[a]-X[b]));
    return x;
}


int main()
{
    freopen("in.txt","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    double mind,nowd,nowx,resx;
    double mind2,resx2;
    double start,end;
    while(T--)
    {
        cas++;
        mind2=mind=1000000000.0;
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            cin>>X[i]>>Y2[i];
            Y2[i]*=Y2[i];
        }
        resx2=resx=X[0];
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
            {
                nowx=getX(i,j);
                nowd=0.0;
                for(int k=0;k<N;k++)
                    nowd=max(getD(nowx,k),nowd);
                if(nowd<mind)
                {
                    mind2=mind;
                    resx2=resx;
                    mind=nowd;
                    resx=nowx;
                }
                else if(nowd<mind2)
                {
                    mind2=nowd;
                    resx2=nowx;
                }
            }
        start=min(resx,resx2);
        end=max(resx,resx2);
        for(double kx=start;kx<end;kx+=0.000001)
        {
            nowd=0.0;
            for(int k=0;k<N;k++)
                nowd=max(getD(nowx,k),nowd);
            if(nowd<mind)
            {
                mind=nowd;
                resx=nowx;
            }
        }
        printf("Case #%d: %.7f\n",cas,resx);
    }
    return 0;
}
