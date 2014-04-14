#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
string ss;
set<string> mp;
int main()
{
    freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    int T;
    string t1,t2;
    cin>>T;
    while(T--)
    {
        mp.clear();
        cin>>ss;
        for(size_t i=1;i<ss.size();i++)
        {
            t1=ss.substr(0,i);
            t2=ss.substr(i,ss.size());
            mp.insert(t1+t2);
            mp.insert(t2+t1);
            reverse(t1.begin(),t1.end());
            mp.insert(t1+t2);
            mp.insert(t2+t1);
            reverse(t2.begin(),t2.end());
            mp.insert(t1+t2);
            mp.insert(t2+t1);
            reverse(t1.begin(),t1.end());
            mp.insert(t1+t2);
            mp.insert(t2+t1);
        }
 //       for(set<string>::iterator iter=mp.begin();iter!=mp.end();iter++)
 //           cout<<*iter<<endl;
        cout<<mp.size()<<endl;
    }
    return 0;
}
