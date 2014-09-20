#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
using namespace std;


int mp[6];
void initMp()
{
    mp[0]=0;
    mp[1]=1;
    mp[2]=2;
    mp[3]=3;
    mp[4]=4;
    mp[5]=5;
}
struct Dice
{
    int a[6];
    int dep;
    int getHash()
    {
        int res=0;
        int now=1;
        for(int i=0;i<6;i++)
        {
            res+=now*a[i];
            res=res*6;
        }
        return res;
    }
    int read()
    {
        /*
        0 1 2 3 4 5
        s x z q y h
        0 1 2 4 3 5
        */
        return scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
    }
    bool eq(const Dice &d)
    {
        for(int i=0;i<6;i++)
            if(a[i]!=d.a[i])
                return false;
        return true;
    }
    Dice doleft()
    {
        Dice res;
        memcpy(res.a,a,sizeof(a));
        res.a[mp[1]]=a[mp[2]];
        res.a[mp[2]]=a[mp[0]];
        res.a[mp[0]]=a[mp[3]];
        res.a[mp[3]]=a[mp[1]];
        res.dep=dep+1;
        return res;
    }
    Dice doright()
    {
        Dice res;
        memcpy(res.a,a,sizeof(a));
        res.a[mp[1]]=a[mp[3]];
        res.a[mp[2]]=a[mp[1]];
        res.a[mp[0]]=a[mp[2]];
        res.a[mp[3]]=a[mp[0]];
        res.dep=dep+1;
        return res;
    }
    Dice dofront()
    {
        Dice res;
        memcpy(res.a,a,sizeof(a));
        res.a[mp[1]]=a[mp[4]];
        res.a[mp[4]]=a[mp[0]];
        res.a[mp[0]]=a[mp[5]];
        res.a[mp[5]]=a[mp[1]];
        res.dep=dep+1;
        return res;
    }
    Dice doback()
    {
        Dice res;
        memcpy(res.a,a,sizeof(a));
        res.a[mp[1]]=a[mp[5]];
        res.a[mp[5]]=a[mp[0]];
        res.a[mp[0]]=a[mp[4]];
        res.a[mp[4]]=a[mp[1]];
        res.dep=dep+1;
        return res;
    }
};
Dice a,b;
queue<Dice> que;
set<int> has;
int bfs()
{
    has.clear();
    while(!que.empty()) que.pop();
    b.dep=0;
    que.push(b);
    while(!que.empty())
    {
        Dice top=que.front();
        que.pop();
        if(has.find(top.getHash())!=has.end())
            continue;
        has.insert(top.getHash());
        if(top.dep>=5)
            return -1;
        if(top.eq(a))
            return top.dep;
        que.push(top.doback());
        que.push(top.dofront());
        que.push(top.doleft());
        que.push(top.doright());
    }
    return -1;
}

int main()
{
    freopen("in.txt","r",stdin);
    initMp();
    while(~a.read())
    {
        b.read();
        printf("%d\n",bfs());
    }
    return 0;
}
