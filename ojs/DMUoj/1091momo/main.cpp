#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=11111;
struct team
{
    int sum;
    int cnt;
    int name;
    bool yes[13];
    void init()
    {
        sum=0;
        cnt=0;
        memset(yes,0,sizeof(yes));
    }
};
team tt[maxn];
int is[maxn];
bool cmp(const team &a,const team &b)
{
    if(a.cnt!=b.cnt)
    {
        return a.cnt>b.cnt;
    }
    else
    {
        if(a.sum!=b.sum) return a.sum<b.sum;
        return a.name<b.name;
    }
}
int time_work(char *ch)
{
    int res=0;
    int tmp=0;
    for(int i=0; i<2; i++)
    {
        tmp+=ch[i]-'0';
        if(i==0) tmp*=10;
    }
    res+=tmp*60;
    tmp=0;
    for(int i=3; i<5; i++)
    {
        tmp+=ch[i]-'0';
        if(i==3) tmp*=10;
    }
    res+=tmp;
    return res;
}
int main()
{
    freopen("in.txt","r",stdin);
 //   freopen("test.out","w",stdout);
    int t;
    char ch[maxn];
    char time_start[maxn];
    char time_end[maxn];
    scanf("%d",&t);
    int cas=0;
    int num;
    while(t--)
    {
        printf("Case %d:\n",++cas);
        scanf("%s%s",time_start,time_end);
        int start=time_work(time_start);
        int end=time_work(time_end);
        int id;
        id=0;
        int now;
        memset(is,-1,sizeof(is));
        while(scanf("%s",ch),strcmp(ch,"#"))
        {
            int len=strlen(ch);
            num=0;
            int a,b;
            for(int i=4; i<len; i++)
            {
                num+=ch[i]-'0';
            }
            if(is[num]==-1)
            {
                is[num]=id;
                now=id;
                tt[id++].init();
                tt[now].name=num;
            }
            else
            {
                now=is[num];
            }
            scanf("%s",ch);
            len=strlen(ch);
            a=time_work(ch);
            scanf("%s",ch);
            b=ch[0]-'A';
            scanf("%s",ch);
            if(!strcmp(ch,"YES"))
            {
                if(!tt[now].yes[b])
                {

                    if(a<=end&&a>=start)
                    {
                        tt[now].yes[b]=true;
                        tt[now].sum+=a-start;
                        tt[now].cnt++;
                    }
                }
            }
            else
            {
                if(a<=end)
                {
                    if(tt[now].cnt)
                    {
                        tt[now].sum+=20;
                    }
                }
            }
        }
        sort(tt,tt+id,cmp);
        for(int i=0; i<id; i++)
        {
            printf("%d team%d %d %d\n",i+1,tt[i].name,tt[i].cnt,tt[i].sum);
        }
    }
    return 0;
}
