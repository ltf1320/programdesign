#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+100;
int n;
int num[maxn];


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    sort(num,num+n);
    if(n==1)
        printf("-1\n");
    else if(n==2)
    {
        int d=num[1]-num[0];
        if(d==0)
            printf("1\n%d\n",num[0]);
        else if(d%2==0)
        {
            printf("3\n");
            printf("%d ",num[0]-d);
            printf("%d ",num[0]+d/2);
            printf("%d\n",num[1]+d);
        }
        else
        {
            printf("2\n");
            printf("%d ",num[0]-d);
            printf("%d\n",num[1]+d);
        }
    }
    else
    {
        int d1=num[1]-num[0],d2,dd=1,td;
        int d1n=1,d2n=0;
        int fd2;
        for(int i=1;i<n-1;i++)
        {
            td=num[i+1]-num[i];
            if(td==d1)
                d1n++;
            else
            {
                if(dd==1)
                {
                    d2=td;
                    fd2=i;
                    d2n=1;
                    dd=2;
                }
                else if(td==d2)
                    d2n++;
                else
                {
                    printf("0\n");
                    return 0;
                }
            }
        }
        if(dd==1)
        {
            if(d1==0)
            {
                printf("1\n%d\n",num[0]);
            }
            else{
            printf("2\n");
            printf("%d ",num[0]-d1);
            printf("%d\n",num[n-1]+d1);
            }
        }
        else
        {
            if(d1n==1&&d2*2==d1)
            {
                printf("1\n");
                printf("%d\n",num[0]+d2);
            }
            else if(d2n==1&&d1*2==d2)
            {
                printf("1\n");
                printf("%d\n",num[fd2]+d1);
            }
            else
                printf("0\n");
        }
    }
    return 0;
}
