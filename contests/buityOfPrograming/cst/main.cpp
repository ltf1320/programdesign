#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100+10;
char word[maxn][maxn];
char ss[maxn][maxn];
struct Tree
{
    int to;
    Tree* next [30];
    Tree()
    {
        to=-1;
        memset(next,0,sizeof(next));
    }
    void reset()
    {
        to=-1;
        for(int i=0;i<30;i++)
        {
            if(next[i])
            {
                next[i]->reset();
                delete next[i];
                next[i]=0;
            }
        }
    }
};
Tree head;

void insert(char *s,int to)
{
    int p=0;
    Tree *now=&head;
    while(s[p])
    {
        if(!now->next[s[p]-'a'])
            now->next[s[p]-'a']=new Tree();
        now=now->next[s[p]-'a'];
        p++;
    }
    now->to=to;
}

int find(char *s)
{
    int p=0;
    Tree *now=&head;
    while(s[p])
    {
        if(!now->next[s[p]-'a'])
            return -1;
        now=now->next[s[p]-'a'];
        p++;
    }
    return now->to;
}

int change(char *s)
{
    int kn=0,p=0;
    int t=0;
    while(s[p])
    {
        if(s[p]==' ')
        {
            ss[kn][t]=0;
            t=0;
            p++;
            kn++;
        }
 //       if(!s[p]) return kn;
        ss[kn][t]=s[p];
        t++;p++;
    }
    ss[kn][t]=0; //!!!
    return kn+1;
}


int main()
{
    freopen("in.txt","r",stdin);
    int T;
    int N,M;
    int kn,tt;
    char tmp[maxn],tmp2[maxn];
    int cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        head.reset();
        kn=0;
        scanf("%d%d",&N,&M);
        for(int i=0; i<M; i++)
        {
            scanf("%s%s",tmp,word[i]);
            insert(tmp,i);
        }
        getchar();
        gets(tmp2);
        kn=change(tmp2);
        for(int i=0;i<N-1;i++)
            for(int j=0;j<kn;j++)
            {
                tt=find(ss[j]);
                if(tt!=-1)
                {
                    strcpy(ss[j],word[tt]);
                }
            }
        printf("Case #%d:",cas);
        for(int i=0;i<kn;i++)
            printf(" %s",ss[i]);
        putchar('\n');
    }
    return 0;
}
