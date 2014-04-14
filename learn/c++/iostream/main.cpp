#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
using namespace std;

int main()
{
    int ival;
    vector<int> intv;
    while(cin>>ival,!cin.eof())
    {
        if(cin.bad())
            throw runtime_error("input error");
        else if(cin.fail())
        {
            cerr<<"bad data"<<endl;
            cin.clear(istream::goodbit);
            cin.ignore(std::numeric_limits<std::streamsize>::max( ), '\n' );
            continue;
        }
        intv.push_back(ival);
    }
    for(vector<int>::iterator iter=intv.begin();iter!=intv.end();++iter)
        cout<<*iter<<" ";
    return 0;
}
