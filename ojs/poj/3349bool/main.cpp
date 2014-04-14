#include <iostream>
#include <stdio.h>
#define MAX_V 90001
#define MAXN 100000+10
#define MAXM MAX_V+10

using namespace std;

struct Snowflake
{
    int a[6];
    Snowflake *next;
}snow[MAXN],head[MAXM];

int n;

bool compare(Snowflake *p,Snowflake *q)
{
    int i=0,k=0,j=0;
    for(i=0;i<6;i++)
    {
        if(p->a[i]==q->a[0])break;
    }
    k=i;
    for(j=0;j<6;j++)
    {
        if(q->a[j]==p->a[i])i=(i+1)%6;
        else break;
    }
    if(j==6)return true;
    for(j=0;j<6;j++)
    {
        if(k<0)k+=6;
        if(q->a[j]==p->a[k])k--;
        else break;
    }
    if(j==6)return true;
    return false;
}

bool serchANDinsert(int temp,Snowflake *q)
{
    Snowflake *p=&head[temp];
    while(p->next)
    {
        if(compare(p->next,q))return true;
        p=p->next;
    }
    p->next=q;
    q->next=NULL;
    return false;
}

void init()
{
    for(int i=0;i<MAXN;i++)
    {
        snow[i].next=NULL;
    }
    for(int i=0;i<MAXM;i++)
    {
        head[i].next=NULL;
    }
}

void print()
{
    Snowflake *p=NULL;
    for(int i=0;i<50;i++)
    {
        p=&head[i];
        printf("%d\n",i);
        while(p->next)
        {
            for(int i=0;i<6;i++)
            {
                printf("%d ",p->next->a[i]);
            }
            printf("\n");
            p=p->next;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    bool flag=0;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        flag=false;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum=0;
            for(int j=0;j<6;j++)
            {
                scanf("%d",&snow[i].a[j]);
                sum+=snow[i].a[j];
            }
            if(flag==false&&serchANDinsert(sum%MAX_V,&snow[i]))flag=true;
        }
        if(flag)printf("Twin snowflakes found.\n");
        else printf("No two snowflakes are alike.\n");
        //print();
    }
    return 0;
}
