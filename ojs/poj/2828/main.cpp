#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=200000+1000;
struct People
{
    int val;
    int id;
    People(){}
    People(int id_,int val_){id=id_;val=val_;}
};
vector<People> peo[maxn];
bool vis[maxn];

void print(int i)
{
    vis[i]=1;
    int k;
    for(vector<People>::reverse_iterator iter=peo[i].rbegin();iter!=peo[i].rend();++iter)
    {
        printf("%d ",(*iter).val);
        k=(*iter).id;
        if(!vis[k])
            print(k);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int N;
    int follow,val;
    while(scanf("%d",&N)!=EOF)
    {
        for(int i=0;i<N;++i)
            peo[i].clear();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<N;++i)
        {
            scanf("%d%d",&follow,&val);
            peo[follow].push_back(People(i,val));
        }
        for(int i=0;i<N;++i)
        {
            if(!vis[i]) print(i);
        }
        printf("\n");
    }
    return 0;
}
