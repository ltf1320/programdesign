#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=50+10;

int mp[300];
int N,M,P;
int code;
struct Node
{
    Node *fail;
    Node *next[maxn];
    int code;
    bool end;
    Node()
    {
        fail=NULL;
        for(int i=0;i<maxn;i++)
            next[i]=NULL;
        end=0;
    }
};
Node Tree;


void insert(const char *s)
{
    int i=0;
    Node *now=&Tree;
    while(s[i])
    {
        if(now->next[mp[s[i]]]==NULL)
        {
            now->next[mp[s[i]]]=new Node();
            now->next[mp[s[i]]]->code=code++;
        }
        now=now->next[mp[s[i]]];
        i++;
    }
    now->end=1;
}

void BuildAC()
{
    Node *now,*tmp;
    queue<Node*> que;
    que.push(&Tree);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<N;i++)
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
                        now->next[i]->end=1;
                    now->next[i]->fail=tmp->next[i];
                }
            }
    }
}

struct Mat
{
    int m[maxn][maxn];
    Mat operator*(const Mat &a)
    {
        Mat res;
        for(int i=0;i<code;i++)
            for(int j=0;j<code;j++)
            {
                res.m[i][j]=0;
                for(int k=0;k<code;k++)
                    res.m[i][j]+=m[i][k]*a.m[k][j];
            }
        return res;
    }
    Mat operator^(int n)
    {
        Mat res;
        Mat now=*this;
        for(int i=0;i<code;i++)
            res.m[i][i]=1;
        while(n)
        {
            if(n&1) res=res*now;
            now=now*now;
            n>>=1;
        }
        return res;
    }
    void print()
    {
        for(int i=0;i<code;i++){
            for(int j=0;j<code;j++)
                printf("%d ",m[i][j]);
            printf("\n");
        }
    }
};

void work()
{
    Mat dp;
    Node *now,*tmp;
    memset(dp.m,0,sizeof(dp.m));
    queue<Node *> que;
    que.push(&Tree);
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        for(int i=0;i<N;i++)
        {
            if(now->next[i]!=NULL)
            {
                if(!now->next[i]->end)
                {
                    que.push(now->next[i]);
                    dp.m[now->code][now->next[i]->code]++;
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
    dp=dp^M;
    int res=0;
    for(int i=0;i<code;i++)
    {
        res+=dp.m[0][i];
    }
    printf("%d\n",res);
}

void init()
{
    memset(mp,-1,sizeof(mp));
    Tree.code=0;
    code=1;
}

void input()
{
    char tmp[maxn];
    char ch;
    scanf("%d%d%d",&N,&M,&P);
    ch=getchar();
    for(int i=0;i<N;i++)
    {
        ch=getchar();
        mp[ch]=i;
    }
    getchar();
    for(int i=0;i<P;i++)
    {
        scanf("%s",tmp);
        insert(tmp);
    }
    BuildAC();
}

int main()
{
    freopen("in.txt","r",stdin);
    init();
    input();
    work();
    return 0;
}
