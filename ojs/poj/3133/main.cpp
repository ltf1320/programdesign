#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long LL;
const int maxn=15;
const int MOD=9997;
const int inf=0x3f3f3f3f;
int N,M;
int map[maxn][maxn];

int code[maxn];

bool judgeCode()
{
    int n2=0,n3=0;
    for(int i=0; i<=M; i++)
    {
        switch(code[i])
        {
        case 1:
            n2++;
            break;
        case 2:
            n2--;
            break;
        case 5:
            n3++;
            break;
        case 6:
            n3--;
            break;
        }
    }
    if(n2||n3) return false;
    return true;
}
void getcode(LL st)
{
    for(int i=0; i<=M+2; i++)
    {
        code[i]=st&7;
        st>>=3;
    }
}

LL getst()
{
    LL st=0;
    for(int i=M+2; i>=0; i--)
    {
        st<<=3;
        st|=code[i];
    }
    return st;
}



struct HasNode
{
    HasNode():next(-1),num(0) {}
    HasNode(LL state,int n):next(-1),st(state),num(n) {}
    int next;
    LL st;
    int num;
};

struct Has
{
    HasNode has[40000];
    int box[10000];
    int end;
    void init()
    {
        end=0;
        memset(box,-1,sizeof(box));
    }
    void update(LL st,int num)
    {
        int h=st%MOD;
        for(int i=box[h]; i!=-1; i=has[i].next)
        {
            if(st==has[i].st)
            {
                has[i].num=min(has[i].num,num);
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
            for(int j=0; j<=M+2; j++)
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
    int ww=now&4;
    for(int i=start+1; i<M; i++)
    {
        if(!code[i]) continue;
        if(code[i]==now)    cnt++;
        else if((code[i]&4)==ww&&code[i]!=7&&code[i]!=3) ///
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
    int ww=now&4;
    for(int i=start-1; i>=0; i--)
    {
        if(!code[i]) continue;
        if(code[i]==now) cnt++;
        else if((code[i]&4)==ww&&code[i]!=7&&code[i]!=3)
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
        up=code[j-1];
        left=code[M];
        if(!up&&!left)
        {
            hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num);
            if(map[i][j+1]!=1&&map[i+1][j]!=1)
            {
                code[M]=2;
                code[j-1]=1;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
                code[M]=6;
                code[j-1]=5;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
        }
        if(up&&!left)
        {
            if(map[i+1][j]!=1)
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            if(map[i][j+1]!=1)
            {
                code[M]=up;
                code[j-1]=0;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
        }
        if(!up&&left)
        {
            if(map[i][j+1]!=1)
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            if(map[i+1][j]!=1)
            {
                code[M]=0;
                code[j-1]=left;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
        }
        if(up&&left)
        {
            int match,ww;
            if(up>>2!=left>>2) continue;
            ww=up&(1<<2);
            if(up==ww+1&&left==ww+1)
            {
                match=findRMatch(j-1,left);
                code[match]=ww+1;
                code[M]=0;
                code[j-1]=0;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
            if(up==ww+1&&left==ww+2)
            {
                code[M]=0;
                code[j-1]=0;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
            if(up==ww+2&&left==ww+1)
            {
                if(i==N&&j==M)
                {
                    code[j-1]=0;
                    code[M]=0;
                    hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
                }
            }
            if(up==ww+2&&left==ww+2)
            {
                match=findLMatch(j-1,left);
                code[match]=ww+2;
                code[j-1]=0;
                code[M]=0;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
            if(up==ww+3&&left==ww+3)
            {
                code[j-1]=0;
                code[M]=0;
                code[M+1+(ww!=0)]=3;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
            ///
            if(up==ww+3&&left!=ww+3)
            {
                if(left==ww+1)
                    match=findRMatch(j-1,left);
                else match=findLMatch(j-1,left);
                code[match]=ww+3;
                code[j-1]=0;///
                code[M]=0;///
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
            if(left==ww+3&&up!=ww+3)
            {
                if(up==ww+1)
                    match=findRMatch(j-1,up);
                else match=findLMatch(j-1,up);
                code[match]=ww+3;
                code[M]=0;
                code[j-1]=0;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
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

void dp23(int i,int j,int kn)
{
    int match;
    int ww;
    int up,left;
    if(map[i][j]==2) ww=0;
    else ww=1<<2;
    for(int k=0; k<hast[kn&1].end; k++)
    {
        getcode(hast[kn&1].has[k].st);
        up=code[j-1];
        left=code[M];
        if(up&&(up&4)!=ww)continue;
        if(left&&(left&4)!=ww)continue;
        if(up&&(!left))
        {
            if(up!=3+ww)
            {
                if(up==1+ww)
                    match=findRMatch(j-1,up);
                else match=findLMatch(j-1,up);
                code[match]=3+ww;
                code[j-1]=0;
                code[M+1+(ww!=0)]++;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
            else
            {
                code[j-1]=0;
                code[M+1+(ww!=0)]=3;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
        }
        if(left&&!up)
        {
            if(left!=3+ww)//
            {
                if(left==1+ww)
                    match=findRMatch(j-1,left);
                else match=findLMatch(j-1,left);
                code[M]=0;
                code[match]=3+ww;
                code[M+1+(ww!=0)]++;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
            else
            {
                code[M]=0;
                code[M+1+(ww!=0)]=3;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
        }
        if(!left&&!up)
        {
            code[M+1+(ww!=0)]++;
            if(map[i+1][j]!=1)
            {
                code[j-1]=3+ww;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
            if(map[i][j+1]!=1)
            {
                code[j-1]=0;
                code[M]=3+ww;
                hast[(kn&1)^1].update(getst(),hast[kn&1].has[k].num+1);
            }
        }
    }
}

void work()
{
    int kn=0;
    memset(code,0,sizeof(code));
    hast[0].update(0,0);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
        {
//            printf("%d %d\n",i,j);
//            hast[kn&1].print();
            hast[(kn&1)^1].init();
            if(map[i][j]==1)
                dpblock(i,j,kn);
            else if(map[i][j])
                dp23(i,j,kn);
            else dpblank(i,j,kn);
            kn++;
        }
    int res=inf;
    for(int i=0; i<hast[kn&1].end; i++)
    {
        getcode(hast[kn&1].has[i].st);
        if(code[M+1]==3&&code[M+2]==3)
            res=min(res,hast[kn&1].has[i].num);
    }
    if(res==inf) res=2;
    printf("%d\n",res-2);
}

void input()
{
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
        {
            scanf("%d",&map[i][j]);
        }
    for(int i=0; i<=N+1; i++)
        map[i][0]=map[i][M+1]=1;
    for(int i=0; i<=M+1; i++)
        map[0][i]=map[N+1][i]=1;
}

void init()
{
    hast[0].init();
    hast[1].init();
}
int main()
{
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&N,&M))
    {
        if(!(N||M)) break;
        init();
        input();
        work();
    }
    return 0;
}
