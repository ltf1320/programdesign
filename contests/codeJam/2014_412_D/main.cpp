#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int maxn=1000+10;

double a[maxn],b[maxn];
int N;

void output(double *arr)
{
    for(int i=0; i<N; i++)
        printf("%.5f ",arr[i]);
    puts("");
}

int getRes1()
{
    int al=0,ar=N,bl=0,br=N;
    int res=0;
    while(al<ar)
    {
        sort(a+al,a+ar);
        sort(b+bl,b+br);
        if(a[al]>b[bl])
        {
            res++;
            al++;
            bl++;
        }
        else
        {
            al++;
            br--;
        }
    }
    return res;
}

int getRes2()
{
    int res=0;
    set<double> st;
    for(int i=0; i<N; i++)
        st.insert(b[i]);
    for(int i=0; i<N; i++)
    {
        set<double>::iterator iter=st.lower_bound((a[i]));
        if(iter==st.end())
        {
            res++;
            st.erase(st.begin());
        }
        else
        {
            st.erase(iter);
        }
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d",&N);
        for(int i=0; i<N; i++)
            scanf("%lf",&a[i]);
        for(int i=0; i<N; i++)
            scanf("%lf",&b[i]);
        printf("Case #%d: %d %d\n",cas,getRes1(),getRes2());
    }
    return 0;
}
