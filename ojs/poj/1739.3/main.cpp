#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=12;
const int MOD=97;
int N,M;
int map[maxn][maxn];

int code[maxn];
void getcode(int st)
{
    for(int i=0; i<=M; i++)
    {
        code[i]=st&3;
        st>>=2;
    }
}

int getst()
{
    int st=0;
    for(int i=M; i>=0; i--)
    {
        st<<=2;
        st|=code[i];
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
    HasNode has[5000];
    int box[100];
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
        for(int i=0; i<end; i++)
        {
            getcode(has[i].st);
            for(int j=0; j<=M; j++)
                printf("%d ",code[j]);
            printf("  %d\n",has[i].num);
        }
        puts("");
    }
};
Has hast[2];

int findRMatch(int start,int now)
{
    int cnt=0;
    for(int i=start+1; i<M; i++)
    {
        if(!code[i]) continue;
        if(code[i]==now)    cnt++;
        else
        {
            if(cnt==0) return i;
            cnt--;
        }
    }
    return -100000;
}

int findLMatch(int start,int now)
{
    int cnt=0;
    for(int i=start-1; i>=0; i--)
    {
        if(!code[i]) continue;
        if(code[i]==now)    cnt++;
        else
        {
            if(cnt==0) return i;
            cnt--;
        }
    }
    return -100000;
}

void dpblank(int i,int j,int kn)
{
    int up,left;
    for(int k=0; k<hast[kn&1].end; k++)
    {
        getcode(hast[kn&1].has[k].st);
        up=code[j];
        left=code[M];
        if(!up&&!left)
        {
            if(j!=M-1&&!map[i][j+1]&&i!=N-1&&!map[i+1][j])
            {
                code[M]=2;
                code[j]=1;
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
        if(up&&left)
        {
            int match;
            if(up==1&&left==1)
            {
                match=findRMatch(j,left);
                code[match]=1;
                code[M]=0;
                code[j]=0;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
            }
            if(up==1&&left==2)
            {
                code[M]=0;
                code[j]=0;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
            }
            if(up==2&&left==1)
            {
                if(i==N-1&&j==M-1)
                {
                    code[j]=0;
                    code[M]=0;
                    hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
                }
            }
            if(up==2&&left==2)
            {
                match=findLMatch(j,left);
                code[match]=2;
                code[j]=0;
                code[M]=0;
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
  //          printf("%d %d\n",i,j);
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
 //  freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&N,&M))
    {
        if(!(N||M)) break;
        init();
        input();
        work();
    }
    return 0;
}
