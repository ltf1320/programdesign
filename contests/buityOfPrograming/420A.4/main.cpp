#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int maxn=1000+10;
int N;
int AN1,AN;

int n0[maxn],n1[maxn];
set<int> st;


void init()
{
    n0[0]=1;
    n1[0]=0;
    n0[1002]=0;
    n1[1002]=1;
    AN=2;
    AN1=1;
}

void insert(int n)
{
    int l,r;
    set<int>::iterator iter=st.find(n);
    iter--;
    l=*iter;
    iter++;
    iter++;
    r=*iter;
    if(n0[l]+n1[l]>=n0[r]+n1[r])
    {
        n1[n]=n1[l]+1;
        n0[n]=n0[l];
    }
    else
    {
        n1[n]=n1[r];
        n0[n]=n1[r]+1;
    }
    AN+=n1[n]+n0[n];
    AN1+=n1[n];
}

int main()
{
    freopen("in.txt","r",stdin);
    int T,tmp;
    int cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        memset(n0,0,sizeof(n0));
        memset(n1,0,sizeof(n1));
        init();
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            scanf("%d",&tmp);
            tmp++;
            st.insert(tmp);
            insert(tmp);
        }
        printf("Case #%d: %d %d\n",cas,AN,AN1);
    }
    return 0;
}
