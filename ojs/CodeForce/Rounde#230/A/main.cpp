#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+10;
char str[maxn];

int num[maxn];

int main()
{
  //  freopen("in.txt","r",stdin);
    gets(str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        switch(str[i])
        {
            case 'n':num[0]++;
                break;
            case 'i':num[1]++;break;
            case 'e':num[2]++;break;
            case 't':num[3]++;break;
        }
    }
    if(num[0]<3)
    {
        cout<<0<<endl;
        return 0;
    }
    num[0]=(num[0]+num[0]/3)/3;
    num[2]/=3;
    int res=10000;
    res=min(res,num[0]);
    res=min(res,num[1]);
    res=min(res,num[2]);
    res=min(res,num[3]);
    cout<<res<<endl;
    return 0;
}
