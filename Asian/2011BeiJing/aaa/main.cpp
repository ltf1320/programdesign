#include <iostream>
#include <stdio.h>
#include<string.h>
using namespace std;

int head[1001];

struct EDGE
{
    int to,next;
}e[10001];

int spfa()
{
    int sum=0;
    for(int k=head[1];k!=-1;k=e[k].next)
    sum++;
    return sum;
}

int main()
{
    int n;
  //  freopen("out.txt","w",stdout);
 //   memset(head,-1,sizeof(head));
    while(scanf("%d",&n),n)
    {
  //      printf("hi");
     cout<<"hi"<<endl;
        spfa();
    }
    return 0;
}
