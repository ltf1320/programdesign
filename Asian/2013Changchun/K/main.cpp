#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
typedef long long LL;
const LL maxn=(LL)1E12;
const LL inf=(LL)0x3f3f3f3f*0x3f3f3f3f;

map<LL,pair<int,int> > mp;
int cnt=0;


LL N;

void pre()
{
    int now;
    LL nres;
    for(int i=2;i<=1000000;i++)
    {
        now=i;nres=0;
        for(int p=1;nres<=maxn;p++)
        {
            nres=(LL)i*(now-1)/(i-1);
            if(nres==30)
            {
                i++;
                i--;
            }
            cnt++;
            if(mp.count(nres))
            {
                pair<int,int> pp=mp.find(nres)->second;
                if((LL)pp.first*pp.second>(LL)i*p)
                    mp[nres]=pp;
                else if((LL)pp.first*pp.second==(LL)i*p&&pp.second>p)
                    mp[nres]=pp;
            }
            else
                mp.insert(make_pair(nres,make_pair(i,p)));
            now=now*i;
            if(now<=0)
                break;
        }
    }
}

void work()
{
    LL mx;
    LL k,r;
    if(mp.count(N))
    {
        pair<int,int> pp=mp.find(N)->second;
        k=pp.first;
        r=pp.second;
        mx=k*r;
    }
    else
    {
        mx=N;
        k=N;
        r=1;
    }
    if(mp.count(N-1))
    {
        pair<int,int> pp=mp.find(N-1)->second;
        if((LL)pp.first*pp.second<mx)
        {
            k=pp.first;
            r=pp.second;
        }
        else if((LL)pp.first*pp.second==mx&&pp.second<r)
        {
            k=pp.first;
            r=pp.second;
        }
    }
    else
    {
        if((N-1)<mx)
        {
            k=N-1;
            r=1;
        }
        else if(N-1==mx&&1<r)
        {
            k=N-1;
            r=1;
        }
    }
    printf("%I64d %I64d\n",r,k);
}

LL a[2141833][2];
int main()
{
    freopen("in.txt","r",stdin);
    pre();
    memset(a,-1,sizeof(a));
 //   cout<<cnt<<endl;
 //   cout<<mp.size()<<endl;
    while(~scanf("%I64d",&N))
        work();
    return 0;
}
