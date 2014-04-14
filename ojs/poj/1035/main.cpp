#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=10000+100;

char words[maxn][20];
int length[maxn];
int an;

int rt[maxn];

void find(char *s)
{
    int len=strlen(s);
    int rn=0;
    for(int i=0;i<an;i++)
    {
        if(len==length[i])
        {
            bool flag=1;
            bool flag2=1;
            for(int j=0;j<len;j++)
                if(words[i][j]!=s[j])
                {
                    flag=false;
                    for(int k=j+1;k<len;k++)
                        if(words[i][k]!=s[k])
                        {
                            flag2=false;
                            break;
                        }
                    break;
                }
            if(flag)
            {
                printf("%s is correct\n",s);
                return;
            }
            if(flag2) rt[rn++]=i;
        }
        if(len==length[i]+1)
        {
            bool flag=1;
            for(int j=0;j<len;j++)
                if(words[i][j]!=s[j])
                {
                    for(int k=j;k<len;k++)
                    {
                        if(words[i][k]!=s[k+1])
                        {
                            flag=false;
                            break;
                        }
                    }
                    break;
                }
            if(flag) rt[rn++]=i;
        }
        if(len==length[i]-1)
        {
            bool flag=1;
            for(int j=0;j<len;j++)
                if(words[i][j]!=s[j])
                {
                    for(int k=j;k<len+1;k++)
                    {
                        if(words[i][k+1]!=s[k])
                        {
                            flag=false;
                            break;
                        }
                    }
                    break;
                }
            if(flag)
                rt[rn++]=i;
        }
    }
    printf("%s:",s);
    for(int i=0;i<rn;i++)
        printf(" %s",words[rt[i]]);
    putchar('\n');
}


int main()
{
    freopen("in.txt","r",stdin);
    char tmp[20];
    an=0;
    while(1)
    {
        scanf("%s",tmp);
        if(tmp[0]=='#') break;
        strcpy(words[an],tmp);
        length[an++]=strlen(tmp);
    }
    while(1)
    {
        scanf("%s",tmp);
        if(tmp[0]=='#') break;
        find(tmp);
    }
    return 0;
}
