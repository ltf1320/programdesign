#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
const int maxn=2000+10;
char refers[maxn][300];
int ocr[maxn];
int aocr[maxn];
int mp[maxn];
int ocrn;
int refn;

char tmp[100];
int getNum(char *s)
{
    int now=*s++;
    while(*s&&*s>='0'&&*s<='9')
    {
        now=now*10+*s-'0';
        s++;
    }
    return now;
}


void analyse(char *s)
{
    int l=strlen(s);
    int now;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='[')
        {
            now=getNum(s+i+1);
            if(!mp[now])
                mp[now]=refn++;
            if(ocr[mp[now]]==0)
                ocr[mp[now]]=ocrn++;
            printf("[%d]",ocr[mp[now]]);
            while(s[i]!=']') i++;
        }
        else putchar(s[i]);
    }
    putchar('\n');
}


void read()
{
    char *tt,*p;
    int now,rf;
    while(gets(tmp))
    {
        if(tmp[0]==0) continue;
        if(tmp[0]=='[')
        {
            now=getNum(tmp+1);
            if(mp[now])
                rf=mp[now];
            else
            {
                rf=mp[now]=refn++;
            }
            tt=tmp+1;
            while(*tt!=']')tt++;
            tt++;
//            strcpy(refers[now],tt);
            p=refers[rf];
            while(*tt)
              *p++=*tt++;
            *p++='\n';
            *p=0;
            while(gets(tmp))
            {
                if(tmp[0]==0) break;
 //               strcat(refers[now],"\n");
 //               strcat(refers[now],tmp);
                tt=tmp;
                while(*tt)
                    *p++=*tt++;
                *p++='\n';
                *p=0;
            }
        }
        else
        {
            analyse(tmp);
            while(gets(tmp))
            {
                if(tmp[0]==0) break;
                analyse(tmp);
            }
            putchar('\n');
        }
    }
}


void printRef()
{

    if(refn!=ocrn) //> RE ,< WA
    {
        int pp=0;
        printf("%d",1/pp);
    }
    int dd=0;

    for(int i=1;i<refn;i++)
    {
        if(ocr[i]==0)
        {
            printf("[%d]%s\n",dd+1,refers[i]);
            dd++;
            ocrn++;
        }
    }
    for(int i=1;i<refn;i++)
        aocr[ocr[i]]=i;
    for(int i=1;i<ocrn-dd;i++)
    {
        printf("[%d]%s",dd+i,refers[aocr[i]]);
        putchar('\n');
    }
}

void init()
{
    refn=ocrn=1;
    memset(ocr,0,sizeof(ocr));
    memset(aocr,0,sizeof(aocr));
    memset(mp,0,sizeof(mp));
}

int main()
{
    freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    init();
    read();
    printRef();
    return 0;
}
