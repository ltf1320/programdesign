#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


int main()
{
    int num;
    while(1)
        try
        {
            cout<<"input a number,not 0"<<endl;
            cin>>num;
            if(num==0)
              //  throw runtime_error("0 is not permited");
                    throw 2;
            if(num<0)
                cerr<<"ERROR: "<<__FILE__<<endl
                    <<"LINE: "<<__LINE__<<endl
                    <<"compiled on "<<__DATE__<<endl
                    <<"  at "<<__TIME__<<endl;
            cout<<10.0/num<<endl;
        }
        catch(runtime_error err)   //err 是runtime_error类类型
        {
            cout<<err.what()<<endl
                <<"try again? Enter 'y' to continue"<<endl;
            char ch;
            cin>>ch;
            if(ch!='y')
                break;    //程序默认执行continue
        }
        catch(int)
        {
            cout<<"d"<<endl;
        }
}
