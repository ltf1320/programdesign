#include <iostream>

using namespace std;

int main()
{
    bool arr[4][4];
    char ch;
    for(int *p=arr,i=0;i<16;i++,p++)
    {
        cin>>ch;
        if(ch=='b')
            *p=1;
        else *p=0;
    }

    return 0;
}


