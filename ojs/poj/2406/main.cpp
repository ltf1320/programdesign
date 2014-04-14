#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000000+100;

char str[maxn];
int pi[maxn];
int len;

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
        memset(pi,0,sizeof(pi));
        if(str[0]=='.') break;
        len=strlen(str);
        pre();
        if(len%(len-pi[len-1]-1)==0) printf("%d\n",len/(len-pi[len-1]-1));
        else printf("%d\n",1);
    }
    return 0;
}
