#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxc=30;
const int maxn=100000+100;

int str[maxn];
int dif[maxc];

int stack[2*maxn];
int top=0;

int state[2*maxn];
bool flag[2*maxn];
int stp=0;

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
            stack[top++]=str[i];
            state[stp++]=i;
        }
        else if(dif[str[i]]<0)
        {
            state[stp++]=i;
        }
    }
    for(int i=0;i<26;i++)
        if(dif[i]<0)
        {
            for(int j=0;j<dif[i];j++)
            {
                stack[top++]=i;
            }
        }
    sort(stack,stack+top);
    p=0;
    for(int i=0;i<stp;i++)
    {
        while(dif[stack[p]]!=0)
            p++;
        if(dif[str[i]]==0) continue;
        if(dif[stack[p]]<0)
        {
            dif[stack[p]]++;
            dif[str[state[i]]]--;
            str[state[i]]=stack[p];
            p++;
        }
        else
        {
            for(int j=0;j<stp;j++)
            {
                if()
            }
        }
    }
    printf("%d\n",res);
    for(int i=0; i<N; i++)
        putchar('A'+str[i]);
    putchar('\n');
    return 0;
}
