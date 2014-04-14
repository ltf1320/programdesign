#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10000+100;
char str[maxn];
int len;
int pen[maxn];

void pre()
{
    int st=0;
    pen[1]=0;
    for(int i=2;i<len;i++)
    {
        while(st&&str[st+1]!=str[i])
            st=pen[st];
        if(str[st+1]==str[i]) st++;
        pen[i]=st;
    }
}

void work()
{
    int st;
    pre();
    for(int i=0;i<len;i++)
    {
        printf("%d",i);
        for(int j=0;j<26;j++)
        {
            st=i;
            while(st&&str[st+1]!='a'+j)
                st=pen[st];
            if(str[st+1]=='a'+j)
                st++;
            printf(" %d",st);
        }
        putchar('\n');
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    str[0]=32;
    while(true)
    {
        gets(str+1);
        if(str[1]=='0') break;
        len=strlen(str);
        work();
    }
    return 0;
}
