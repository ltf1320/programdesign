#include <iostream>
#include <cstdio>
using namespace std;
#define MOD 9941
#define MAX 10005

struct node
{
    node():next(0) {}
    int val, index;
    node* next;
} HashMap[MOD];

int root[MAX],num[MAX],u=0;
char c[MAX];
int find(int x)
{
    int y = x%MOD;
    node *p,*q;
    p = &HashMap[y], q = HashMap[y].next;
    while (q)
        if(q->val == x)return q->index;
        else p=q,q=q->next;
    node *temp=new node();
    temp->val=x,temp->index=++u,p->next=temp,num[u]=x;
    return u;
}
int findroot(int x)
{
    int t;
    if(root[x]!=x)
    {
        t = root[x];
        root[x]=findroot(root[x]);
        c[x] = c[t]^c[x];
    }
    return root[x];
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,l,n,s,t,r1,r2,v,ans;
    bool IsError = false;
    char ch[5];
    for(i=0; i<MAX; i++)root[i]=i,c[i]=0;
    scanf("%d\n%d", &l, &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d %d %s", &s, &t, ch);
        if(IsError)continue;
        v = (ch[0] == 'e')?0:1;
        s=find(s-1),t=find(t);
        r1=findroot(s), r2=findroot(t);
        if(r1==r2 && (c[s]^c[t]^v))
        {
            IsError=true;
            ans=i-1;
        }
        else if(r1 != r2)
        {
            if(num[r1]<num[r2])root[r2]=r1,c[r2]=c[s]^c[t]^v;
            else root[r1]=r2, c[r1]=c[s]^c[t]^v;
        }
    }
    IsError ? printf("%d\n",ans) : printf("%d\n", n);
    return 0;
}
