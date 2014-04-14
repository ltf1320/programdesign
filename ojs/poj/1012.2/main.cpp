#include <iostream>
#include <cstdio>
using namespace std;

int ans[20];
int s[20];  //s[i] 表示倒数第i次杀的人现在的编号
int joseph(int k,int m)
{
    for(int i=1;i<=k;i++)
    {
        s[i]=(m-1)%(k+i);
        for(int j=1;j<i;j++)
            s[j]=(s[j]+m)%(k+i);
    }
    for(int i=1;i<=k;i++)
        if(s[i]<k) return 0;
    return 1;
}

int main()
{
    freopen("in.txt","r",stdin);
    for(int k=1;k<14;k++)
    {
        for(int m=k+1;m;m+=k+1)  //考虑倒数第一次杀人，由于好人为一个整体，所以最后一次被杀的人一定是0号或者k号，所以(M-1)%(k+1)=0或1
        {
            if(joseph(k,m))
            {
                ans[k]=m;
   //             cout<<m<<endl;
                break;
            }
            if(joseph(k,m+1))
            {
                ans[k]=m+1;
   //             cout<<m+1<<endl;
                break;
            }
        }
    }
    int k;
    while(~scanf("%d",&k)&&k)
        printf("%d\n",ans[k]);
    return 0;
}
