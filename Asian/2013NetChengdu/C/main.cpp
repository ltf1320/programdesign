#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10000+100;

char end[10]="nanodesu";
char kend[10]="desu";

char str[maxn];
int cas;

int main()
{
    freopen("in.txt","r",stdin);
    int T,len;
    scanf("%d",&T);
    gets(str);
    while(T--)
    {
        cas++;
        gets(str);
        len=strlen(str);
        if(len>=4&&!strcmp(str+len-4,kend))
        {
            str[len-4]=0;
        }
        printf("Case #%d: ",cas);
        printf("%s",str);
        puts(end);
    }
    return 0;
}
