#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn=10000;
struct bign
{
    int len1,len2;
    int s[maxn];
    int p[maxn];
    bign()
    {
        len1=1;
        len2=0;
        memset(s,0,sizeof(s));
        memset(p,0,sizeof(p));
    }
    bign operator = (char * num)
    {
        int len3=strlen(num),i;
        for(i=0; i<len3; i++)
        {
            if(num[i]=='.')
            {
                break;
            }
        }
        len1=i;
        if(len1!=len3) len2=len3-1-i;
        for(i=0; i<len1; i++)
        {
            s[i]=num[len1-i-1]-'0';
        }
        for(i=1; i<=len2; i++)
        {
            p[i]=num[len1+i]-'0';
        }
        return *this;
    }
    bign operator + (const bign &b)
    {
        bign c;
        c.len1=0;
        c.len2=max(len2,b.len2);
        int i,g;
        for(i=c.len2,g=0;i>0;i--)
        {
            int x=g;
            if(i<=len2) x+=p[i];
            if(i<=b.len2) x+=b.p[i];
            c.p[i]=x%10;
            g=x/10;
        }
        for(i=0;g||i<max(len1,b.len1);i++)
        {
            int x=g;
            if(i<len1) x+=s[i];
            if(i<b.len1) x+=b.s[i];
            c.s[c.len1++]=x%10;
            g=x/10;
        }
        c.clean();
        return c;
    }
    void prinf_s()
    {
        if(len1!=1||s[0]!=0)
        {
            for(int i=0; i<len1; i++)
            {
                printf("%d",s[len1-i-1]);
            }
        }
        if(len2) printf(".");
        for(int i=0; i<len2; i++)
        {
            printf("%d",p[1+i]);
        }
        printf("\n");
    }
    void clean()
    {
        while(len1>1&&!s[len1-1]) len1--;
        while(len2>0&&!p[len2]) len2--;
    }
};
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
 //  freopen("test.in","r",stdin);
  // freopen("test.out","w",stdout);
    bign a,b,c;
    char m[maxn],n[maxn];
    while(~scanf("%s%s",m,n))
    {
        a=m;
        b=n;
        c=a+b;
        c.prinf_s();
    }
    return 0;
}
