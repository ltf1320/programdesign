#include <iostream>
#include <limits>
#include <vector>
#include <stdexcept>
#include "input.h"
using namespace std;

int main()
{
    istream &acin=input(cin);    //注意&！缺了会导致cin被复制（出错）
    cout<<"fuction over"<<endl;
    int k;
    acin>>k;
    cout<<k;
    return 0;
}
