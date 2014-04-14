#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
    int ia[]={0,1,1,2,3,5,8,13,21,55,89};
    list<int> intl(ia,ia+11);
    vector<int> intv(ia,ia+11);
    bool flag=0;
    for(vector<int>::iterator iter=intv.begin();iter!=intv.end();)
    {
        for(int i=0;i<5;i++,iter++)
        {
            if(iter==intv.end())
            {
                flag=1;
                break;
            }
            cout<<*iter<<" ";
        }
        if(flag) break;
        cout<<endl;
    }
    intv.reserve(50);
    cout<<intv.size()<<endl
        <<intv.capacity()<<endl;
    return 0;
}
