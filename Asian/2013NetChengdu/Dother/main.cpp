#include<iostream>
#include<stack>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<cmath>
#define ll long long
#define oo 1000000007
#define eps 1e-5
#define MAXN 100010
using namespace std;
int main()
{
      int C,cases,M,N,i,j,k,t;
     // freopen("input.txt","r",stdin);    freopen("output.txt","w",stdout);
      scanf("%d",&C);
      for (cases=1;cases<=C;cases++)
      {
               scanf("%d%d",&M,&N);
               printf("Case #%d: ",cases);
               if (M==1)
               {
                       while (N--) printf("a");
               }else
               if (M==2)
               {
                       if (N==1) printf("a"); else
                       if (N==2) printf("ab"); else
                       if (N==3) printf("aab"); else
                       if (N==4) printf("aabb"); else
                       if (N==5) printf("aaaba"); else
                       if (N==6) printf("aaabab"); else
                       if (N==7) printf("aaababb"); else
                       if (N==8) printf("aaababbb"); else
                       {
                                printf("aa"),N-=2;
                                for (i=1;i<=N/6;i++) printf("aababb");
                                if (N%6==1) printf("a");
                                if (N%6==2) printf("aa");
                                if (N%6==3) printf("aaa");
                                if (N%6==4) printf("aaaa");
                                if (N%6==5) printf("aabab");
                       }
               }else
               {
                       k=0;
                       while (N--)
                       {
                              if (!k) printf("a");
                              if (k==1) printf("b");
                              if (k==2) printf("c");
                              k=(k+1)%3;
                       }
               }
               printf("\n");
      }
      return 0;
}
