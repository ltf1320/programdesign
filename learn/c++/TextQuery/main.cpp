#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <sstream>
#include "TQ.h"
using namespace std;

int main()
{
    cout << "Please input the file route and name" << endl;
    string filename;
    cin>>filename;
    TQ file(filename);
    cout<<"please input the key word"<<endl;
    string key;
    cin>>key;
    file.findword(key);
    return 0;
}
