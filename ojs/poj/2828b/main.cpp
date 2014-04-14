#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

list<int> que;
const int maxn=200000+100;

int main()
{
    freopen("in.txt","r",stdin);
    int N;
    int follow,val;
    list<int>::iterator iter;
    while(scanf("%d",&N)!=EOF)
    {
        que.resize(0);
        for(int i=0;i<N;++i)
        {
            scanf("%d%d",&follow,&val);
            iter=que.begin();
            for(int j=0;j<follow;++j,++iter);
            que.insert(iter,val);
        }
        for(list<int>::iterator iter=que.begin();iter!=que.end();++iter)
        {
            cout<<*iter<<" ";
        }
        cout<<endl;
    }
    return 0;
}
