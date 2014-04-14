#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int maxn=1000+10;
char game[maxn][maxn];
char words[maxn];
int wdlen[maxn];
int minlen;
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
    minlen=maxn;
    for(int i=1; i<=W; i++)
    {
        gets(words);
        insert(words,i);
        wdlen[i]=strlen(words);
        if(wdlen[i]<minlen) minlen=wdlen[i];
    }
    BuildAC();
}

void match(const char *s,int x,int y,int drec)
{
    Node *now=&Tree;
    Node *tmp;
    int i=0;
    while(s[i])
    {
        while(now->fail!=NULL&&now->next[s[i]-'A']==NULL)
            now=now->fail;
        if(now->next[s[i]-'A']!=NULL)
        {
            now=now->next[s[i]-'A'];
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
    }
}

void work()
{
    int nx,ny,p;
    for(int d=0; d<8; d++)
    {
        for(int i=0; i<L; i+=L-1)
        {
            if(i+drex[d]>=0&&i+drex[d]<L)
            {
                for(int j=0; j<C; j++)
                {
                    nx=i;
                    ny=j;
                    p=0;
                    while(nx>=0&&nx<L&&ny<C&&ny>=0)
                    {
                        words[p++]=game[nx][ny];
                        nx+=drex[d];
                        ny+=drey[d];
                    }
                    if(p<minlen) continue;
                    words[p]=0;
                    match(words,i,j,d);
                }
            }
            if(i+drey[d]>=0&&i+drey[d]<C)
            {
                for(int j=0; j<L; j++)
                {
                    nx=j;
                    ny=i;
                    p=0;
                    while(nx>=0&&nx<L&&ny<C&&ny>=0)
                    {
                        words[p++]=game[nx][ny];
                        nx+=drex[d];
                        ny+=drey[d];
                    }
                    words[p]=0;
                    if(p<minlen) continue;
                    match(words,j,i,d);
                }
            }
        }
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
