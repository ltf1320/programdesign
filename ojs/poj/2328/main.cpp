#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int n,max,min;
    string s1,s2;
    bool s=1;
    max=11;
    min=0;
    while(~scanf("%d",&n))
    {
        if(!n) break;
        cin>>s1>>s2;
        if(s1=="too")
        {
            if(s2=="high")
            {
                if(n<min)
                    s=0;
                else if(max>n)
                    max=n;
            }
            else
            {
                if(n>max)
                    s=0;
                else if(min<n)
                    min=n;
            }
        }
        else
        {
            if(n>min && n<max &&s)
                cout<<"Stan may be honest"<<endl;
            else cout<<"Stan is dishonest"<<endl;
            max=11;
            min=0;
            s=1;
        }
    }
    return 0;
}
