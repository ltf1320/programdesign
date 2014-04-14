#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int maxn=1000+10;
char game[maxn][maxn];
char words[maxn];
int wdlen[maxn];
int L,C,W;

const int drex[10]= {-1,-1,0,1,1,1,0,-1};
const int drey[10]= {0,1,1,1,0,-1,-1,-1};

struct Node
{
    Node *fail;
    Node *next[30];
    int end;
    Node()
    {
        fail=false;
        for(int i=0; i<26; i++)
            next[i]=0;
        end=0;
    }
};
Node Tree;

void insert(const char *s,int code)
{
    int i=0;
    Node *now=&Tree;
    while(s[i])
    {
        if(now->next[s[i]-'A']==NULL)
            now->next[s[i]-'A']=new Node();
        now=now->next[s[i]-'A'];
        i++;
    }
    now->end=code;
}


void BuildAC()
{
    Node *now=&Tree;
    Node *tmp;
    now->fail=NULL;
    queue<Node *>que;
    que.push(&Tree);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0; i<26; i++)
        {
            if(now->next[i]!=NULL)
            {
                que.push(now->next[i]);
                if(now==&Tree)
                    now->next[i]->fail=&Tree;
                else
                {
                    tmp=now->fail;
                    while(tmp!=NULL&&tmp->next[i]==NULL)
                        tmp=tmp->fail;
                    if(tmp==NULL) now->next[i]->fail=&Tree;
                    else if(tmp->next[i]!=NULL)
                        now->next[i]->fail=tmp->next[i];
                }
            }
        }
    }
}

struct RES
{
    int x,y;
    char dir;
};
RES res[maxn];



void input()
{
    getchar();
    for(int i=0; i<L; i++)
        gets(game[i]);
    for(int i=1; i<=W; i++)
    {
        gets(words);
        insert(words,i);
        wdlen[i]=strlen(words);
    }
    BuildAC();
}

void match(int x,int y,int drec)
{
    Node *now=&Tree;
    Node *tmp;
    int i=0;
    int nx=x;
    int ny=y;
    char nc;
    while(nx>=0&&nx<L&&ny>=0&&ny<C)
    {
        nc=game[nx][ny];
        while(now->fail!=NULL&&now->next[nc-'A']==NULL)
            now=now->fail;
        if(now->next[nc-'A']!=NULL)
        {
            now=now->next[nc-'A'];
            tmp=now;
            while(tmp->fail!=NULL&&tmp->end!=-1)
            {
                if(tmp->end)
                {
                    res[tmp->end].x=x+(i-wdlen[tmp->end]+1)*drex[drec];
                    res[tmp->end].y=y+(i-wdlen[tmp->end]+1)*drey[drec];
                    res[tmp->end].dir=drec+'A';
                }
                tmp->end=-1;
            }

        }
        i++;
        nx+=drex[drec];
        ny+=drey[drec];
    }
}

void work()
{
    for(int i=0;i<C;i++)
    {
        match(L-1,i,0);
        match(L-1,i,1);
        match(L-1,i,7);
    }
    for(int i=0;i<C;i++)
    {
        match(0,i,3);
        match(0,i,4);
        match(0,i,5);
    }
    for(int i=0;i<L;i++)
    {
        match(i,0,1);
        match(i,0,2);
        match(i,0,3);
    }
    for(int i=0;i<L;i++)
    {
        match(i,C-1,5);
        match(i,C-1,6);
        match(i,C-1,7);
    }
}


void print()
{
    for(int i=1; i<=W; i++)
    {
        printf("%d %d %c\n",res[i].x,res[i].y,res[i].dir);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&L,&C,&W);
    input();
    work();
    print();
    return 0;
}
