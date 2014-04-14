#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=1000+10;
const int inf=0x3f3f3f3f;
int dis[maxn][maxn];
int N,M;

int getN(char ch)
{
    if(ch>='a'&&ch<='z')
        return ch-'a';
    else return ch-'A'+26;
}

struct Trie
{
    Trie *next[60];
    int code;
    Trie():code(-1){memset(next,0,sizeof(next));}
};
Trie root;
int code;
void insert(char *s)
{
    Trie* now=&root;
    int nxt;
    while(*s)
    {
        nxt=getN(*s);
        if(!now->next[nxt])
            now->next[nxt]=new Trie();
        now=now->next[nxt];
        s++;
    }
    now->code=code++;
}

int find(char *s)
{
    Trie* now=&root;
    int nxt;
    while(*s)
    {
        nxt=getN(*s);
        if(!now->next[nxt])
            now->next[nxt]=new Trie();
        now=now->next[nxt];
        s++;
    }
    return now->code;
}

void floyd()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                if(dis[j][k]>dis[j][i]+dis[i][k])
                    dis[j][k]=dis[j][i]+dis[i][k];
            }
        }
}

void input()
{
    char tmp[20],t2[20];
    int c1,c2;
    for(int i=0;i<N;i++)
    {
        scanf("%s",tmp);
        insert(tmp);
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        scanf("%s%s",tmp,t2);
        c1=find(tmp);
        c2=find(t2);
        dis[c1][c2]=dis[c2][c1]=1;
    }
}

void work()
{
    floyd();
    int res=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            res=max(res,dis[i][j]);
        }
    printf("%d\n",res);
}

void init()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dis[i][j]=inf;
    code=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N))
    {
        if(!N)break;
        init();
        input();
        work();
    }
    return 0;
}
