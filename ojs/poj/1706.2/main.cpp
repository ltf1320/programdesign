#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000+10;
char tmp[100];
struct Refer
{
    char str[300];
    int cx;
    bool operator<(const Refer &a)const
    {
        return cx<a.cx;
    }
    Refer():cx(0){}
};
Refer refers[maxn];
int refn,ocrn;
int mpold[maxn];

bool isEmp(char *s)
{
    while(*s)
        if(*s++!=' ') return false;
    return true;
}

int getNum(char *s)
{
    int now=*s++-'0';
    while(*s&&*s>='0'&&*s<='9')
    {
        now=now*10+*s-'0';
        s++;
    }
    return now;
}

void readRefer(int old)
{
    int rn;
    if(mpold[old])
        rn=mpold[old];
    else
    {
        mpold[old]=rn=refn++;
    }
    char *p=refers[rn].str,*tt=tmp;
    while(*tt!=']') tt++;
    tt++;
    while(*tt)
        *p++=*tt++;
    *p++='\n';
    *p=0;
    while(gets(tmp))
    {
        if(isEmp(tmp)) break;
        tt=tmp;
        while(*tt)
            *p++=*tt++;
        *p++='\n';
        *p=0;
    }
}

int searchRef(int old)
{
    int rn;
    if(mpold[old])
        rn=mpold[old];
    else mpold[old]=rn=refn++;
    if(refers[rn].cx==0)
        refers[rn].cx=ocrn++;
    return refers[rn].cx;
}

void readLine(char *s)
{
    int old;
    while(*s)
    {
        if(*s=='[')
        {
            s++;
            old=getNum(s);
            while(*s!=']') s++;
            s++;
            printf("[%d]",searchRef(old));
        }
        else putchar(*s++);
    }
    puts("");
}

void readTxt()
{
    int old;
    while(gets(tmp))
    {
        if(isEmp(tmp))
            continue;
        if(tmp[0]=='[')
        {
            old=getNum(tmp+1);
            readRefer(old);
        }
        else
        {
            readLine(tmp);
            while(gets(tmp))
            {
                if(isEmp(tmp)) break;
                readLine(tmp);
            }
            puts("");
        }
    }
}

void printRef()
{
    sort(refers+1,refers+refn);
    for(int i=1;i<refn;i++)
    {
        printf("[%d]%s\n",i,refers[i].str);
    }
}

void init()
{
    refn=ocrn=1;
    memset(mpold,0,sizeof(mpold));
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    init();
    readTxt();
    printRef();
    return 0;
}
