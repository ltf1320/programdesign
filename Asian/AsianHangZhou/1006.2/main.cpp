#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=100000+10;
const int inf=1E9+10;
int N,M;
struct Enimy
{
    int costd,k;
    bool operator<(const Enimy &a)const
    {
        if(costd==a.costd) return k>a.k;
        return costd<a.costd;
    }
};
Enimy ems[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    int d,k;
    scanf("%d",&T);
    int nowk; //现在有的刀
    int usm,killm; //用掉的耐久，杀掉的人
    int usm2,killm2;
    int cas=1;
    int mind,rm; //有刀中最小d
    int daidaonum,knum; //有刀人数  刀数
    while(T--)
    {
        scanf("%d%d",&N,&M);
        mind=inf;
        usm=killm=daidaonum=knum=nowk=0;
        for(int i=0; i<N; i++)
        {
            scanf("%d%d",&d,&k);
            if(k>0)
            {
                if(mind>d)
                {
                    mind=d;
                }
                daidaonum++;
                knum+=k;
            }
            ems[i].costd=d;
            ems[i].k=k;
        }
        sort(ems,ems+N);
        int i;
        for(i=0; i<N; i++)
        {
            if(usm+ems[i].costd>M) break;
            if(killm+nowk>=N) break;
            usm+=ems[i].costd;
            nowk+=ems[i].k;
            killm++;
        }
        if(killm+nowk>=N) killm=N;
        else if(nowk>0)
        {
            for(; i<N; i++)
            {
                if(ems[i].k>0)
                {
                    nowk+=ems[i].k-1;
                    killm++;
                }
            }
            killm+=nowk;
            killm=min(N,killm);
        }
//        else
        {
            killm2=0;
            usm2=0;
            nowk=0;
            if(mind!=inf&&mind<M)
            {
                for(i=0;i<N;i++)
                    if(ems[i].k>0){
                        rm=i;
                        usm2+=ems[i].costd;
                        nowk=ems[i].k;
                        break;
                    }
                for(i=0;i<N;i++)
                {
                    if(i==rm) continue;
                    if(usm2+ems[i].costd>M) break;
                    if(killm2+nowk>=N) break;
                    nowk+=ems[i].k;
                    usm2+=ems[i].costd;
                    killm2++;
                }
                for(i++;i<N;i++)
                {
                    if(ems[i].k>0)
                    {
                        nowk+=ems[i].k-1;
                        killm2++;
                    }
                }
                killm2+=nowk;
            }
        }
        killm2=min(N,killm2);
        killm=min(N,killm);
        if(killm2>killm)
        {
            killm=killm2;
            usm=usm2;
        }
        if(killm2==killm)
            usm=min(usm,usm2);
        printf("Case %d: %d %d\n",cas++,killm,usm);
    }
    return 0;
}
