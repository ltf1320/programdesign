#include <iostream>
#include <exception>
using namespace std;

class base
{
    public:
        base(int a)
        {
            if(a==0)
                throw 2;
        }
};

class my: public base
{
public:
    my(int a):base(a)
    {

    }
};

int main()
{
    my *k;
    try{
        k=new my(0);
    }
    catch(exception e)
    {
        cout<<"ss"<<endl;
    }
    return 0;
}
