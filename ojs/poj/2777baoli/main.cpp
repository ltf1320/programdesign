#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn=100000+100;
int arr[maxn];


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int L,T,O;
    char ch;
    int left,right,col;
    while(1)
    {
        cin>>L>>T>>O;
        int sum=0,sumc=0;
        if(!cin) break;
        for(int j=0;j<2L;++j)
            arr[j]=1;
        for(int i=0; i<O; ++i)
        {
            cin>>ch;
            if(ch=='C')
            {
                cin>>left>>right>>col;
                if(left>right)
                {
                    int tem=right;
                    right=left;
                    left=tem;
                }
                for(int j=left;j<=right;++j)
                    arr[j]=col;
            }
            else
            {
                bool result[40]={0};
                cin>>left>>right;
                if(left>right)
                {
                    int tem=right;
                    right=left;
                    left=tem;
                }
                for(int j=left;j<=right;++j)
                {
                    result[arr[j]]=1;
                }
                int res=0;
                for(int j=0; j<T+1; ++j)
                    if(result[j]) res++;
                cout<<res<<endl;
            }
        }
    }

    return 0;
}
