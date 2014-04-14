#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    double num1,num2,result;
    cin>>num1>>num2;
    while(cin)
    {
        result=abs(num2-num1);
        cout<<result<<endl;
        cin>>num1>>num2;
    }
}
