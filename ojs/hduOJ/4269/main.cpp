#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stdexcept>
using namespace std;

const int strn=20;

struct TNode
{
    int k;
    TNode *next[30];
    TNode()
    {
        k=-1;
        for(int i=0; i<30; i++)
            next[i]=NULL;
    }
    void reset()
    {
        for(int i=0; i<30; i++)
            if(next[i]!=NULL)
            {
                next[i]->reset();
                delete next[i];
                next[i]=NULL;
            }
    }
};
TNode head;

void insert(char *s,int kk)
{
    int len=strlen(s);
    TNode *p=&head;
    int i;
    for(i=0; i<len; i++)
    {
        if(p->next[s[i]-'a']==NULL)
            p->next[s[i]-'a']=new TNode();
        p=p->next[s[i]-'a'];
    }
    p->k=kk;
}

int search(char *s)
{
    TNode *p=&head;
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        p=p->next[s[i]-'a'];
        if(p==NULL) return -1;
    }
    return p->k;
}

struct EQP
{
    char name[strn];
    int type;//1 for normal,2 for mix,3 for con;
    int s; //(总)价格
    int mn; //合成所需数目
//    int code;
    int mixn[10];
    char mix[10][strn];
    EQP() {}
    EQP(char *ss,int d)
    {
        strcpy(name,ss);
        s=d;
    }
    bool operator==(char *a)
    {
        int i;
        for(i=0; name[i]&&a[i]; i++)
        {
            if(i>=strn) break;
            if(name[i]!=a[i]) return false;
        }
        if(name[i]!=a[i]) return false;
        return true;
    }
    bool operator<(const EQP &b) const
    {
        int i=0;
        while(name[i]&&b.name[i])
        {
            if(name[i]!=b.name[i]) break;
            i++;
            if(i>=strn) break;
        }
        return name[i]<b.name[i];
    }
};

EQP eqps[100];
void getS(int pp)
{
    if(eqps[pp].type==2)
    {
        int kn;
        int res=eqps[pp].s;
        for(int i=0; i<eqps[i].mn; i++)
        {
            kn=search(eqps[i].mix[i]);
            if(kn==-1) continue;
            getS(kn);
            res+=eqps[kn].s;
        }
        eqps[pp].s=res;
    }
}


struct BP
{
    int code;
    int num;
    bool used;
    bool operator<(const BP &a)const
    {
        char *p1=eqps[code].name;
        char *p2=eqps[a.code].name;
        while((*p1)&&(*p2))
        {
            if(*p1!=*p2)
                return *p1<*p2;
            p1++;
            p2++;
        }
        return *p1<*p2;
    }
};

BP backpack[12];

int monny;
int ge;


bool input()
{
    int an=0;
    int n;
    char tmp[strn];
    int s;
    char ch;
    if(scanf("%d",&n)==EOF) return false;
    while(n--)
    {
        scanf("%s%d",tmp,&s);
        strcpy(eqps[an].name,tmp);
        eqps[an].s=s;
        eqps[an].type=1;
//        eqps[an].code=an;
        insert(tmp,an++);
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%d:",tmp,&s);
        strcpy(eqps[an].name,tmp);
        eqps[an].s=s;
        eqps[an].type=2;
//        eqps[an].code=an;
        int i=0;
        ch=getchar();
        if(ch=='\n')
        {
            eqps[an].mn=0;
            insert(tmp,an++);
            continue;
        }
        char tmp2[strn];
        while(scanf("%s %d%c",tmp2,&s,&ch))
        {
            strcpy(eqps[an].mix[i],tmp2);
            eqps[an].mixn[i++]=s;
            if(ch=='\n') break;
        }
        eqps[an].mn=i;
        insert(tmp,an++);
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%d",tmp,&s);
        strcpy(eqps[an].name,tmp);
        eqps[an].s=s;
        eqps[an].type=3;
//        eqps[an].code=an;
        insert(tmp,an++);
    }
    for(int i=0; i<an; i++)
        getS(i);
    return true;
}



int find(int s)
{
    for(int i=0; i<6; i++)
    {
        if(!backpack[i].used) continue;
        if(backpack[i].code==s)
        {
            return i;
        }
    }
    return -1;
}
int find(char *s)
{
    return find(search(s));
}


void buy(char *s)
{
    int bn=search(s);
    if(bn==-1) return;
    if(monny<eqps[bn].s) return;
    if(eqps[bn].type==1)
    {
        if(ge==6) return;
        for(int i=0; i<6; i++)
        {
            if(backpack[i].used) continue;
            backpack[i].used=1;
            backpack[i].code=bn;
            backpack[i].num=1;
            break;
        }
    }
    else if(eqps[bn].type==2)
    {
        int p[10];
        int pn=0;//需要去掉的个数
        int kn;
        int pg=0;
        bool flag;
        for(int i=0; i<eqps[bn].mn; i++)
        {
            int an=0;//这种装备在背包中的个数
            flag=1;
            kn=search(eqps[bn].mix[i]);
            if(kn==-1) continue;
            for(int j=0; j<6&&an<eqps[bn].mixn[i]; j++)
            {
                if(backpack[i].used&&backpack[j].code==kn)
                {
                    p[an++,pn++]=j;
                    flag=0;
                    if(eqps[backpack[i].code].type!=3)
                        pg++;
                    else if(backpack[i].num==1) pg++;
                }
            }
            if(flag) return;
            if(an<eqps[bn].mixn[i]) return;
        }
        if(ge-pg==6) return;
        for(int i=0; i<pn; i++)
        {
            if(eqps[backpack[p[i]].code].type==3)
            {
                if(backpack[p[i]].num==1)
                {
                    backpack[p[i]].used=0;
                    ge--;
                }
                else backpack[p[i]].num--;
            }
            else
            {
                backpack[p[i]].used=0;
                ge--;
            }
        }
        for(int i=0; i<6; i++)
        {
            if(backpack[i].used) continue;
            backpack[i].used=1;
            backpack[i].code=bn;
            backpack[i].num=1;
            break;
        }
    }
    else
    {
        if(ge==6) return;
        int p=find(eqps[bn].name);
        if(p!=-1)
        {
            backpack[p].num++;
            ge--;
        }
        else
        {
            for(int i=0; i<6; i++)
            {
                if(backpack[i].used) continue;
                backpack[i].used=1;
                backpack[i].code=bn;
                backpack[i].num=1;
                break;
            }
        }
    }
    ge++;
    monny-=eqps[bn].s;
}

void sell(char *s)
{
    if(ge==0) return;
    int p=find(s);
    if(p!=-1)
    {
        monny+=eqps[backpack[p].code].s*backpack[p].num;
        backpack[p].used=0;
        ge--;
    }
}

void GO()
{
    int n;
    char ch;
    int tn;
    char tmp[strn];
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
                buy(tmp);
            }
        }
        else
        {
            gets(tmp);
            sell(tmp);
        }
    }
}
int cas;


void PR()
{
    cas++;
    printf("Case %d:\n",cas);
    printf("%d\n",monny);
    printf("%d\n",ge);
    sort(backpack,backpack+6);
    for(int i=0; i<6; i++)
    {
        if(backpack[i].used) printf("%s: %d\n",eqps[backpack[i].code].name,backpack[i].num);
    }
}

void init()
{
    head.reset();
    monny=0;
    ge=0;
    for(int i=0; i<6; i++)
        backpack[i].used=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    cas=0;
    init();
    bool flag=0;
    try{
    while(input())
    {

        GO();
        if(flag) printf("\n");
        flag=1;
        PR();
        init();
    }
    }catch(runtime_error e)
    {
        printf("%d",1);
    }
    return 0;
}
