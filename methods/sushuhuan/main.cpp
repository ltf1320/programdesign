#include <iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<ctime>
using namespace std;
const int maxn=100;
bool isnp[maxn+10];
int result[maxn+10];
bool used[maxn+10];
int num=0;
void dps(int n,int now=0)
{
    if(n==now)
    {
        num++;
        for(int i=0; i<n; ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }

    else
        for(int i=1; i<=n; ++i) if(!used[i])
            {
                if(!isnp[result[now-1]+i])
                {
                    result[now]=i;
                    used[i]=1;
                    dps(n,now+1);
                    used[i]=0;
                }
            }
}

int main()
{
    freopen("out.txt","w",stdout);
    freopen("in.txt" ,"r",stdin);
    int i;          //打一个素数表
    isnp[1]=1;
    for(i=4; i<maxn; i+=2)
        isnp[i]=1;
    for(i=3; i<sqrt(maxn); i+=2)
        if(!isnp[i])
        {
            int s=2*i;
            for(int j=i*i; j<maxn; j+=s)
                isnp[j]=1;
        }
    int n;
    memset(used,0,sizeof(used));
    result[0]=1;
    used[1]=1;
//    while(1)
    {
        cin>>n;
//        if(!cin||n==0) break;
        cout<<n<<":"<<endl;
        dps(n,1);
        cout<<"num:"<<num<<endl;
        cout<<"time:"<<static_cast<double>(clock())/CLOCKS_PER_SEC<<endl;
        num=0;
    }
    return 0;
}
