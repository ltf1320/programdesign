#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=30;
int N,h,nt;
int f[maxn],t[maxn],d[maxn];
int rest[maxn],nowt[maxn];

struct Node
{
    int id,nf;
    bool operator<(const Node &a)const
    {
        if(nf==a.nf) return id>a.id;
        return nf<a.nf;
    }
    Node(int i,int f):id(i),nf(f){}
    Node(){}
};

priority_queue<Node> que;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tmp;
    Node now;
    int res=0,nres;
    while(~scanf("%d",&N)&&N)
    {
        res=-1;
        scanf("%d",&h);
        h*=12;
        for(int i=0;i<N;i++)
            scanf("%d",&f[i]);
        for(int i=0;i<N;i++)
            scanf("%d",&d[i]);
        t[0]=0;
        for(int i=1;i<N;i++)
        {
            scanf("%d",&tmp);
            t[i]=t[i-1]+tmp;
        }
        for(int i=0;i<N;i++)
        {
            nres=0;
            while(!que.empty()) que.pop();
            memset(nowt,0,sizeof(nowt));
            for(int j=0;j<=i;j++)
                que.push(Node(j,f[j]));
            nt=h-t[i];
            while(nt>0)
            {
                now=que.top();
                que.pop();
                nres+=now.nf;
                nowt[now.id]+=5;
                now.nf-=d[now.id];
                if(now.nf<0) now.nf=0;
                que.push(now);
                nt--;
            }
            if(nres>res)
            {
                for(int i=0;i<N;i++)
                    rest[i]=nowt[i];
                res=nres;
            }
        }
        for(int i=0;i<N-1;i++)
            printf("%d, ",rest[i]);
        printf("%d\n",rest[N-1]);
        printf("Number of fish expected: %d\n\n",res);
    }
    return 0;
}
