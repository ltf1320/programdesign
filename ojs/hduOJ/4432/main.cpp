#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=100;

int num[100];
int nn;
int N,M;

void change(int n,int jz)
{
    nn=0;
    while(n)
    {
        num[nn]=n%jz;
        n/=jz;
        nn++;
    }
}

int getSum(int a)
{
    int sq=sqrt(a);
    int sum=0;
    for(int i=1; i<=sq; i++)
        if(a%i==0)
        {
            change(i,M);
            for(int j=0; j<nn; j++)
                sum+=num[j]*num[j];
            if(a/i>sq)
            {
                change(a/i,M);
                for(int j=0; j<nn; j++)
                    sum+=num[j]*num[j];
            }
        }
    return sum;
}


void printnum()
{
    for(int i=nn-1; i>=0; i--)
    {
        if(num[i]<10)
            printf("%d",num[i]);
        else printf("%c",num[i]-10+'A');
    }
    putchar('\n');
}


int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        change(getSum(N),M);
        printnum();
    }
    return 0;
}
