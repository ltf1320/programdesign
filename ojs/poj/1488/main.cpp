#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    string word;
    int l,sum;
    char k;
    freopen("in.txt","r",stdin);
    cin>>word;
    while(word!=string("#"))
    {
        sum=0;
        while(word!=string("0"))
        {
            cin>>word;
            cin>>l;
            cin>>k;
            switch(k)
            {
                case 'F':
                    sum+=l*2;
                    break;
                case 'B':
                    if(l%2)
                        sum+=l/2+1;
                    else sum+=l/2;
                    break;
                case 'Y':
                    if(l<=500)
                        sum+=500;
                    else sum+=l;
                    break;
            }
            cin>>word;
        }
        cout<<sum<<endl;
        cin>>word;
    }
    return 0;
}
