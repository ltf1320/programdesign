#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
const int inf=1E9+10;
int N,M;



int ems[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int an;
    int mind; //�е�����Сd
    int daidaonum,knum; //�е�����  ����
    int d,k;
    int usm,killm; //�õ����;ã�ɱ������
    int killm2,usm2;
    int cas=1;
    while(T--)
    {
        scanf("%d%d",&N,&M);
        mind=inf;
        an=daidaonum=knum=usm=killm=0;
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
                ems[an++]=d;
            }
            else
            {
                ems[an++]=d;
            }
        }
        //��ɱ����
        if(mind!=inf)
        {
            if(M>=mind)
            {
                usm+=mind;
                killm+=daidaonum;
                knum-=daidaonum;
                knum++;
            }
            else knum=0;
        }
        sort(ems,ems+an);
        for(int i=0; i<an-knum; i++)
        {
            if(usm+ems[i]>M) break;
            usm+=ems[i];
            killm++;
        }
        killm+=knum;
        killm=min(N,killm);

        //��ɱ������
        usm2=0;
        killm2=0;
        for(int i=0;i<an;i++)
        {
            if(usm2+ems[i]>M) break;
            usm2+=ems[i];
            killm2++;
        }
        killm2=min(N,killm2);
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
