#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
const int maxm=2000+100;
const int maxn=30;
const int pri=99997;
const int inf=0x3f3f3f3f;
int N,M;

char str[maxm];
map<char,int> mp;
char alph[maxn];
int add[maxn];
int del[maxn];
int addsum[maxm];
int delsum[maxm];

struct Node
{
    int from,to;
    Node *next;
    Node(){next=NULL;}
    Node(int f,int t):from(f),to(t),next(NULL){}
};
Node hash[100000];

int getHash(int from,int to,bool st)
{
    int hash = 0;
    char ch;
    for (int i = st?from:to;st?(i<=to):(i>=from); st?i++:i--)
    {
        ch=str[i];
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
        }
    }
    return ((int)fabs(hash))%pri;
}

void insert(int from,int to)
{
    int has=getHash(from,to,1);
    Node *p=&hash[has];
    while(p->next)
    {
        if(p->next->from==from&&p->next->to==to)
            return;

    }
    p->next=new Node(from,to);
}

void input()
{
    scanf("%d%d",&N,&M);
    scanf("%s",str+1);
    char ch;
    for(int i=0;i<N;i++)
    {
        scanf("%c%d%d%c",&alph[i],&add[i],&del[i],&ch);
        mp[alph[i]]=i;
    }
    addsum[0]=0;
    delsum[0]=0;
    for(int i=1;i<=M;i++)
    {
        addsum[i]=addsum[i-1]+add[mp[str[i]]];
        delsum[i]=delsum[i-1]+del[mp[str[i]]];
    }
}

Node* find(int from,int to)
{
    int has=getHash(from,to,0);
    Node *p=hash[has].next;
    while(p)
    {
        if(to-from==p->to-p->from)
        {
            for(int i=0;i<=to-from;i++)
            {
                if(str[p->from+i]!=str[p->to-i])
                    break;
                if(i==to-from)
                    return p;
            }
        }
        p=p->next;
    }
    return NULL;
}

int getCost(int f,int t,int rf,int rt)
{
    int res=inf;
    int tmp;
    if(f>rt) return inf;
    if(t<rf)
    {
        tmp=delsum[f]-delsum[0]+delsum[rf]-delsum[t]+delsum[M]-delsum[rt];
        if(tmp<res) res=tmp;
        tmp=addsum[f]-addsum[0]+delsum[rf]-delsum[t]+delsum[M]-delsum[rt];
        if(tmp<res) res=tmp;
        tmp=delsum[f]-delsum[0]+addsum[rf]-addsum[t]+delsum[M]-delsum[rt];
        if(tmp<res) res=tmp;
        tmp=delsum[f]-delsum[0]+delsum[rf]-delsum[t]+addsum[M]-addsum[rt];
        if(tmp<res) res=tmp;
        tmp=addsum[f]-addsum[0]+addsum[rf]-addsum[t]+delsum[M]-delsum[rt];
        if(tmp<res) res=tmp;
        tmp=addsum[f]-addsum[0]+delsum[rf]-delsum[t]+addsum[M]-addsum[rt];
        if(tmp<res) res=tmp;
        tmp=delsum[f]-delsum[0]+addsum[rf]-addsum[t]+addsum[M]-addsum[rt];
        if(tmp<res) res=tmp;
        tmp=addsum[f]-addsum[0]+addsum[rf]-addsum[t]+addsum[M]-addsum[rt];
        if(tmp<res) res=tmp;
    }
    else
    {
        tmp=delsum[f]-delsum[0]+delsum[M]-delsum[rt];
        if(tmp<res) res=tmp;
        tmp=addsum[f]-addsum[0]+delsum[M]-delsum[rt];
        if(tmp<res) res=tmp;
        tmp=delsum[f]-delsum[0]+addsum[M]-addsum[rt];
        if(tmp<res) res=tmp;
        tmp=addsum[f]-addsum[0]+addsum[M]-addsum[rt];
        if(tmp<res) res=tmp;
    }
    return res;
}

int work()
{
    int res=inf;
    Node *fd;
    if(M==0) return 0;
    for(int i=1;i<=M;i++)
    {
        if(str[i]!=str[M-i+1]) break;
        if(i==M) return 0;
    }
    for(int i=1;i<=M;i++)
        for(int j=0;j<=M-i;j++)
            insert(i,i+j);
    for(int i=1;i<=M;i++)
        for(int j=0;j<=M-i;j++)
            if((fd=find(i,i+j)))
            {
                res=min(res,getCost(fd->from,fd->to,i,i+j));
            }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    input();
    printf("%d\n",work());
    return 0;
}
