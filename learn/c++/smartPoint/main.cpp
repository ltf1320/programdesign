#include <iostream>
#include "smartPointerclass.h"

using namespace std;

int main()
{
    int a(9),b(2);
    Hasptr ptr1(88,&a);
    Hasptr ptr2(ptr1);
    Hasptr ptr3(77,&b);
    ptr3=ptr1;
    cout<<ptr1;
    delete &ptr1;
    delete &ptr2;
    delete &ptr3;
    return 0;
}
