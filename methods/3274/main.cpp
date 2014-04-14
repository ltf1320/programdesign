#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
const int pri=99991;
const int maxn=100000;

struct Node
{
    Node()
    {
        next=NULL;
        b=-1;
        num=0;
    }
    Node(long long a)
    {
        next=NULL;
        b=a;
        num=1;
    }
    Node *next;
    long long b;
    int num;
};
Node nds[maxn];

int N,K;

int getHash(long long n)
{
    return n%pri;
}

int main()
{
    long long tmpn;
    int thash;
    scanf("%d%d",&N,&K);
    bool flag;
    Node *p;
    while(N--)
    {
        flag=0;
        scanf("%lld",&tmpn);
        thash=getHash(tmpn);
        for(*p=nds[thash];p->next!=NULL;p=p->next)
        {
            if(tmpn==p->b)
            {
                p->num++;
                flag=1;
            }
        }
        if(!flag)
        {
            p->next=new Node(tmpn);
        }
    }
    int res=0;
    long long
    for(int i=0;i<maxn;i++)
    {

    }
    return 0;
}
