#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxc=30;
const int maxn=100000+100;

int str[maxn];
int has[maxc];
int need[maxc];

int stp=0;
bool flag[maxn];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char ch;
    int N=0;
    int p=0,res=0,t;
    while((ch=getchar())!='\n')
    {
        str[p++]=ch-'A';
        has[ch-'A']++;
        N++;
    }
    while((ch=getchar())!='\n')
        need[ch-'A']++;
    p=0;
    for(int i=0;i<N;i++)
    {
        while(need[p]<=has[p]) p++;
        t=str[i];
        if(need[str[i]]<has[str[i]]&&(str[i]>p||need[str[i]]==0))
        {
            str[i]=p;
            need[p]--;
            res++;
        }
        else need[str[i]]--;
        has[t]--;
    }
    printf("%d\n",res);
    for(int i=0; i<N; i++)
        putchar('A'+str[i]);
    putchar('\n');
    return 0;
}
