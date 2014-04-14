#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream in1,in2;
    in1.open("in1.txt",ios::in);
    in2.open("in2.txt",ios::in);
    string line1,line2;
    int l=1;
    while(1)
    {
        getline(in1,line1);
        getline(in2,line2);
        if(!in1) break;
        if(!in2) break;
        if(line1!=line2)
            cout<<"wrong:"<<l<<endl;
        l++;

    }
    return 0;
}
