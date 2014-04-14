#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100;
int n,m;

struct DNA
{
    char s[maxn+10];
    int num;
    bool operator<(const DNA a)const
    {
        return num<a.num;
    }
};
void cal(DNA &k)
{
    k.num=0;
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
            if((k.s[i]-k.s[j])>0)
                k.num++;
    }
}


DNA d[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<m;++i)
        {
            scanf("%s",d[i].s);
            cal(d[i]);
        }
        stable_sort(d,d+m);
        for(int i=0;i<m;++i)
            printf("%s\n",d[i].s);
    }
    return 0;
}
