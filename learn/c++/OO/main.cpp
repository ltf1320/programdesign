#include <iostream>
#include <stdexcept>
#include "books.h"
using namespace std;

int main()
{
    AudioBook BookCpp("e0001","c++primer","J",120,15);
    cout<<BookCpp<<endl;
    return 0;
}


