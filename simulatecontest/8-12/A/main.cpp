#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=10000+100;

int N,M;

struct Node
{
    int num;
    Node *pre,*next;
    Node():pre(0),next(0) {}
    Node(Node* p,int n):num(n),pre(p),next(0) {}
};
Node *pt;

bool lazy;
int ln;
int k1,k2;

void add(int n)
{
    if(lazy)
        ln+=n;
    else
    {
        lazy=1;
        ln=n;
    }
}

void reverse()
{
    Node *start=pt->pre;
    Node *pre=pt;
    Node *now=pt->next;
    Node *next;
    pt->pre=pt->next;
    for(int i=0; i<k1-2; i++)
    {
        next=now->next;
        now->next=pre;
        now->pre=next;
        pre=now;
        now=next;
    }
    next=now->next;
    now->next=pre;
    now->pre=start;
    start->next=now;
    pt->next=next;
    next->pre=pt;
    pt=now;
}

void update()
{
    if(lazy)
    {
        Node *now=pt;
        for(int i=0; i<k2; i++)
        {
            now->num+=ln;
            now=now->next;
        }
        lazy=0;
    }
}

void insert(int n)
{
    update();
    N++;
    if(!pt)
    {
        pt=new Node();
        pt->next=pt;
        pt->pre=pt;
        pt->num=n;
        return ;
    }
    Node* tmp=pt->next;
    pt->next=new Node(pt,n);
    pt->next->next=tmp;
    tmp->pre=pt->next;
}

void del()
{
    update();
    if(!pt) return;
    if(N==1)
    {
        delete pt;
        pt=0;
        N=0;
        return;
    }
    N--;
    Node *pre=pt->pre;
    Node *tmp=pt;
    pt=pt->next;
    pre->next=pt;
    pt->pre=pre;
    delete tmp;
}

void move(int k)
{
    update();
    if(k==1)
        pt=pt->pre;
    else pt=pt->next;
}

void query()
{
    if(lazy)
        printf("%d\n",pt->num+ln);
    else printf("%d\n",pt->num);
}

void init()
{
    lazy=0;
    if(!pt) return;
    Node* now=pt->next;
    Node *next=pt->next->next;
    for(int i=0;i<N-1;i++)
    {
        delete now;
        now=next;
        next=now->next;
    }
    delete pt;
    pt=0;
}

void input()
{
    pt=new Node();
    Node *now=pt;
    scanf("%d",&pt->num);
    int tmp;
    for(int i=0;i<N-1;i++)
    {
        scanf("%d",&tmp);
        now->next=new Node(now,tmp);
        now=now->next;
    }
    now->next=pt;
    pt->pre=now;
}

void print()
{
    Node *now=pt;
    for(int i=0;i<=N;i++)
    {
        printf("%d ",now->num);
        now=now->next;
    }
    now=pt;
    printf("     ");
    for(int i=0;i<=N;i++)
    {
        printf("%d ",now->num);
        now=now->pre;
    }
    puts("");
}

void work()
{
    char tmp[20];
    int tt;
    for(int i=0;i<M;i++)
    {
        scanf("%s",tmp);
        switch(tmp[0])
        {
            case 'a':
                scanf("%d",&tt);
                add(tt);
                break;
            case 'r':
                reverse();
                break;
            case 'i':
                scanf("%d",&tt);
                insert(tt);
                break;
            case 'd':
                del();
                break;
            case 'm':
                scanf("%d",&tt);
                move(tt);
                break;
            case 'q':
                query();
                break;
        }
 //       print();
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int cas=0;
    while(~scanf("%d%d%d%d",&N,&M,&k1,&k2))
    {
        if(N==0&&M==0&&k1==0&&k2==0)
            break;
        cas++;
        init();
        input();
        printf("Case #%d:\n",cas);
        work();
    }
    return 0;
}
