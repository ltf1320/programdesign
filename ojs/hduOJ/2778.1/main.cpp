/*
4 10
ATAA
TAA
AA
A
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const long long maxn=2000000000;
const int maxm=10+2;
__int64 m,n;

int mp(char ch)
{
    switch(ch)
    {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'T':
        return 2;
    case 'G':
        return 3;
    }
    return -1;
}

struct Node
{
    Node *fail;
    Node *next[4];
    bool end;
    int code;
    Node()
    {
        fail=0;
        for(int i=0; i<4; i++) next[i]=0;
        end=0;
    }
    void reset()
    {
        fail=NULL;
        for(int i=0; i<4; i++)
            if(next[i]!=NULL)
            {
                next[i]->reset();
                delete next[i];
                next[i]=NULL;
            }
        end=0;
    }
};
Node Tree;

int code;
void insert(const char *s)
{
    int i=0;
    Node *p=&Tree;
    while(s[i])
    {
        if(p->next[mp(s[i])]==NULL)
        {
            p->next[mp(s[i])]=new Node();
            p->next[mp(s[i])]->code=code++;
        }
        p=p->next[mp(s[i])];
        i++;
    }
    p->end=1;
}

void BuildAC()
{
    Node *now;
    Node *tmp;
    queue<Node*> que;
    que.push(&Tree);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0; i<4; i++)
        {
            if(now->next[i]!=NULL)
            {
                que.push(now->next[i]);
                tmp=now->fail;
                while(tmp!=NULL&&tmp->next[i]==NULL)
                    tmp=tmp->fail;
                if(tmp==NULL)
                    now->next[i]->fail=&Tree;
                else if(tmp->next[i]!=NULL)
                {
                    if(tmp->next[i]->end)
                        now->next[i]->end=1; //!!!±ðÂ©
                    now->next[i]->fail=tmp->next[i];
                }
            }
        }
    }
}

struct Mat
{
    __int64 m[maxm*maxm][maxm*maxm];
    Mat operator*(const Mat& a)
    {
        Mat r;
        for(int i=0; i<code; i++)
            for(int j=0; j<code; j++)
            {
                r.m[i][j]=0;
                for(int k=0; k<code; k++)
                    r.m[i][j]+=m[i][k]*a.m[k][j];
                r.m[i][j]%=100000;
            }
        return r;
    }
    Mat operator^(long long n)
    {
        Mat res;
        Mat now;
        memset(res.m,0,sizeof(res));
        memset(now.m,0,sizeof(now.m));
        for(int i=0; i<code; i++)
            for(int j=0; j<code; j++)
            {
                now.m[i][j]=m[i][j];
                res.m[i][i]=1;
            }
        while(n)
        {
            if(n&1)
                res=res*now;
//            res.print();
            now=now*now;
            n>>=1;
        }
        return res;
    }
    void print()
    {
        for(int i=0; i<code; i++)
        {
            for(int j=0; j<code; j++)
                printf("%I64d ",m[i][j]);
            printf("\n");
        }
    }
};

void input()
{
    char tmp[maxm];
    for(int i=0; i<m; i++)
    {
        scanf("%s",tmp);
        insert(tmp);
    }
    BuildAC();
}

Mat dp;
void work()
{
    Mat dp;
    Node *now,*tmp;
    memset(dp.m,0,sizeof(dp));
    queue<Node*> que;
    que.push(&Tree);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            if(now->next[i]!=NULL)
            {
                if(!now->next[i]->end)
                {
                    dp.m[now->code][now->next[i]->code]++;
                    que.push(now->next[i]);
                }
                continue;
            }
            tmp=now->fail;
            while(tmp!=NULL&&tmp->next[i]==NULL)
                tmp=tmp->fail;
            if(tmp==NULL)
                dp.m[now->code][0]++;
            else if(!tmp->next[i]->end)
                dp.m[now->code][tmp->next[i]->code]++;
        }
    }
    dp.print();
    dp=dp^n;
    __int64 res=0;
    for(int i=0;i<code;i++)
    {
        res+=dp.m[0][i];
        res%=100000;
    }
    printf("%I64d\n",res);
}

void init()
{
    code=1;
    Tree.code=0;
 //   Tree.reset();
    memset(dp.m,0,sizeof(dp));
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%I64d%I64d",&m,&n);
    init();
    input();
    work();
    return 0;
}
