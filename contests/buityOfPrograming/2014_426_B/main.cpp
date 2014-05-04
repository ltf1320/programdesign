//source here
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int R,H;
int n;
const int maxn = 102;
const double PI=acos(-1);

struct building{
    int x,y,r,h;
};

building Bu[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    for(int tcase=1;tcase<=cases;tcase++){
        printf("Case %d: ",tcase);
        scanf("%d%d",&R,&H);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&Bu[i].x,&Bu[i].y,
                             &Bu[i].r,&Bu[i].h);
        }
        double ans;
        if(n==0){
            ans=1;
        }
        else{
            double dis=sqrtf(Bu[0].x*Bu[0].x+Bu[0].y*Bu[0].y);

            if(Bu[0].h>=H){
                double sin=Bu[0].r/dis;
                double ang=asin(sin);
                ans=(PI-ang)/PI;
            }
            else
            {
                double l1=sqrt(Bu[0].r*Bu[0].r+dis*dis);
                double L1=H*l1/(H-Bu[0].h);
                double l2=dis+Bu[0].r;
                double L2=H*l2/(H-Bu[0].h);
                if(L1>=R){
                    double sin=Bu[0].r/dis;
                    double ang=asin(sin);
                    ans=(PI-ang)/PI;
                }
                else if(L1<=R&&L2<=R){
                    ans=1;
                }
                else{
                    double y=(double)R*(H-Bu[0].h)/H;
                    double cosa=(y*y+dis*dis-Bu[0].r*Bu[0].r)/
                                (2*y*dis);
                    double ang=acos(cosa);
                    ans=(PI-ang)/PI;
                }
            }
        }
        printf("%.7f\n",ans);
    }
    return 0;
}
