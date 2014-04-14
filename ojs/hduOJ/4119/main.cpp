#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=50+10;
const int maxm=100+10;
int N,M;
int hn;
int cas=1;

char letter[maxn][maxn];
char substr[4][maxn*maxn/4];

struct Node
{
    bool end;
    Node *next[30];
    Node()
    {
        for(int i=0;i<30;i++)
            next[i]=NULL;
        end=0;
    }
    void reset()
    {
        end=0;
        for(int i=0;i<30;i++)
            if(next[i]!=NULL)
            {
                next[i]->reset();
                delete next[i];
                next[i]=NULL;
            }
    }
};
Node Tree;

void insert(const char *s)
{
    int i=0;
    Node *p=&Tree;
    while(s[i])
    {
        if(p->next[s[i]-'a']==NULL)
            p->next[s[i]-'a']=new Node();
        p=p->next[s[i]-'a'];
        i++;
    }
    p->end=1;
}

struct Mask
{
    int x,y;
    void Rotate()
    {
        int t=x;
        x=y;
        y=N-1-t;
    }
    bool operator<(const Mask &a) const
    {
        if(x==a.x)
            return y<a.y;
        else return x<a.x;
    }
};
Mask masks[maxn*maxn/4];

void input()
{
    char ch;
    char tmp[maxn];
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            scanf("%c",&letter[i][j]);
            if(letter[i][j]=='\n')
                j--;
            if(letter[i][j]=='.')
                letter[i][j]=' ';
        }
    hn=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            scanf("%c",&ch);
            if(ch=='\n'){j--;continue;}
            if(ch=='*')
            {
                masks[hn].x=i;
                masks[hn].y=j;
                hn++;
            }
        }
    scanf("%d",&M);
    getchar();
    Tree.reset();
    for(int i=0;i<M;i++)
    {
        gets(tmp);
        insert(tmp);
    }
}

bool compare(const char *a,const char *b)
{
    if(a[0]==0) return true;
    int pa=0,pb=0;
    while(a[pa]&&b[pb])
    {
        if(a[pa]==' ')
        {
            pa++;
            continue;
        }
        if(b[pb]==' ')
        {
            pb++;
            continue;
        }
        if(a[pa]!=b[pb]) return a[pa]>b[pb];
        pa++;
        pb++;
    }
    return a[pa]>b[pb];
}

bool judge(const char *s)
{
    Node *now=&Tree;
    for(int p=0;s[p];p++)
    {
        if(now->next[s[p]-'a']==NULL) return false;
        now=now->next[s[p]-'a'];
    }
    return now->end;
}

void work()
{
    for(int i=0;i<hn;i++)
        substr[0][i]=letter[masks[i].x][masks[i].y];
    substr[0][hn]=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=0;j<hn;j++)
            masks[j].Rotate();
        sort(masks,masks+hn);
        for(int j=0;j<hn;j++)
            substr[i][j]=letter[masks[j].x][masks[j].y];
        substr[i][hn]=0;
    }


    char stmp[maxn*maxn];
    char now[maxn*maxn];
    char res[maxn*maxn];
    res[0]=0;
    for(int i=0;i<4;i++)
    {
        int k=i-1;
        int j,p;
        for(j=0;j<4;j++)
        {
            k++;
            if(k>3) k%=4;
            for(int p=0;p<hn;p++)
            {
                stmp[j*hn+p]=substr[k][p];
            }
        }
        stmp[4*hn]=0;
        p=0;
        while(p<4*hn)
        {
            if(stmp[p]==' ')
            {
                p++;
                continue;
            }
            sscanf(stmp+p,"%s",now);
            if(!judge(now)) break;
            p+=strlen(now);
        }
        if(p>=4*hn&&compare(res,stmp))
            strcpy(res,stmp);
    }
    printf("Case #%d: ",cas++);
    if(res[0]==0)
        printf("FAIL TO DECRYPT\n");
    else
    {
        int s=strlen(res)-1;
        for(;res[s]==' ';s--)
            res[s]=0;
        int p=0;
        while(res[p]==' ') p++;
        for(;res[p];p++)
        {
            if(res[p]==' '&&res[p+1]==' ') continue;
            putchar(res[p]);
        }
        putchar('\n');
    }
}


int main()
{
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        input();
        work();
    }
    return 0;
}
