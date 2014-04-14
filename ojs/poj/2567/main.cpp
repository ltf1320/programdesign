#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=50+10;
int N;
struct EDGE
{
    int to,next;
};
EDGE edge[2*maxn];
int box[maxn];
int ent;
bool del[maxn];
int du[maxn];
int ans[maxn];
int ansn;
void _add(int f,int t)
{
    edge[ent].to=t;
    edge[ent].next=box[f];
    box[f]=ent++;
}

void add(int f,int t)
{
    _add(f,t);
    _add(t,f);
    du[f]++;
    du[t]++;
}

void init()
{
    N=1;
    ent=0;
    ansn=0;
    memset(box,-1,sizeof(box));
    memset(du,0,sizeof(du));
    memset(del,0,sizeof(del));
}

void readTree(int now)
{
    int nxt;
    char ch;
    while(true)
    {
        ch=getchar();
        while(ch==' ') ch=getchar();
        if(ch=='(')
        {
            scanf("%d",&nxt);
            N++;
            add(now,nxt);
            readTree(nxt);
        }
        else if(ch==')')
            break;
    }
}

void work()
{
    for(int k=0; k<N-1; k++)
    {
        for(int i=1; i<=N; i++)
        {
            if(!del[i]&&du[i]==1)
            {
                del[i]=1;
                for(int j=box[i];j!=-1;j=edge[j].next)
                {
                    if(!del[edge[j].to])
                    {
                        ans[ansn++]=edge[j].to;
                        du[edge[j].to]--;
                        break;
                    }
                }
                break;
            }
        }
    }
    for(int i=0;i<N-2;i++)
        printf("%d ",ans[i]);
    if(N>1)
        printf("%d\n",ans[N-2]);
    else printf("\n"); //!!
}

int main()
{
    freopen("in.txt","r",stdin);
    char ch;
    char tmp[maxn];
    int root;
    while(~scanf("%c%d",&ch,&root))
    {
        init();
        readTree(root);
        gets(tmp);
        work();
    }
    return 0;
}
