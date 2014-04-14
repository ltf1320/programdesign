#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    double num1,num2,result;
    char ch,op;
    string line;
    while(1)
    {
        getline(cin,line);
        while(1)
        {
            string::iterator iter;
            iter=find(line.begin(),line.end(),' ');
            if(iter==line.end()) break;
            line.erase(iter);
        }
        stringstream in(line);
        in>>num1;
        if(!in) break;
        while(1)
        {
            in>>ch;
            if(ch=='+'||ch=='-')
            {
                op=ch;
                break;
            }
        }
        in>>num2;
        switch(op)
        {
            case '+':
                result=num1+num2;
                break;
            case '-':
                result=num1-num2;
                break;
        }
        cout<<num1<<op<<num2<<" = "<<result<<endl;
    }
    return 0;
}
