#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=400000;
char str[maxn];
int len;
int pi[maxn];
int stack[maxn];
int top;

void pre()
{
    int k,p;
    k=-1;
    pi[0]=-1;
    for(p=1;p<len;p++)
    {
        while(k!=-1&&str[k+1]!=str[p])
            k=pi[k];
        if(str[k+1]==str[p])
            k++;
        pi[p]=k;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%s",str))
    {
        len=strlen(str);
        pre();
        top=0;
        int k=len-1;
        while(k!=-1)
        {
            stack[top++]=k+1;
            k=pi[k];
        }
        while(top>1)
            printf("%d ",stack[--top]);
        printf("%d\n",stack[--top]);
    }
    return 0;
}
