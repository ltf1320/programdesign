#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10;
bool finded;

int mp(char ch)
{
    switch(ch)
    {
    case 'A':
    case 'B':
    case 'C':
        return 2;
    case 'D':
    case 'E':
    case 'F':
        return 3;
    case 'G':
    case 'H':
    case 'I':
        return 4;
    case 'J':
    case 'K':
    case 'L':
        return 5;
    case 'M':
    case 'N':
    case 'O':
        return 6;
    case 'P':
    case 'R':
    case 'S':
        return 7;
    case 'T':
    case 'U':
    case 'V':
        return 8;
    case 'W':
    case 'X':
    case 'Y':
        return 9;
    default:
        return -1;
    }
}

struct Node
{
    Node *next[maxn];
    int num;
    Node()
    {
        num=0;
        memset(next,0,sizeof(next));
    }
};
Node Tree;

void insert(const int *s)
{
    Node *p=&Tree;
    for(int i=0; i<7; i++)
    {
        if(p->next[s[i]]==NULL)
            p->next[s[i]]=new Node();
        p=p->next[s[i]];
    }
    p->num++;
}
int now[maxn];
void find(Node *p,int dp)
{
    if(dp==7)
    {
        if(p->num>1)
        {
            finded=1;
            for(int i=0; i<7; i++)
            {
                if(i==3) putchar('-');
                printf("%d",now[i]);
            }
            printf(" %d\n",p->num);
        }
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            if(p->next[i]!=NULL)
            {
                now[dp]=i;
                find(p->next[i],dp+1);
            }
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int tmp[maxn],k;
    char ch;
    char tt[100];
    int T;
    scanf("%d",&T);
    while(T--)
    {
        k=0;
        while(k<7)
        {
            ch=getchar();
            if(ch>='0'&&ch<='9')
            {
                tmp[k++]=ch-'0';
            }
            else if(mp(ch)!=-1)
            {
                tmp[k++]=mp(ch);
            }
        }
        insert(tmp);
        gets(tt);
    }
    find(&Tree,0);
    if(!finded)
        printf("No duplicates.\n");
    return 0;
}
