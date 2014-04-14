#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int abs(int a)
{
    return a>0?a:-a;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    int s[3000+100];
    bool v[3000+100];
    bool flag;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&s[i]);
        if(n==1)
        {
            printf("Jolly\n");
            continue;
        }
        memset(v,0,sizeof(v));
        for(int i=1;i<n;i++)
            v[abs(s[i]-s[i-1])]=1;
        flag=1;
        for(int i=1;i<n;i++)
        {
            if(!v[i])
            {
                flag=0;
                break;
            }
        }
        if(flag) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}
