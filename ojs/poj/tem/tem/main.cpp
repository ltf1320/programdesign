#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 200
using namespace std;
int a , b , c ;
bool ma[maxn][maxn];
int op[maxn][maxn];
struct maa
{
    int x , y;
}pre[maxn][maxn];
struct pot
{
    int a , b , step ;
};
queue <pot> p;
pot bfs( pot top )
{
    p.push(top);
    while(!p.empty())
    {
        pot t=p.front() , tem ;
        if(!ma[a][t.b])
        {
            tem.a=a,tem.b=t.b,tem.step=t.step+1;
            op[tem.a][tem.b]=11;
            pre[tem.a][tem.b].x=t.a;
            pre[tem.a][tem.b].y=t.b;
            ma[tem.a][tem.b]=1;
            p.push(tem);
            if(tem.a==c||tem.b==c) return tem;
        }
        if(!ma[t.a][b])
        {
            tem.b=b,tem.a=t.a,tem.step=t.step+1;
            op[tem.a][tem.b]=12;
            pre[tem.a][tem.b].x=t.a;
            pre[tem.a][tem.b].y=t.b;
            ma[tem.a][tem.b]=1;
            p.push(tem);
            if(tem.a==c||tem.b==c) return tem;
        }
        if(!ma[0][t.b])
        {
            tem.b=t.b,tem.a=0,tem.step=t.step+1;
            op[tem.a][tem.b]=21;
            pre[tem.a][tem.b].x=t.a;
            pre[tem.a][tem.b].y=t.b;
            ma[tem.a][tem.b]=1;
            p.push(tem);
            if(tem.a==c||tem.b==c) return tem;
        }
        if(!ma[t.a][0])
        {
            tem.b=0,tem.a=t.a,tem.step=t.step+1;
            op[tem.a][tem.b]=22;
            pre[tem.a][tem.b].x=t.a;
            pre[tem.a][tem.b].y=t.b;
            ma[tem.a][tem.b]=1;
            p.push(tem);
            if(tem.a==c||tem.b==c) return tem;
        }
        if(t.a+t.b>b)
        {
            if(!ma[t.a+t.b-b][b])
            {
                tem.a=t.a+t.b-b,tem.b=b,tem.step=t.step+1;
                op[tem.a][tem.b]=31;
                pre[tem.a][tem.b].x=t.a;
                pre[tem.a][tem.b].y=t.b;
                ma[tem.a][tem.b]=1;
                p.push(tem);
                if(tem.a==c||tem.b==c) return tem;
            }
        }
        if(t.a+t.b<=b)
        {
            if(!ma[0][t.a+t.b])
            {
                tem.a=0,tem.b=t.a+t.b,tem.step=t.step+1;
                op[tem.a][tem.b]=31;
                pre[tem.a][tem.b].x=t.a;
                pre[tem.a][tem.b].y=t.b;
                ma[tem.a][tem.b]=1;
                p.push(tem);
                if(tem.a==c||tem.b==c) return tem;
            }
        }
        if(t.a+t.b>a)
        {
            if(!ma[a][t.a+t.b-a])
            {
                tem.a=a,tem.b=t.a+t.b-a,tem.step=t.step+1;
                op[tem.a][tem.b]=32;
                pre[tem.a][tem.b].x=t.a;
                pre[tem.a][tem.b].y=t.b;
                ma[tem.a][tem.b]=1;
                p.push(tem);
                if(tem.a==c||tem.b==c) return tem;
            }
        }
        if(t.a+t.b<=a)
        {
            if(!ma[t.a+t.b][0])
            {
                tem.a=t.a+t.b,tem.b=0,tem.step=t.step+1;
                op[tem.a][tem.b]=32;
                pre[tem.a][tem.b].x=t.a;
                pre[tem.a][tem.b].y=t.b;
                ma[tem.a][tem.b]=1;
                p.push(tem);
                if(tem.a==c||tem.b==c) return tem;
            }
        }
        p.pop();
    }
    pot tem ;
    return tem;
}
void trace( int step ,int x , int y)
{
    if(step==0)
        return;
    trace(step-1,pre[x][y].x,pre[x][y].y);
    int k = op[x][y];
    if(k==11) printf("fill A\n");
    else if(k==12)  printf("fill B\n");
    else if(k==21)  printf("empty A\n");
    else if(k==22)  printf("empty B\n");
    else if(k==31)  printf("pour A B\n");
    else if(k==32)  printf("pour B A\n");
}
void pnt( pot ans )
{
    trace(ans.step,ans.a,ans.b);
    printf("success\n");
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        while(!p.empty()) p.pop();
        pot first;
        first.a=0,first.b=0,first.step=0;
        memset(ma,0,sizeof(ma));
        memset(op,0,sizeof(op));
        memset(pre,0,sizeof(pre));
        pot ans=bfs(first);
        if(p.empty()) printf("impossible\n");
        else
            pnt(ans);
    }
    return 0;
}
