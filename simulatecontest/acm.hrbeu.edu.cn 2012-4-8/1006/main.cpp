#include <iostream>
#include <cstdio>
#include<cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
int lb[20000];
class Meizi
{
    public:
    string name;
    int k;
};

bool operator<(const Meizi &a,const Meizi &b)
{
    if(a.k<b.k)
        return 1;
    else if(a.k==b.k)
        if(a.name<b.name)
            return 1;
    return 0;
}
Meizi meizi[500000];
char tem[10000];
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    int m;
    char mm[10000];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            getchar();
            scanf("%s %d",tem,&meizi[i].k);
            meizi[i].name=tem;
        }
        for(int i=0;i<m;++i)
            scanf("%d",&lb[i]);
        sort(meizi,&meizi[n]);
        for(int i=0;i<m;++i)
        {
            mm[0]=0;
            if(lb[i]<meizi[0].k||lb[i]>meizi[n-1].k)
            {
                printf("sorry!\n");
                continue;
            }
            for(int j=0;j<n;++j)
                if(meizi[j].k==lb[i])
                {
                    strcpy(mm,meizi[j].name.c_str());
                    break;
                }
            if(mm[0]==0) printf("sorry!\n");
            else printf("%s\n",mm);
        }
    }
    return 0;
}
