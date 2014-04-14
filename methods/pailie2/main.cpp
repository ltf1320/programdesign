//可以对有重复数据进行全排列输出的程序
#include <iostream>
#include <algorithm>
using namespace std;
int num[10000];
int s[1000000];

void pailie(int n,int now=0)
{
    if(n==now)
    {
        for(int i=0;i<n;++i)
            cout<<s[i];
        cout<<" ";
        return;
    }
    for(int i=0;i<n;++i) if(!i||num[i]!=num[i-1])
    {
        int c1(0),c2(0);
        for(int j=0;j<now;++j)
            if(s[j]==num[i])
                c1++;
        for(int j=0;j<n;++j)
            if(num[j]==num[i])
                c2++;
        if(c1<c2)
        {
            s[now]=num[i];
            pailie(n,now+1);
        }
    }
}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>num[i];
    sort(num,num+n);
    pailie(n);
    return 0;
}
