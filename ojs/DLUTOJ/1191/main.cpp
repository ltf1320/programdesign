#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
const int maxn=10000;
queue<int> ML,BF;
int stack[2*maxn+200];
int top;
int n,m,z;
int main()
{
    freopen("in.txt","r",stdin);
    int tmp;
    int k,step;
    while(~scanf("%d%d%d",&n,&m,&z))
    {
        while(!ML.empty()) ML.pop();
        while(!BF.empty()) BF.pop();
        top=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&tmp);
            ML.push(tmp);
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d",&tmp);
            BF.push(tmp);
        }
        step=0;
        while(step++<z)
        {
            if(step&1)
            {
                tmp=ML.front();
                ML.pop();
                k=-1;
                for(int i=top-1;i>=0;--i)
                    if(stack[i]==tmp)
                    {
                        k=i;
                        break;
                    }
                if(k!=-1)
                {
                    ML.push(tmp);
                    while(top>k)
                    {
                        ML.push(stack[--top]);
                    }
                    top++;
                }
                else
                    stack[top++]=tmp;
            }
            else
            {
                tmp=BF.front();
                BF.pop();
                k=-1;
                for(int i=top-1;i>=0;--i)
                    if(stack[i]==tmp)
                    {
                        k=i;
                        break;
                    }
                if(k!=-1)
                {
                    BF.push(tmp);
                    while(top>k)
                    {
                        BF.push(stack[--top]);
                    }
                    top++;
                }
                else
                    stack[top++]=tmp;
            }
            if(ML.empty() || BF.empty())
                break;
        }
        printf("%d %d",ML.size(),BF.size());
    }
    return 0;
}
