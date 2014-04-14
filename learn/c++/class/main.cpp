#include <iostream>
#include "Screen.h"
#include <cstring>
using namespace std;


class CDemo
{
    public:
    CDemo(const char* str);
    ~CDemo();
    private:
    char name[20];
};

CDemo::CDemo(const char *str)
{
    strncpy(name,str,20);
    cout<<"Constructor called for "<<name<<endl;
}

CDemo::~CDemo()
{
    cout<<"Destructor called for "<<name<<endl;
}

void func()
{
    CDemo Local("func Local Object");
    static CDemo Static("Static Object");
    CDemo *Heap=new CDemo("Headp Object in func");
}

CDemo Global("Global Object");

int main()
{
    cout<<"call Main"<<endl;
    CDemo Main("Main Local Object");
    CDemo *Heap=new CDemo("Heap Object in main");
    cout<<endl<<"call func:"<<endl<<endl;
    func();
    cout<<endl<<"After func"<<endl<<endl;
    if()
    delete Heap;
    cout<<endl;
    return 0;

}
