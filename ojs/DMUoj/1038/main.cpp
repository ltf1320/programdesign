#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=1e3+10;
char ch[maxn];
int work(char * a)
{
    int len=strlen(a);
    int sum=0;
    for(int i=0;i<len;i++)
    {
        sum+=(ch[i]-'0')*(pow(2,len-1-i));
    }
    return sum;
}
int main()
{
    freopen("in.txt","r",stdin);
   // freopen("test.in","r",stdin);
  //  freopen("test.out","w",stdout);
    int t;
    scanf("%d",&t);
    gets(ch);
    while(t--)
    {
       // scanf("%s",ch);
       gets(ch);
        int ans;
        ans=work(ch);
        printf("%d\n",ans);
    }
    return 0;
}
