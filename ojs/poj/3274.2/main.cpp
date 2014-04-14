#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=100000+100;
const int maxk=30+10;

int sum[maxn][maxk];
int c[maxn][maxk];
const int Pri=99997;
int N,K;

struct Node
{
    int v;
    Node *next;
    Node()
    {
        next=NULL;
    }
};

Node hash[maxn];

int abs(const int &a) {return a>0?a:-a;}

int getHash(int c[])
{
    int p=0;
    for(int i=0; i<K; i++)
        p=(p<<2)+c[i];
    return abs(p)%Pri;
}

int main()
{
    freopen("in.txt","r",stdin);
    int now,has;
    int res;
    bool found;
    Node *p;
    scanf("%d%d",&N,&K);
    for(int i=0; i<K; i++)
        sum[0][i]=0;
    res=0;
    for(int i=1; i<=N; i++)
    {
        scanf("%d",&now);
        for(int j=0; j<K; j++)
        {
            if(now&1)
                sum[i][j]=sum[i-1][j]+1;
            else sum[i][j]=sum[i-1][j];
            c[i][j]=sum[i][j]-sum[i][0];
            now>>=1;
        }
    }
    /*
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<K;j++)
            printf("%d ",c[i][j]);
        putchar('\n');
    }
    */
    for(int i=0; i<=N; i++)
    {
        has=getHash(c[i]);
        for(p=&hash[has]; p->next!=NULL; p=p->next)
        {
            found=1;
            for(int j=0; j<K; j++)
            {
                if(c[i][j]!=c[p->next->v][j])
                {
                    found=0;
                    break;
                }
            }
            if(found&&res<i-p->next->v)
                res=i-p->next->v;
        }
        p->next=new Node();
        p->next->v=i;
    }
    printf("%d\n",res);
    return 0;
}
