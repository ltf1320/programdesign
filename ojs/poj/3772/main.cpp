#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=20;
int N;

int goNext(int st)
{
    int tmp=7;
    tmp=tmp&st;
    tmp<<=1;
    tmp&=7;
    for(int i=0;i<3;i++)
        st&=(-1)^(1<<(i));
    st^=tmp;
    return st;
}

int out1(int st)
{
    if(st&(1<<(3)))
        st^=(1<<(3))+(1<<(4));
    else st|=(1<<(3));
    return st;
}



bool used[maxn];
int map[maxn][maxn];
int sum[maxn];
int res;
void dfs(int n,int score,int state)
{
    int nxt,sc;
    if(n==N||(state>>3)==3)
    {
        if(score>res) res=score;
        return;
    }
    int kk=0;
    for(int i=0;i<N;i++)
        if(!used[i]) kk+=sum[i];
    if(kk+score<res) return;
    for(int i=0;i<N;i++)
    {
        if(!used[i])
        {
            used[i]=1;
            switch(map[i][n])
            {
                case 0:
                    nxt=out1(state);
                    dfs(n+1,score,nxt);
                    break;
                case 1:
                    sc=state&(1<<2)?1:0;
                    nxt=out1(state);
                    nxt=goNext(state);
                    dfs(n+1,score+sc,nxt);
                    break;
                case 2:
                    sc=state&(1<<2)?1:0;
                    nxt=goNext(state);
                    nxt|=1;
                    dfs(n+1,score+sc,nxt);
                    break;
                case 3:
                    sc=1;
                    nxt=state;
                    for(int i=0;i<3;i++)
                    {
                        if(state&(1<<i))
                            sc++;
                        nxt&=((-1)^(1<<i));
                    }
                    dfs(n+1,score+sc,state);
                    break;
            }
            used[i]=0;
        }
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&N)&&N)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                scanf("%d",&map[i][j]);
                if(map[i][j]!=0)
                    sum[i]+=1;
                if(map[i][j]==3)
                    sum[i]+=3;
            }
        res=0;
        dfs(0,0,0);
        printf("%d\n",res);
    }
    return 0;
}
