#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool isV(char s)
{
    if((s=='a')||(s=='e')||(s=='i')||(s=='o')||(s=='u'))return true;
    else return false;
}

bool judge(char *s)
{
    int len=strlen(s);
    bool flag=1;
    for(int i=0;i<len;i++)
    {
        if(isV(s[i]))
        {
            flag=0;break;
        }
    }
    if(flag) return false;
    int vn=0,cn=0;
    for(int i=0;i<len;i++)
    {
         if(isV(s[i]))
         {
            vn++;
            cn=0;
         }
         else
         {
             cn++;
             vn=0;
         }
         if(vn==3||cn==3) return false;
    }
    for(int i=1;i<len;i++)
    {
        if(s[i]==s[i-1]&&s[i]!='e'&&s[i]!='o') return false;
    }
    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    char str[15];
    while(~scanf("%s",str))
    {
        if(str[0]=='e'&&str[1]=='n'&&str[2]=='d'&&str[3]=='\0') break;
        if(judge(str))
            printf("<%s> is acceptable.\n",str);
        else
            printf("<%s> is not acceptable.\n",str);
    }
    return 0;
}
