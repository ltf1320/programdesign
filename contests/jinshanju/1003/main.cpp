#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int N;

deque<int> que;
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&N);
    char tmp[120];
    int len;
    while(N--)
    {
        que.clear();
        scanf("%s",tmp);
        len=strlen(tmp);
        que.push_front(tmp[0]);
        for(int i=1;i<len;i++)
        {
            if(tmp[i]!='0'&&tmp[i]<=que.front())
                que.push_front(tmp[i]);
            else que.push_back(tmp[i]);
        }
        while(!que.empty())
        {
            putchar(que.front());
            que.pop_front();
        }
        putchar('\n');
    }
    return 0;
}
