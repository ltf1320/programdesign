#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=12;
const int MOD=3997;
int N,M;
int map[maxn][maxn];

int code[maxn];
int fa[maxn];
void getcode(int st)
{
    for(int i=0; i<=M; i++)
    {
        code[i]=st&7;
        st>>=3;
    }
}

int getst()
{
    int cnt=1;
    memset(fa,-1,sizeof(fa));
    fa[0]=0;
    int st=0;
    for(int i=M; i>=0; i--)
    {
        st<<=3;
        if(fa[code[i]]==-1)
            fa[code[i]]=cnt++;
        st|=fa[code[i]];
    }
    return st;
}

struct HasNode
{
    HasNode():next(-1),num(0) {}
    HasNode(int state,int n):next(-1),st(state),num(n) {}
    int next;
    int st,num;
};

struct Has
{
    HasNode has[40000];
    int box[4000];
    int end;
    void init()
    {
        end=0;
        memset(box,-1,sizeof(box));
    }
    void update(int st,int num)
    {
        int h=st%MOD;
        for(int i=box[h]; i!=-1; i=has[i].next)
        {
            if(st==has[i].st)
            {
                has[i].num+=num;
                return;
            }
        }
        has[end].num=num;
        has[end].st=st;
        has[end].next=box[h];
        box[h]=end++;
    }
    void print()
    {
        for(int i=0;i<end;i++)
        {
            getcode(has[i].st);
            for(int j=0;j<=M;j++)
                printf("%d ",code[j]);
            printf("  %d\n",has[i].num);
        }
        puts("");
    }
};
Has hast[2];


void dpblank(int i,int j,int kn)
{
    int up,left;
    for(int k=0; k<hast[kn&1].end; k++)
    {
        getcode(hast[kn&1].has[k].st);
        up=code[j];
        left=code[M];
        if(up&&left)
        {
            if(up==left)
            {
                if(i==N-1&&j==M-1)
                {
                    code[M]=0;
                    code[j]=0;
                    hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
                }
            }
            else
            {
                for(int p=0; p<=M; p++)
                    if(code[p]==up)
                        code[p]=left;
                code[M]=0;
                code[j]=0;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
            }
        }
        if(up&&!left)
        {
            if(i!=N-1&&!map[i+1][j])
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
            if(j!=M-1&&!map[i][j+1])
            {
                code[M]=up;
                code[j]=0;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
            }
        }
        if(!up&&left)
        {
            if(j!=M-1&&!map[i][j+1])
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
            if(i!=N-1&&!map[i+1][j])
            {
                code[M]=0;
                code[j]=left;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
            }
        }
        if(!up&&!left)
        {
            if(j!=M-1&&!map[i][j+1]&&i!=N-1&&!map[i+1][j])
            {
                code[M]=code[j]=maxn-1;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
            }
        }
    }
}

void dpblock(int i,int j,int kn)
{
    for(int k=0; k<hast[kn&1].end; k++)
    {
        getcode(hast[kn&1].has[k].st);
        code[M]=code[j]=0;
        hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
    }
}


void work()
{
    int kn=0;
    memset(code,0,sizeof(code));
    hast[0].update(0,1);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
   //         printf("%d %d\n",i,j);
   //         hast[kn&1].print();
            hast[(kn&1)^1].init();
            if(map[i][j])
                dpblock(i,j,kn);
            else dpblank(i,j,kn);
            kn++;
        }
    LL res=0;
    for(int i=0; i<hast[kn&1].end; i++)
        res+=hast[kn&1].has[i].num;
    printf("%I64d\n",res);
}

void input()
{
    char ch;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            scanf("%c",&ch);
            if(ch==' '||ch=='\n')
            {
                j--;
                continue;
            }
            if(ch=='#')
                map[i][j]=1;
        }
    for(int j=1; j<M-1; j++)
        map[N][j]=1;
    N+=2;
}

void init()
{
    memset(map,0,sizeof(map));
    hast[0].init();
    hast[1].init();
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&N,&M))
    {
        if(!(N||M)) break;
        init();
        input();
        work();
    }
    return 0;
}
