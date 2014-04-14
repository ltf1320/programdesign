#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5000+10;
const int inf=0x3f3f3f3f;
int N;
struct Node
{
    int pr,n;
    Node* next;
    Node()
    {
        next=0;
    }
    Node(int p,int dn,Node *ne):pr(p),n(dn),next(ne) {}
};
Node nds[maxn];


int main()
{
    freopen("in.txt","r",stdin);
    int dn,tmp;
    int maxd=0;
    Node *now;
    nds[0].next=new Node();
    nds[0].next->pr=inf;
    nds[0].next->n=1;
    scanf("%d",&N);
    for(int i=0; i<N; i++)
    {
        scanf("%d",&tmp);
        for(int j=maxd; j>=0; j--)
        {
            now=&nds[j];
            dn=0;
            while(now->next&&now->next->pr>tmp)
            {
                dn+=now->next->n;
                now=now->next;
            }
            if(dn>0)
            {
                now=&nds[j+1];
                while(now->next&&now->next->pr>tmp)
                    now=now->next;
                if(now->next&&now->next->pr==tmp)
                    now->next->n+=dn;
                else
                    now->next=new Node(tmp,dn,now->next);
                maxd=max(maxd,j+1);
            }
        }
    }
    dn=0;
    now=nds[maxd].next;
    while(now)
    {
        dn+=now->n;
        now=now->next;
    }
    printf("%d %d\n",maxd,dn);
    return 0;
}
