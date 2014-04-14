#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=110;
int a,b;
struct Node
{
    int x,y;
};
Node que[maxn];
int len;
char s[110];
int main()
{
 //   freopen("in.txt","r",stdin);
    bool flag;
    que[0].x=que[0].y=0;
    while(~scanf("%d%d",&a,&b))
    {
        scanf("%s",s);
        len=strlen(s);
        for(int i=1;i<=len;i++)
        {
            switch(s[i-1])
            {
                case 'U':que[i].x=que[i-1].x;que[i].y=que[i-1].y+1;break;
                case 'D':que[i].x=que[i-1].x;que[i].y=que[i-1].y-1;break;
                case 'L':que[i].x=que[i-1].x-1;que[i].y=que[i-1].y;break;
                case 'R':que[i].x=que[i-1].x+1;que[i].y=que[i-1].y;break;
            }
        }
        flag=0;
        for(int i=0;i<len;i++)
        {
            if(que[len].x==0)
            {
                if(que[len].y==0)
                {
                    if(a==que[i].x&&b==que[i].y)
                    {
                        flag=1;
                        break;
                    }
                }
                if(a==que[i].x&&(b-que[i].y)%que[len].y==0)
                {
                    flag=1;
                    break;
                }
            }
            else if(que[len].y==0)
            {
                if(b==que[i].y&&(a-que[i].x)%que[len].x==0)
                {
                    flag=1;
                    break;
                }
            }
            else
            {
                if((a-que[i].x)%que[len].x!=0)
                    continue;
                if((b-que[i].y)%que[len].y!=0)
                    continue;
                if((a-que[i].x)*que[len].x<0)
                    continue;
                if((b-que[i].y)*que[len].y<0)
                    continue;
                if(((a-que[i].x)/que[len].x)==((b-que[i].y)/que[len].y))
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
