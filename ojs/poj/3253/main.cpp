//直接看算法导论做的...2A(long long)
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;



struct Node
{
    Node *left,*right;
    int s;
    Node(){};
    Node(int k)
    {
        left=right=NULL;
        s=k;
    }
    Node(Node *a,Node *b)
    {
        left=a;
        right=b;
        s=a->s+b->s;
    }
    bool operator<(const Node &a) const
    {
        return s>a.s;
    }
};
Node *head;

void buildTree()
{
    priority_queue<Node> que;
    int n,tmp;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&tmp);
        que.push(Node(tmp));
    }
    Node *t1,*t2;
    while(1)
    {
        t1=new Node(que.top());
        que.pop();
        if(que.empty())
        {
            head=t1;
            return;
        }
        t2=new Node(que.top());
        que.pop();
        que.push(Node(t1,t2));
    }
}
long long res;
void dfs(Node *p)
{
    if(p->left==NULL) return;
    res+=p->s;
    dfs(p->left);
    dfs(p->right);
}

int main()
{
    freopen("in.txt","r",stdin);
    buildTree();
    res=0;
    dfs(head);
    printf("%lld\n",res);
    return 0;
}
