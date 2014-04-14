#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxc=30;
const int maxn=100000+100;

int str[maxn];
int dif[maxc];

int stack[2*maxn];
int top;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(dif,0,sizeof(dif));
    char ch;
    int N=0;
    int p=0,res=0;
    while((ch=getchar())!='\n')
    {
        str[p++]=ch-'A';
        dif[ch-'A']++;
        N++;
    }
    while((ch=getchar())!='\n')
        dif[ch-'A']--;
    p=0;
    for(int i=0; i<N; i++)
    {
        if(dif[str[i]]>0)
        {
            while(dif[p]>=0) p++;
            if(p<str[i])
            {
                dif[str[i]]--;
                dif[p]++;
                str[i]=p;
                res++;
            }
        }
    }
    p=26;
    for(int i=N-1; i>=0; i--)
    {
        if(dif[str[i]]>0)
        {
            while(dif[p]>=0) p--;
            dif[str[i]]--;
            dif[p]++;
            str[i]=p;
            res++;
        }
    }
    printf("%d\n",res);
    for(int i=0; i<N; i++)
        putchar('A'+str[i]);
    putchar('\n');
    return 0;
}
