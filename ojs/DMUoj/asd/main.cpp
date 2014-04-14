#include<iostream>
#include<vector>
#include <cstdio>
#include<algorithm>
using namespace  std;
int main()
{
 //  freopen("test.in","r",stdin);
 //  freopen("test.out","w",stdout);
    int x,n,t;
    while(scanf("%d",&n)!=EOF){
        if(n==1 || n%2==0){
            //不存在这样的x
            printf("2^? mod %d = 1\n",n);
        }else{
            x=1;
            t=2;
            //暴力找到最小的x使得2^x mod n=1
            while(t%n!=1){
                x++;
                t=t*2%n;
            }
            printf("2^%d mod %d = 1\n",x,n);
        }
    }
    return 0;
}
