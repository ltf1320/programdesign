#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5000+100;
const int inf=0x3f3f3f3f;
int N;
bool ori[maxn]; //1 for B,0 for forward
bool state[2*maxn];

int resk,resm;
int start;
int findFa(int l,int r)
{
   while(l!=r)
   {
       l>>=1;
       r>>=1;
   }
   return l;
}

void change(int l,int r)
{
    int m=findFa(start+l,start+r);
    state[m]^=1;
}

void getStart()
{
    start=1;
    while(start<N)
        start<<=1;
}

bool query(int a)
{
    int now=start+a;
    bool res=0;
    while(now)
    {
        res^=state[now];
        now>>=1;
    }
    return res;
}

void buildTree()
{
    getStart();
    memset(state,0,sizeof(state));
    for(int i=0;i<N;i++)
        state[start+i]=ori[i];
}

void judge(int k)
{
    int nowm=0;
    buildTree();
    for(int i=0;i<N;i++)
    {
        if(query(i))
        {
            change(i,i+k-1);
            nowm++;
        }
    }
    if(nowm<resm)
    {
        resk=k;
        resm=nowm;
    }
}

void input()
{
    char ch;
    for(int i=0;i<N;i++)
    {
        scanf("%c",&ch);
        if(ch==' '||ch=='\n')
        {
            i--;continue;
        }
        if(ch=='B')
            ori[i]=1;
        else ori[i]=0;
    }
}

void work()
{
    resm=inf;
    for(int i=1;i<=N;i++)
        judge(i);
    printf("%d %d\n",resk,resm);
}

int main()
{
    scanf("%d",&N);
    input();
    work();
    return 0;
}
