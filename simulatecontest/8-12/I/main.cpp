#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=10;
int cnt[maxn];
const int sc[maxn]={16,7,8,1,1,2,3};
int getScore()
{
    int N;
    char ch;
    int res=0;
    scanf("%d",&N);
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<N;i++)
    {
        scanf("%c",&ch);
        if(ch==' ') {i--;continue;}
        cnt[ch-'A']++;
    }
    for(int i=)
}

int main()
{
    int N,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
    }
    return 0;
}
