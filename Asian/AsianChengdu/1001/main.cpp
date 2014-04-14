#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
set<int> ss;

int main()
{
    freopen("in.txt","r",stdin);
    int n,t;
    char tmp[10];
    while(~scanf("%d",&n))
    {
        ss.clear();
        while(n--)
        {
            scanf("%s",tmp);
            if(tmp[0]=='a')
            {
                scanf("%d",&t);
                ss.insert(t);
            }
            if(tmp[0]=='d')
            {
                scanf("%d",&t);
                ss.erase(t);
            }
            if(tmp[0]=='s')
            {
                set<int>::iterator iter=ss.begin();
                int i=1;
                int sum=0;
                for(;iter!=ss.end();iter++,i++)
                {
                    if(i%5==3)
                        sum+=*iter;
                }
                printf("%d\n",sum);
            }
        }
    }
    return 0;
}
