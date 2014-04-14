#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=110;

int num[maxn];
bool used[maxn];
int cnt=0;

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>num[i];
    sort(num,num+N);
    int nc;
    for(int i=0;i<N;i++)
    {
        nc=0;
        while(used[i]) i++;
        if(i>=N) break;
        cnt++;
        nc++;
        used[i]=true;
        for(int j=i+1;j<N;j++)
        {
            if(!used[j]&&num[j]>=nc)
            {
                nc++;
                used[j]=true;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
