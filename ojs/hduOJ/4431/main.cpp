#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int maxn=30;
int mj[10][maxn];
int mjn[10];
//0 for Man,1 for Sou,2 for Pin,3 for cha
int getType(char ch)
{
    switch(ch)
    {
    case 'm':
        return 0;
    case 's':
        return 1;
    case 'p':
        return 2;
    case 'c':
        return 3;
    }
    return -1000;
}

char getType(int ch)
{
    switch(ch)
    {
    case 0:
        return 'm';
    case 1:
        return 's';
    case 2:
        return 'p';
    case 3:
        return 'c';
    }
    return 0;
}


struct MJ
{
    int type,num;
    MJ(int t,int n):type(t),num(n) {};
    MJ() {}
    bool operator<(const MJ &a) const
    {
        if(type==a.type)
            return num<a.num;
        else return type<a.type;
    }
};
set<MJ> res;

bool judgeh(int type,int num)
{
    int tmp[maxn];
    for(int i=1; i<=7; i++)
    {
        if(mj[3][i]%3!=0) return 0;
    }
    for(int i=0; i<3; i++)
    {
        if(mjn[i]%3!=0)
            return 0;
        for(int j=1; j<=12; j++)
            tmp[j]=mj[i][j];
        for(int j=1; j<=9; j++)
        {
            if(tmp[j]>=3)
                tmp[j]-=3;
            if(tmp[j+1]>=tmp[j]&&tmp[j+2]>=tmp[j])
            {
                tmp[j+1]-=tmp[j];
                tmp[j+2]-=tmp[j];
                tmp[j]=0;
            }
            if(tmp[j]) return 0;
        }
    }
    return 1;
}


MJ judge7d()
{
    bool f=0;
    MJ q;
    for(int i=0; i<3; i++)
        for(int j=1; j<=9; j++)
        {
            if(mj[i][j]>2) return MJ(-1,-1);
            if(mj[i][j]==1)
            {
                if(f) return MJ(-1,-1);
                f=1;
                q=MJ(i,j);
            }
        }
    for(int j=1; j<=7; j++)
    {
        if(mj[3][j]>2) return MJ(-1,-1);
        if(mj[3][j]==1)
        {
            if(f) return MJ(-1,-1);
            f=1;
            q=MJ(3,j);
        }
    }
    if(f) return q;
    else return MJ(-1,-1);
}


MJ judge19()
{
    bool f=0,o=0;
    MJ q;
    for(int i=0; i<3; i++)
        for(int j=1; j<10; j+=8)
        {
            if(mj[i][j]>2)
                return MJ(-1,-1);
            if(mj[i][j]==2) //!
            {
                if(o) return MJ(-1,-1);
                else o=1;
            }
            else if(mj[i][j]==0)
            {
                if(f)
                    return MJ(-1,-1);
                else
                {
                    f=1;
                    q=MJ(i,j);
                }
            }
        }
    if(!f)
    {
        for(int i=1;i<=7;i++)
        {
            if(mj[3][i]!=1)
            {
                f=1;
                break;
            }
        }
        if(!f)
        {
            for(int i=1;i<=7;i++)
            {
                res.insert(MJ(3,i));
            }
            for(int i=0; i<3; i++)
                for(int j=1; j<10; j+=8)
                {
                    res.insert(MJ(i,j));
                }
            return MJ(-1,-1);
        }
        f=0;
    }
    for(int i=1; i<=7; i++)
    {
        if(mj[3][i]==0)
        {
            if(f)
                return MJ(-1,-1);
            else
            {
                f=1;
                q=MJ(3,i);
            }
        }
        else if(mj[3][i]==2)
        {
            if(o)
                return MJ(-1,-1);
            else o=1;
        }
        else if(mj[3][i]>2) return MJ(-1,-1);
    }
    if(o&&f) return q;
    else return MJ(-1,-1);
}

void work()
{
    MJ r;
    bool fd;
    r=judge19();
    if(r.num!=-1&&mj[r.type][r.num]!=4)
        res.insert(r);
    r=judge7d();
    if(r.num!=-1&&mj[r.type][r.num]!=4)
        res.insert(r);
    int end1,end2;
    for(int i=0; i<4; i++)
    {
        if(i==3) end1=7;
        else end1=9;
        for(int j=1; j<=end1; j++)
        {
            if(mj[i][j]==4) continue;  //!!!!!
            fd=0;
            mj[i][j]++;
            mjn[i]++;
            for(int k=0; k<4; k++)
            {
                if(k==3) end2=7;
                else end2=9;
                for(int p=1; p<=end2; p++)
                {
                    if(mj[k][p]>=2)
                    {
                        mj[k][p]-=2;
                        mjn[k]-=2;
                        if(judgeh(i,j))
                        {
                            res.insert(MJ(i,j));
                            fd=1;
                            mjn[k]+=2;
                            mj[k][p]+=2;
                            break;
                        }
                        mjn[k]+=2;
                        mj[k][p]+=2;
                    }
                }
                if(fd) break;
            }
            mjn[i]--;
            mj[i][j]--;
        }
    }
}

void input()
{
    int k,t;
    char ch;
    for(int i=0; i<13; i++)
    {
        scanf("%d%c",&k,&ch);
        t=getType(ch);
        mj[t][k]++;
        mjn[t]++;
    }
}

void init()
{
    memset(mj,0,sizeof(mj));
    memset(mjn,0,sizeof(mjn));
    res.clear();
}

void print()
{
    if(res.size()==0)
        printf("Nooten\n");
    else
    {
        printf("%d",(int)res.size());
    //    cout<<res.size();
        for(set<MJ>::iterator iter=res.begin(); iter!=res.end(); iter++)
            printf(" %d%c",iter->num,getType(iter->type));
        putchar('\n');
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        input();
        work();
        print();
    }
    return 0;
}
