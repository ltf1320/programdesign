#include <iostream>

using namespace std;

char zimu[30];
char result[10000];
int n, L;
bool num;
bool end=0;

bool ish(char k[],int n)
{
    bool result;
    for(int i=1;i<n/2+1;++i)
    {
        result=1;
        for(int j=0;j<i;++j)
        {
            if(k[n-2*i+j]!=k[n-i+j])
            {
                result=0;
                break;
            }
        }
        if(result==1)
            break;
    }
    return result;
}

void dfs(int now=0)
{
    if(num==n&&!end)
    {
        result[now]=0;
        cout<<result<<endl;
        end=1;
        return;
    }
    result[now+1]=0;
    for(int i=0;i<L;++i)
    {
        result[now]=zimu[i];
        if(ish(result,now+1))
            num++;
        dfs(now+1);
    }
}

int main()
{
    char a='A';
    for(int i=0;i<26;++i)
        zimu[i]=++a;
    while(1)
    {
        cin>>n>>L;
        if(!cin) break;
        dfs(0);
    }
    return 0;
}
