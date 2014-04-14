#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2*1000000+100;
int len;
char str[maxn];
int ss[maxn];
int p[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int cas=0;
    while(~scanf("%s",str))
    {
        cas++;
        if(str[0]=='E') break;
        len=strlen(str);
        ss[0]='1';
        for(int i=0;i<len;i++)
        {
            ss[2*i+1]='9';
            ss[2*i+2]=str[i];
        }
        ss[2*len+1]='9';
        ss[2*len+2]='2';
        len*=2;
//        cm=0;
        int mx=0,id;
        int res=0;
        for(int i=1;i<=len;i++)
        {
            if(mx>i)
                p[i]=min(p[2*id-i],mx-i);
            else p[i]=1;
            while(ss[i-p[i]]==ss[i+p[i]])
            {
                p[i]++;
            }
            if(i+p[i]>mx)
            {
                mx=i+p[i];
                id=i;
            }
            res=max(res,p[i]-1);
        }
        printf("Case %d: %d\n",cas,res);
//
    }
    return 0;
}
