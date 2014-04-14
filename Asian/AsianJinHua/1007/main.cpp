#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=20+10;
bool cl[40+10][20+5];
double incr[110];
int N,K,M;
int acre;
struct Course
{
    int s,cr,code;
    bool operator<(const Course &a) const
    {
        if(s<60||a.s<60)
            return s>a.s;
        return cr*incr[s]<a.cr*incr[a.s];
    }
};
Course crs[maxn];

double getP(int n)
{
    return 4.0-3.0*(n-100.0)*(n-100.0)/1600.0;
}

void input()
{
    acre=0;
    for(int i=0;i<M;i++)
    {
        scanf("%d",&crs[i].cr);
        acre+=crs[i].cr;
        crs[i].code=i;
    }
    for(int i=0;i<M;i++)
        scanf("%d",&crs[i].s);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>cl[i][j];
}

double work()
{
    priority_queue<Course> que;
    queue<Course> tmq;
    Course tmp;
    for(int i=0;i<M;i++)
        que.push(crs[i]);
    for(int i=0;i<N;i++)
        for(int j=0;j<K;j++)
        {
            tmp=que.top();
            que.pop();
            if(cl[i][tmp.code])
            {
                tmp.s++;
                que.push(tmp);
            }
            else
            {
                tmq.push(tmp);
                j--;
                continue;
            }
            while(!tmq.empty())
            {
                que.push(tmq.front());
                tmq.pop();
            }
        }
    double res=0;
    if(que.top().s<60) return 0;
    while(!que.empty())
    {
        res+=getP(que.top().s)*que.top().cr;
        que.pop();
    }
    return res/acre;
}

int main()
{
    freopen("in.txt","r",stdin);
    for(int i=0;i<100;i++)
        incr[i]=getP(i+1)-getP(i);
    incr[100]=0;
    while(~scanf("%d%d%d",&N,&K,&M))
    {
        if(N==0&&K==0&&M==0) break;
        input();
        printf("%.6f\n",work());
    }
    return 0;
}
