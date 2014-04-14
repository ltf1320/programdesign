#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100000+100;
char now[maxn];
char g[maxn];
int len;

void getG()
{
    g[0]=now[0];
    for(int i=1;i<len;i++)
        g[i]=((now[i]-'0')^(now[i-1]-'0'))+'0';
    g[len]=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%s",now))
    {
        len=strlen(now);
        getG();
        cout<<now<<" "<<g<<endl;
    }
    return 0;
}
