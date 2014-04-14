#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1000+10;
const int maxt=1000+10;
bool usedt[maxn];
int maxtn;
char skip()
{
    char ch;
    while((ch=getchar())==' ');
    return ch;
}

struct Time
{
    int h,m,s;
    Time(int hh,int mm,int ss):h(hh),m(mm),s(ss) {}
    Time() {}
    void readTime()
    {
        scanf("%d",&h);
        skip();
        scanf("%d",&m);
        skip();
        scanf("%d",&s);
    }
    int operator-(Time &a)
    {
        return (h-a.h)*60+m-a.m;
    }
};
Time startTime,endTime;

struct TEAM
{
    bool ti[maxt];
    int ac;
    int fs[maxt];
    int fssum;
    int id;
    vector<Time> WATime[maxt];
    Time acTime[maxt];
    void reset(int i)
    {
        id=i;
        memset(ti,0,sizeof(ti));
        ac=0;
        memset(fs,0,sizeof(fs));
        fssum=0;
        for(int i=0;i<maxt;i++)
            WATime[i].clear();
    }
    void AC(int t,Time now)
    {
        if(now-endTime>0) return;
        if(ti[t])
        {
            if(now-acTime[t]<0)
            {
                fssum-=acTime[t]-startTime;
                fssum-=fs[t];
                fs[t]=0;
                ac--;
            }
            else return;
        }
        acTime[t]=now;
        for(size_t i=0; i<WATime[t].size(); i++)
        {
            if(now-WATime[t][i]>0)
                fs[t]+=20;
        }
        fssum+=fs[t];
        fssum+=now-startTime;
        ti[t]=1;
        ac++;
    }
    void WA(int t,Time now)
    {
        if(now-endTime>0) return;
        WATime[t].push_back(now);
        if(ti[t])
        {
            if(now-acTime[t]<0)
            {
                fs[t]+=20;
                fssum+=20;
            }
        }
    }
    bool operator<(const TEAM &a)const
    {
        if(ac==a.ac)
        {
            if(fssum==a.fssum)
                return id<a.id;
            return fssum<a.fssum;
        }
        return ac>a.ac;
    }
};
TEAM team[maxn];

void work()
{
    startTime.readTime();
    endTime.readTime();
    char tmp[maxn];
    int tn;
    Time now;
    char Ti;
    while(true)
    {
        scanf("%s",tmp);
        if(tmp[0]=='#') return;
        sscanf(tmp+4,"%d",&tn);
        usedt[tn]=1;
        maxtn=max(tn,maxtn);
        now.readTime();
        Ti=skip();
        scanf("%s",tmp);
        if(tmp[0]=='Y')
            team[tn].AC(Ti-'A',now);
        else team[tn].WA(Ti-'A',now);
    }
}
int cas;
void print()
{
    printf("Case %d:\n",cas);
    sort(team,team+maxtn+1);
    for(int i=0;i<=maxtn;i++)
        if(usedt[team[i].id])
            printf("%d team%d %d %d\n",i+1,team[i].id,team[i].ac,team[i].fssum);
}

void init()
{
    memset(usedt,0,sizeof(usedt));
    for(int i=0;i<maxt;i++)
        team[i].reset(i);
    maxtn=0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        init();
        work();
        print();
    }
    return 0;
}
