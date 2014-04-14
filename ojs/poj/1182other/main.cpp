#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int front[50005],v[50005];
int find(int x)
{
    if(x!=front[x])
       {
             int y=front[x];
               front[x]=find(front[x]);
              v[x]=(v[x]+v[y])%3;      //回溯中由子结点与父亲结点的关系和父亲结点与根结点的关系找到该子结点与根结点的关系
        }
     else return x;
        return front[x];
}
void link(int x,int y,int z)
{
      int xx=find(x),yy=find(y);
    front[yy]=xx;
 v[yy]=(v[x]-v[y]+3+z)%3;  //由子结点与根结点的关系来找到根结点与根结点的关系
}
int main()
{
    freopen("in.txt","r",stdin);
   int n,m,i,count=0;
    memset(v,0,sizeof(v));
        for(i=0;i<50005;i++)front[i]=i;
        scanf("%d%d",&n,&m);
  while(m--)
    {
             int x,y,z;
            scanf("%d%d%d",&z,&x,&y);
             if(x>n||y>n)count+=1;
           else
          {
                     if(z==1)
                      {
                             if(find(x)!=find(y))link(x,y,0);
                              else if(v[x]!=v[y])count+=1;     //同类则在同一集合，且与根结点的关系相同。

                     }
                     else
                  {
                             if(find(x)!=find(y))link(x,y,1);
                              else if((v[x]+1)%3!=v[y])count+=1;   //在同一根结点，如果两子结点是捕食关系则它们与根结点的关系值差1
                     }
             }
     }
     printf("%d\n",count);
 return 0;
}
