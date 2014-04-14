#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
int N;
int num[maxn];
bool fw[maxn];

bool bin(int a,int b,int c)
{
    if(a>b)
        swap(a,b);
    if(c>=a&&c<=b)
        return true;
    return false;
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&num[i]);
    for(int i=1;i<N;i++)
    {
        if(bin(num[i-1],num[i],num[i+1]))
            fw[i]=1;
        else
            fw[i]=0;
        for(int j=i-1;j>=1;j--)
        {
            if(fw[j]&&!bin(num[j],num[j-1],num[i]))
            {
                printf("yes\n");
                return 0;
            }
            if(!fw[j]&&bin(num[j],num[j-1],num[i]))
            {
                printf("yes\n");
                return 0;
            }
        }
    }
    printf("no\n");
    return 0;
}
