#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5000+100;
const int MN=5001;

struct Node
{
    int code;
    Node *next;
    Node(int a):code(a),next(NULL){}
    Node():next(NULL){}
};

Node head[maxn];
Node *tail[maxn];
int num[maxn];
int N;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tmp;
    Node* now;
    scanf("%d",&N);
    memset(num,0,sizeof(num));
    for(int i=1;i<MN;i++)
        tail[i]=&head[i];
    for(int i=1;i<=2*N;i++)
    {
        scanf("%d",&tmp);
        tail[tmp]->next=new Node(i);
        tail[tmp]=tail[tmp]->next;
        num[tmp]++;
    }
    for(int i=1;i<MN;i++)
    {
        if(num[i]%2)
        {
            printf("-1\n");
            return 0;
        }
    }
    for(int i=1;i<MN;i++)
    {
        now=head[i].next;
        while(now)
        {
            printf("%d %d\n",now->code,now->next->code);
            now=now->next->next;
        }
    }
    return 0;
}
