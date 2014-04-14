#include <iostream>
#include "Sale_item.h"

using namespace std;

int main()
{
    Sale_item item1,item2;
    cout<<"please input one item:"<<endl;
    item1.input();
    cout<<"this is the item:"<<endl;
    item1.output();
    cout<<endl
        <<"please input another item:"<<endl;
    item2.input();
    cout<<"this is the item:"<<endl;
    item2.output();
    cout<<endl
        <<"addition is:"<<endl;
    item2.add(item1);
    item2.output();
    return 0;
}
