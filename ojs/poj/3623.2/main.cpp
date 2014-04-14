#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2000+100;
int N;
char ori[maxn];
char res[maxn];

void work()
{
    ori[N+1]=0;
    ori[0]=0;
    int l=1,r=N;
    int nl,nr;
    int p=0;
    while(l<r)
    {
        nl=l,nr=r;
        while(nl<nr&&ori[nl]==ori[nr])
        {
            nl++;nr--;
        }
        if(nl>=nr||ori[nl]<ori[nr])
            res[p++]=ori[l++];
        else res[p++]=ori[r--];
    }
    res[p++]=ori[l];
    for(int i=0;i<N;i++)
    {
        if(i&&(i%80==0))
            putchar('\n');
        putchar(res[i]);
    }
    printf("\n");
}

void input()
{
    for(int i=1;i<=N;i++)
    {
        scanf("%c",&ori[i]);
        if(ori[i]==' '||ori[i]=='\n')
        {
            i--;continue;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d",&N))
    {
        input();
        work();
    }
    return 0;
}
