#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ish(string s)
{
    int res=0;
    int sz=s.size();
    for(int i=0;i<sz/2;++i)
    {
        if(s[i]!=s[sz-i-1])
        {
            res++;
        }
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n,s1;
    string str;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        cin>>str;
        s1=ish();
        if(s1==0 || s1==1)
        {
            printf("%d\n",s1);
            continue;
        }
        else
        {

        }
    }
    return 0;
}
