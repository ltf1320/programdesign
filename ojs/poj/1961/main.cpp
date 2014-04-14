#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000000+10;
char str[maxn];
int pi[maxn];
int len,N;
void pre()
{
    int p,k;
    k=-1;
    pi[0]=-1;
    for(p=1;p<len;p++)
    {
        while(k!=-1&&str[k+1]!=str[p])
            k=pi[k];
        if(str[k+1]==str[p])
            k++;
        pi[p]=k;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int cas=1;
    while(scanf("%d",&N))
    {
        if(!N) break;
        scanf("%s",str);
        len=strlen(str);
        pre();
        printf("Test case #%d\n",cas++);
        for(int i=1;i<N;i++)
            if((i+1)%(i-pi[i])==0&&(i+1)/(i-pi[i])>1)
            {
                printf("%d %d\n",i+1,(i+1)/(i-pi[i]));
            }
        printf("\n");
    }
    return 0;
}
