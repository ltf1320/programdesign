#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=80+10;
bool mp[30][30];
char ss[maxn];
int len;
bool judge(int D)
{
    memset(mp,0,sizeof(mp));
    for(int i=0;i<len-D-1;i++)
    {
        if(mp[ss[i]-'A'][ss[i+D+1]-'A']) return false;
        else mp[ss[i]-'A'][ss[i+D+1]-'A']=1;
    }
    return true;
}

bool work()
{
    for(int i=0;i<len-1;i++)
        if(!judge(i)) return false;
    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%s",ss))
    {
        if(ss[0]=='*') break;
        len=strlen(ss);
        if(work()) printf("%s is surprising.\n",ss);
        else printf("%s is NOT surprising.\n",ss);
    }
    return 0;
}
