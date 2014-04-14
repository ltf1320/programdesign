
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
const int maxn=1000+10;
const int pri=997;

int abs(int a)
{
    return a>0?a:-a;
}

int res;
struct Point
{
    int x,y;
    Point(){};
    Point(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
    int getHash()
    {
        return abs((x*x+2*x+y*y+y))%pri;
    }
}pnt[maxn];

float dis(Point &a,Point &b)
{
    return sqrt(0.0+(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct Node
{
    Node* next;
    Point p;
    Node()
    {
        next=NULL;
    }
    Node(Point &a)
    {
        p=a;
        next=NULL;
    }
    void reset()
    {
        if(next!=NULL)
        {
            next->reset();
            delete next;
        }
        next=NULL;
    }
};

Node sqs[maxn];

void insert(Point &a)
{
    int h=a.getHash();
    Node *p=&sqs[h];
    if(p->next!=NULL)
        for(p=sqs[h].next;p->next!=NULL;p=p->next);
    p->next=new Node(a);
}

bool find(int i,int j)
{
    Point a,b;
    a.x=pnt[i].x+pnt[i].y-pnt[j].y;
    a.y=pnt[i].y+pnt[j].x-pnt[i].x;
    b.x=pnt[j].x+pnt[i].y-pnt[j].y;
    b.y=pnt[j].y+pnt[j].x-pnt[i].x;
    int h1=a.getHash(),h2=b.getHash();
    Node *p;
    p=&sqs[h1];
    if(p->next!=NULL)
    {
        for(;p->next!=NULL;p=p->next)
        {
            if(p->p.x==a.x&&p->p.y==a.y)
            {
                p=NULL;
                break;
            }
        }
        if(p!=NULL&&p->p.x==a.x&&p->p.y==a.y)
            p=NULL;
        if(p!=NULL) return false;
    }
    else return false;
    p=&sqs[h2];
    if(p->next!=NULL)
    {
        for(;p->next!=NULL;p=p->next)
        {
            if(p->p.x==b.x&&p->p.y==b.y)
            {
                p=NULL;
                break;
            }
        }
        if(p!=NULL&&p->p.x==b.x&&p->p.y==b.y)
            p=NULL;
        if(p!=NULL) return false;
    }
    else return false;
    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        if(!n) break;
        for(int i=0;i<maxn;i++)
            sqs[i].reset();
        res=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&pnt[i].x,&pnt[i].y);
            insert(pnt[i]);
        }
        for(int i=0;i<n;i++)   //注意这个循环，必须每个边都要算一次后除4才是对的..
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(find(i,j))
                    res++;
            }
        }
        printf("%d\n",res/4);
    }
    return 0;
}


