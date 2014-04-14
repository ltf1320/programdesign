#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=100000+100;
int N;
int res[maxn];
struct Node
{
    Node *next;
    int v;
    Node(){next=NULL;}
};

void reset(Node *p)
{
    if(p->next==NULL) return;
    reset(p->next);
    delete p->next;
    p->next=NULL;
}

Node t1[11];
Node t2[11];

void jp()
{
    Node *from,*to,*t,*p;
    Node *end[11];
    for(int i=0;i<10;i++)
        end[i]=&t1[i];
    int tmp;
    from=t1;
    to=t2;
    for(int i=0; i<N; i++)
    {
        scanf("%d",&tmp);
        end[tmp%10]->next=new Node();
        end[tmp%10]=end[tmp%10]->next;
        end[tmp%10]->v=tmp;
    }
    for(int now=10; now<=10; now*=10)
    {
 //       for(int i=0;i<10;i++)
 //           reset(&to[i]);
        for(int i=0;i<10;i++)
            end[i]=&to[i];
        for(int i=0; i<10; i++)
        {
            p=&from[i];
            while(p->next)
            {
                p=p->next;
                end[(p->v/now)%10]->next=new Node();
                end[(p->v/now)%10]=end[(p->v/now)%10]->next;
                end[(p->v/now)%10]->v=p->v;
            }
        }
        t=from;
        from=to;
        to=t;
    }
    for(int i=0; i<10; i++)
    {
        p=&from[i];
        while(p->next)
        {
            p=p->next;
            printf("%d\n",p->v);
        }
    }
}

/*
int t1[11][maxn];
int t2[11][maxn];

int tn1[11];
int tn2[11];


void jp()
{
    int (*from)[maxn];
    int (*to)[maxn];
    int (*tmp)[maxn];
    int *fn,*tn,*t;
    for(int i=0; i<N; i++)
        scanf("%d",&t1[0][i]);
    memset(tn1,0,sizeof(tn1));
    tn1[0]=N;
    from=t1;
    fn=tn1;
    to=t2;
    tn=tn2;
    for(int now=1; now<=10; now*=10)
    {
        for(int i=0;i<10;i++)
            tn[i]=0;
 //       printf("%d %d\n",now,fn[0]);
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<fn[i]; j++)
            {
                to[(from[i][j]/now)%10][tn[(from[i][j]/now)%10]++]=from[i][j];
            }
        }
        tmp=from;
        from=to;
        to=tmp;
        t=fn;
        fn=tn;
        tn=t;
    }
    int top=0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<fn[i]; j++)
        {
 //           res[top++]=from[i][j];
            printf("%d\n",from[i][j]);
        }
    }
}
*/
void qp()
{
    for(int i=0;i<N;i++)
        scanf("%d",&res[i]);
    sort(res,res+N);
    for(int i=0;i<N;i++)
        printf("%d\n",res[i]);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&N);
    jp();    //0.6~0.7
 //   qp();     //0.1
    return 0;
}
