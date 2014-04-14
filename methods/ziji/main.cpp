//求子集
#include <iostream>

using namespace std;

int num[10000];
int s[10000];
void subset(int n,int now=0,int q=0) //q的存在是为了避免重复的子集（1,2,3,4,5与5,4,3,2,1)
{
    for(int i=0;i<now;++i)
        cout<<s[i]<<" ";
    cout<<endl;
    for(int i=q;i<n;++i)
    {
        s[now]=num[i];
        subset(n,now+1,i+1);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>num[i];
    subset(n);
    return 0;
}
