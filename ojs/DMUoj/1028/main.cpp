#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

const int INF = 0x3fffffff;
struct point
{
    double x,y;
    point(){}
    point(int xx,int yy):x(xx),y(yy){}
    struct point operator / (const int k){return point(x/k,y/k);}
    struct point operator + (const point a){return point(x+a.x,y+a.y);}
};
point pt[5];
point pt2[5];
double ans;
double rope;

double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double myabs(double x)
{
    return x>0?x:-x;
}

double cross(point a,point b,point c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

double feima()
{
    double fei=0;
    double a[3];
    bool flag=false;
    for(int i=0;i<3;i++)a[i]=dist(pt2[i],pt2[(i+1)%3]);
    for(int i=0;i<3;i++)
    {
        double cosa=(a[i]*a[i]+a[(i+1)%3]*a[(i+1)%3]-a[(i+2)%3]*a[(i+2)%3])/2/a[i]/a[(i+1)%3];
        if(cosa<-1/2.0)
        {
            flag=true;
            int tem=(i+2)%3;
            if(tem)tem=tem-1;
            else tem=2;
            for(int j=0;j<3;j++)
            {
                if(j==tem)continue;
                fei+=dist(pt2[tem],pt2[j]);
            }
            break;
        }
    }
    if(!flag)
    {
        int s=myabs(cross(pt2[0],pt2[1],pt2[2]));
        fei+=sqrt((a[0]*a[0]+a[1]*a[1]+a[2]*a[2])/2+sqrt(3)*s);
    }
    return fei;
}

void worktri()
{
    for(int i=0;i<4;i++)
    {
        swap(pt2[i],pt2[3]);
        double temp=feima();
        double p2p=INF;
        for(int j=0;j<3;j++)
        {
            double dis=dist(pt2[3],pt2[j]);
            p2p=min(p2p,dis);
        }
        ans=min(ans,temp+p2p);
        swap(pt2[i],pt2[3]);
    }
}

bool cmp(point a,point b)
{
    if(a.y!=b.y)return a.y<b.y;
    else return a.x<b.x;
}

void worksqu()
{
    point bag[5];
    sort(pt2,pt2+4,cmp);
    int i, j;
    bag[0] = pt2[0];
    int len = 1;
    for(i=1;i<4;i++)
    {
        while(len>=2&&cross(bag[len-2], bag[len-1], pt2[i])<=0)len--;
        bag[len++]=pt2[i];
    }
    j = len+1;
    for(i=4-2;i>=0;i--)
    {
        while(len>=j&&cross(bag[len-2], bag[len-1], pt2[i])<=0)len--;
        bag[len++] = pt2[i];
    }
    len--;
    if(len<4)return;
    else
    {
        double temp=dist(bag[0],bag[2])+dist(bag[1],bag[3]);
        ans=min(ans,temp);
    }
}

void crope()
{
    double map[5][5];
    for(int i=0;i<5;i++)
        for(int j=0;j<=i;j++)
        {
            double tem=dist(pt[i],pt[j]);
            map[i][j]=map[j][i]=tem;
        }
    double minedge[5];
    bool visit[5];
    memset(visit,false,sizeof(visit));
    int minv=0;
    visit[minv]=true;
    rope=0.0;
    for(int i=0;i<5;i++)
        if(i!=minv) minedge[i]=map[minv][i];
    for(int i=0;i<4;i++)
    {
        double temp=INF;
        for(int j=0;j<5;j++)
            if(!visit[j]&&temp>minedge[j])
            {
                temp=minedge[j];
                minv=j;
            }
        rope+=temp;
        visit[minv]=true;
        for(int j=0;j<5;j++)
            if(!visit[j]&&minedge[j]>map[minv][j])
                minedge[j]=map[minv][j];
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("test.out","w",stdout);
    while(1)
    {
        for(int i=0;i<5;i++)
        {
            scanf("%lf%lf",&pt[i].x,&pt[i].y);
            if(pt[i].x==-1&&pt[i].y==-1)return 0;
        }
        ans=INF;
        crope();
        for(int i=0;i<5;i++)
        {
            if(i<4)continue;
            for(int j=0;j<5;j++)pt2[j]=pt[j];
            swap(pt2[i],pt2[4]);
            worktri();
            worksqu();
        }
        printf("%.2f\n",rope-ans);
    }
    return 0;
}
