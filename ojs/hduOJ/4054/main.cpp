#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5000;
const int LINE_NUM=16;
char row[maxn];
int row_num;
int p;
char now[2*LINE_NUM];
int addr;

char change(char a)
{
    if(a>='A'&&a<='Z')
        return a+'a'-'A';
    if(a>='a'&&a<='z')
        return a+'A'-'a';
    else return a;
}

void Donext()
{
    printf("%03x0: ",addr);
    for(int i=0;i<LINE_NUM;i++,p++)
    {
        if(p==row_num)
        {
            now[i]=0;
            for(;i<LINE_NUM;i++)
            {
                printf("  ");
                if(i%2) putchar(' ');
            }
            break;
        }
        printf("%02x",row[p]);
        if(i%2) putchar(' ');
        now[i]=change(row[p]);
    }
    now[LINE_NUM]=0;
    printf("%s\n",now);
    addr++;
}

void work()
{
    addr=0;
    while(p<row_num)
        Donext();
}

int input()
{
    p=0;
    if(gets(row)==NULL) return -1;
    row_num=strlen(row);
    return 0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~input())
        work();
    return 0;
}
