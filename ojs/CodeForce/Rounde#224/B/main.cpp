#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL a,b,w,x,c;
LL step=0;
int rt=0,ra=0;
const int maxn=3000+10;
LL hast[maxn],hasa[maxn];
bool flag=0;
int main()
{
    //freopen("in.txt","r",stdin);
    memset(hast,-1,sizeof(hast));
    memset(hasa,-1,sizeof(hasa));
    scanf("%I64d%I64d%I64d%I64d%I64d",&a,&b,&w,&x,&c);
    while(true)
    {
        while(c>a&&b>=x)
        {
            step++;
            rt++;
            b-=x;
            c--;
            if(hast[b]!=-1)
            {
                flag=1;
                break;
            }
            hast[b]=rt;
            hasa[b]=ra;
        }
        if(c<=a)
        {
            printf("%I64d\n",step);
            return 0;
        }
        if(flag)
            break;
        b=w+b-x;
        step++;
        rt++;
        ra++;
        a--;
        c--;
        if(hast[b]!=-1)
        {
            flag=1;
            break;
        }
        hast[b]=rt;
        hasa[b]=ra;
    }
    rt=rt-hast[b];
    ra=ra-hasa[b];
    LL s=(c-a)/(rt-ra)-1;
    step+=s*rt;
    c-=s*rt;
    a-=s*ra;
    while(c>a)
    {
        while(c>a&&b>=x)
        {
            step++;
            b-=x;
            c--;
        }
        if(c<=a)
            break;
        b=w+b-x;
        step++;
        a--;
        c--;
    }
    printf("%I64d\n",step);
    return 0;
}
