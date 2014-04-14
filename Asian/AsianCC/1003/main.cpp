#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=80;
const int pri=79;

int abs(int a)
{
    return a>0?a:-a;
}

struct Node
{
    Node *next;
    char name[20];
    int num;
    int type;//1 for normal,2 for mix,3 for con;
    int s; //(总)价格
    int mn; //合成所需数目
    char mix[6][20];
    int mixn[6];
    Node() {}
    Node(char *ss,int d)
    {
        num=1;
        strcpy(name,ss);
        s=d;
        next=NULL;
    }
    bool operator==(const Node &a)
    {
        int i;
        for(i=0; name[i]&&a.name[i]; i++)
        {
            if(i>=15) break;
            if(name[i]!=a.name[i]) return false;
        }
        if(name[i]!=a.name[i]) return false;
        return true;
    }
    bool operator==(char *a)
    {
        int i;
        for(i=0; name[i]&&a[i]; i++)
        {
            if(i>=15) break;
            if(name[i]!=a[i]) return false;
        }
        if(name[i]!=a[i]) return false;
        return true;
    }
    void reset()
    {
        if(next!=NULL)
        {
            next->reset();
            delete next;
        }
        next=NULL;
    }
};

Node nds[maxn];

int monny;
int ge;
Node* backpack[10];

int find(char *a)
{
    for(int i=0; i<6; i++)
    {
        if(backpack[i]==NULL) continue;
        if((*backpack[i])==a)
        {
            return i;
            break;
        }
    }
    return -1;
}

int getHash(char *str)
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


void init()
{
    monny=0;
    ge=0;
    for(int i=0; i<maxn; i++)
    {
        nds[i].reset();
    }
    for(int i=0;i<6;i++)
        backpack[i]=NULL;
}

void buy(Node &a)
{
    if(monny<a.s) return;
    if(a.type==1)
    {
        if(ge==6) return;
        for(int i=0; i<6; i++)
        {
            if(backpack[i]!=NULL) continue;
            backpack[i]=new Node(a);
            backpack[i]->num=1;
            break;
        }
    }
    if(a.type==2)
    {
        int p[6];
        for(int i=0; i<a.mn; i++)
        {
            if((p[i]=find(a.mix[i]))==-1) return;
        }
        for(int i=0;i<a.mn;i++)
        {
            delete backpack[p[i]];
            backpack[p[i]]=NULL;
            ge--;
        }
        if(ge==6) return;
        for(int i=0; i<6; i++)
        {
            if(backpack[i]!=NULL) continue;
            backpack[i]=new Node(a);
            backpack[i]->num=1;
            break;
        }
    }
    if(a.type==3)
    {
        if(ge==6) return;
        int p=find(a.name);
        if(p!=-1)
        {
            backpack[p]->s+=a.s;
            backpack[p]->num++;
        }
        for(int i=0; i<6; i++)
        {
            if(backpack[i]!=NULL) continue;
            backpack[i]=new Node(a);
            backpack[i]->num=1;
            break;
        }
    }
    ge++;
    monny-=a.s;
}


void sell(const Node &a)
{
    if(ge==0) return;
    for(int i=0; i<6; i++)
    {
        if(backpack[i]==NULL) continue;
        if((*backpack[i])==a)
        {
            monny+=backpack[i]->s;
            ge--;
            delete backpack[i];
            backpack[i]=NULL;
        }
    }
}

bool input()
{
    int n,hs;
    int s;
    char tmp[20];
    char ch;
    Node *p;
    if(scanf("%d",&n)==EOF) return false;
    while(n--)
    {
        scanf("%s%d",tmp,&s);
        hs=getHash(tmp);
        p=&nds[hs];
        if(p->next!=NULL)
            for(;p->next!=NULL;p=p->next);
        p->next=new Node(tmp,s);
        p=p->next;
        p->type=1;
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%d:",tmp,&s);
        hs=getHash(tmp);
        p=&nds[hs];
        if(p->next!=NULL)
            for(;p->next!=NULL;p=p->next);
        p->next=new Node(tmp,s);
        p=p->next;
        p->type=2;
        int i=0;
        ch=getchar();
        if(ch=='\n')
        {
            p->mn=0;
            continue;
        }
        while(scanf("%s %d%c",tmp,&s,&ch))
        {
            strcpy(p->mix[i++],tmp);
            p->mixn[i]=s;
            if(ch=='\n') break;
        }
        p->mn=i;
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%d",tmp,&s);
        hs=getHash(tmp);
        p=&nds[hs];
        if(p->next!=NULL)
            for(;p->next!=NULL;p=p->next);
        p->next=new Node(tmp,s);
        p=p->next;
        p->type=3;
    }
    return true;
}

Node *getNode(char *ss)
{
    int hn=getHash(ss);
    Node *p=&nds[hn];
    for(p=p->next;p!=NULL;p=p->next)
    {
        if((*p)==ss) return p;
    }
    return NULL;
}

void GO()
{
    int n;
    char ch;
    int tn;
    char tmp[20];
    Node *p;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%c",&ch);
        if(ch=='+')
        {
            gets(tmp);
            if(tmp[0]>='0'&&tmp[0]<='9')
            {
                sscanf(tmp,"%d",&tn);
                monny+=tn;
            }
            else
            {
                p=getNode(tmp);
                if(p==NULL) continue;
                buy(*p);
            }
        }
        else
        {
            gets(tmp);
            p=getNode(tmp);
            if(p==NULL) continue;
            sell(*p);
        }
    }
}

bool cmp(Node *a,Node *b)
{
    int i=0;
    if(b==NULL) return true;
    if(a==NULL) return false;
    while(a->name[i]&&b->name[i])
    {
        if(a->name[i]!=b->name[i]) break;
        i++;
        if(i>=15) break;
    }
    return a->name[i]<b->name[i];
}
int cas;
void PR()
{
    cas++;
    printf("Case %d:\n",cas);
    printf("%d\n",monny);
    printf("%d\n",ge);
    sort(backpack,backpack+6,cmp);
    for(int i=0;i<ge;i++)
    {
        printf("%s:%d\n",backpack[i]->name,backpack[i]->num);
    }

}

int main()
{
    freopen("in.txt","r",stdin);
    cas=0;
    init();
    bool flag=0;
    while(input())
    {
        GO();
        if(flag) printf("\n");
        flag=1;
        PR();
        init();
    }
    return 0;
}
