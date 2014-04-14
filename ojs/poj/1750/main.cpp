#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int main()
{
    freopen("in.txt","r",stdin);
    int t1,t2;
    int blank,tb;
    char s;
    char tmp1[12],tmp2[12];
    scanf("%s",tmp1);
    printf("%s\n",tmp1);
    s=tmp1[0];
    t1=strlen(tmp1);
    blank=0;
    while(~scanf("%s\n",tmp2))
    {
        if(tmp2[0]!=s)
        {
            s=tmp2[0];
            printf("%s\n",tmp2);
            memcpy(tmp1,tmp2,sizeof(tmp2));
            t1=strlen(tmp1);
            blank=0;
            continue;
        }
        t2=strlen(tmp2);
        tb=0;
        for(int i=0;i<blank+1&&i<t1&&i<t2;i++)
        {
            if(tmp2[i]==tmp1[i])
            {
                tb++;
            }
            else break;
        }
        blank=tb;
        for(int i=0;i<blank;i++)
            putchar(' ');
        printf("%s\n",tmp2);
        memcpy(tmp1,tmp2,sizeof(tmp2));
        t1=t2;
    }
    return 0;
}
