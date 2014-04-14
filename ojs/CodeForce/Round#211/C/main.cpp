#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=200000+100;
int len;
char str[maxn];
bool del[maxn];


int main()
{
    scanf("%s",str);
    len=strlen(str);
    int cnt=0;
    for(int i=1;i<len;i++)
    {
        if(str[i]==str[i-1])
            cnt++;
        else
            cnt=0;
        if(cnt>=2)
            del[i]=1;
    }
    int pre=0,hs=0;
    for(int i=1;i<len;i++)
    {
        if(del[i]) continue;
        if(str[i]==str[pre])
        {
            if(hs)
                del[i]=1;
            else
            {
                hs=1;
                i++;
                while(del[i])
                    i++;
                pre=i;
            }
        }
        else
        {
            hs=0;
            pre=i;
        }
    }
    for(int i=0;i<len;i++)
        if(!del[i])
            putchar(str[i]);
    puts("");
    return 0;
}
