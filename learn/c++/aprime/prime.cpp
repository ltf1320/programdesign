#include <iostream>
#include <vector>
using namespace std;

class Sale_item
{
    public:
    private:
        double num;
        string isbn;
        unsigned sold;
};

int main()
{
    vector<int> intv;
    int temp;
    while(cin>>temp)
        intv.push_back(temp);
    for(vector<int>::size_type i(0);i<intv.size()/2;i++)
    {
        cout<<intv[i]+intv[intv.size()-1-i]<<endl;
    }
}