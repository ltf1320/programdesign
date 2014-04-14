#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=10000*3;
struct Node
{
    Node *l,*r;
    int mx,kk;
    bool flag;
    Node() {}
    Node(int n)
    {
        mx=n;
        kk=1;
        flag=1;
    }
    Node(Node *ll,Node *rr)
    {
        l=ll;
        r=rr;
        mx=max(l->mx,r->mx);
        kk=l->kk+r->kk;
        flag=0;
    }
};


struct FSO
{
    Node *s;
    FSO(Node *a)
    {
        s=a;
    }
    bool operator<(const FSO &b)const
    {
        if(s->kk==b.s->kk)
            return s->mx>b.s->mx;
        return s->kk>b.s->kk;
    }

};
priority_queue<FSO> que;
Node *Root;
void buildTree(int N)
{
    for(int i=0; i<N; i++)
        que.push(FSO(new Node(i)));
    Node *l,*r;
    while(!que.empty())
    {
        if(que.size()==1) break;
        l=que.top().s;
        que.pop();
        r=que.top().s;
        que.pop();
        que.push(FSO(new Node(l,r)));
    }
    Root=que.top().s;
    que.pop();
}

char nowstr[maxn];
void printTree(int dep,Node *now)
{
    if(now->flag)
    {
        nowstr[dep]=0;
        puts(nowstr);
    }
    else
    {
        nowstr[dep]='0';
        printTree(dep+1,now->l);
        nowstr[dep]='1';
        printTree(dep+1,now->r);
    }
}

int main()
{
    int N;
    while(~scanf("%d",&N))
    {
        if(N==1)
        {
            printf("0\n");
            continue;
        }
        buildTree(N);
        printTree(0,Root);
    }
    return 0;
}
