#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <limits>
#include "open_file.h"
using namespace std;

#define CREAT_FILE

int main()
{
    ifstream ifile;
    ofstream ofile;
    while(!open_file(ifile,ofile,"a.txt"))
        cout<<"open file error,please try again"<<endl;
#ifndef CREAT_FILE   //测试时新建文件用的
    ofile.close();
    ofile.open("a");
    ofile<<"ltf sad"<<endl
         <<"xac"<<endl;
    return 1;
#endif
    vector<string> stv;
    string st;
    while(1)   //如果在这里写：while(getline(ifile,st,'\n'),!ifile.eof()),则会导致最后一行被遗弃
    {
        getline(ifile,st,'\n');
        if(ifile.bad())
            throw runtime_error("read file error");
        else if(ifile.fail())
        {
            cout<<"bad data"<<endl;
            ifile.clear(ifstream::goodbit);
            ifile.ignore(std::numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        stv.push_back(st);
        if(ifile.eof()) break;
    }
    for(vector<string>::iterator iter=stv.begin();iter!=stv.end();++iter)
        cout<<*iter<<endl;
    return 0;
}
