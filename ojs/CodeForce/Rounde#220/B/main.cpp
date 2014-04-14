#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=100000+100;

char str[maxn];

int main()
{
    long long res=1;
    cin>>str;
    int len=strlen(str);
    int d2;
    for(int i=0;i<len-1;)
    {
        if(str[i]-'0'+str[i+1]-'0'==9)
        {
            d2=0;
            while(str[i]-'0'+str[i+1]-'0'==9)
            {
                i++;
                d2++;
            }
            if(d2%2==0)
            {
                res*=d2/2+1;
            }
        }
        else i++;
    }
    cout<<res<<endl;
    return 0;
}
