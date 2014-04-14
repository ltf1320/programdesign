#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn=100000;
const int pri=99991;
char *res;
struct Node
{
    Node *next;
    char str[11];
    char Eng[11];
    Node(){next=NULL;str[0]=0;Eng[0]=0;}
    Node(char *s1,char *s2)
    {
        strcpy(str,s1);
        strcpy(Eng,s2);
        next=NULL;
    }
};
Node nds[maxn];

int abs(int a){return a>0?a:-a;}

int getHash(char *s)
{
    int len=strlen(s);
    int res=0;
    for(int i=1;i<=len;i++)
        res+=(s[i]-'a')*(s[i]-'a')*i*i;
    return res%pri;
}
int APHash(const char *str)
{
    int hash = 0;
    char ch;
    for (long i = 0; ch = (int)*str++; i++)
    {
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
        }
    }
    return abs(hash)%pri;
}

void insert(char *s1,char *s2)
{
    int has=APHash(s1);
    Node *p=&nds[has];
    if(p->next!=NULL)
        for(;p->next!=NULL;p=p->next);
    p->next=new Node(s1,s2);
}

bool find(char *s)
{
    int has=APHash(s);
    Node *p=&nds[has];
    int len=strlen(s);
    int tml;
    int i;
    for(p=p->next;p!=NULL;p=p->next)
    {
        tml=strlen(p->str);
        if(tml!=len) continue;
        for(i=0;i<tml;i++)
        {
            if(p->str[i]!=s[i]) break;
        }
        if(i==tml)
        {
            res=p->Eng;
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("in.txt","r",stdin);
    char tmp1[11];
    char tmp2[11];
    int hash;
    char ch;
    int k;
    while(1)
    {
        ch=getchar();
        if(ch=='\n') break;
        k=0;
        while(ch!=' ')
        {
            tmp1[k++]=ch;
            ch=getchar();
        }
        tmp1[k]=0;
        k=0;
        while((ch=getchar())!='\n')
            tmp2[k++]=ch;
        tmp2[k]=0;
        hash=APHash(tmp2);
        insert(tmp2,tmp1);
    }

    while(~scanf("%s",tmp1))
    {
        if(find(tmp1))
            printf("%s\n",res);
        else printf("eh\n");
    }
    return 0;
}
