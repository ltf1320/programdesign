//深刻教训：漏看一个条件xi!=0，花了很久时间调试..

#include <iostream>
#include<cstdio>
#include<vector>
#include <cmath>
using namespace std;

const int maxn=5000;
const int pri=4999;
const float err=1E-7;
int a[5+2];
int q3[100+10];

struct Node
{
    int s;
    int num;
    Node *next;
    Node()
    {
        next=NULL;
        s=0x3f3f3f3f;
    }
    Node(int ss)
    {
        s=ss;
        num=1;
        next=NULL;
    }
};
Node nds[maxn];

int abs(int s)
{
    return s>0?s:-s;
}

int getHash(int &s)
{
    return abs(s%pri);
}

int main()
{
    freopen("in.txt","r",stdin);
    for(int i=-50; i<=50; i++)
        q3[i+50]=i*i*i;
    for(int i=1; i<=5; i++)
        scanf("%d",&a[i]);
    int res=0;
    int tmp,tmh;
    Node *p;
    for(int x1=-50; x1<=50; x1++)
        for(int x2=-50; x2<=50; x2++)
        {
            if(x1==0||x2==0) continue;
            tmp=a[1]*q3[x1+50]+a[2]*q3[x2+50];
            tmh=getHash(tmp);
            for(p=&nds[tmh]; p->next!=NULL; p=p->next)
            {
                if(tmp==p->s)
                {
                    p->num++;
                    p=NULL;
                    break;
                }
            }
            if(p==NULL) continue;
            if(tmp==p->s)
                p->num++;
            else
                p->next=new Node(tmp);
        }
    for(int x3=-50; x3<=50; x3++)
        for(int x4=-50; x4<=50; x4++)
            for(int x5=-50; x5<=50; x5++)
            {
                if(x3==0||x4==0||x5==0) continue;
                tmp=a[3]*q3[x3+50]+a[4]*q3[x4+50]+a[5]*q3[x5+50];
                tmp=-tmp;
                tmh=getHash(tmp);
                for(p=&nds[tmh]; p->next!=NULL; p=p->next)
                {
                    if(tmp==p->s)
                    {
                        res+=p->num;
                        p=NULL;
                        break;
                    }
                }
                if(p==NULL) continue;
                if(tmp==p->s)
                    res+=p->num;
            }
    printf("%d\n",res);
    return 0;
}

