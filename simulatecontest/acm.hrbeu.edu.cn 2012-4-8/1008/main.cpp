#include <iostream>
#include <cstdio>
#include<sstream>
using namespace std;

int md[20]= {0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
    freopen("in.txt","r",stdin);
    int y,m,d;
    char ch;
    string line;
    while(1)
    {
        getline(cin,line);
        if(!cin) break;
        stringstream in(line);
        if(line[4]=='/')
            in>>y>>ch>>m>>ch>>d;
        else if(line[2]=='/')
            in>>m>>ch>>d>>ch>>y;
        else if(line[2]=='-')
            in>>d>>ch>>m>>ch>>y;
        if(m<1||m>12)
        {
            cout<<"wrong date!"<<endl;
            continue;
        }
        if(d<1||d>md[m])
        {
            cout<<"wrong date!"<<endl;
            continue;
        }
        if(m==2)
        {
            if(y%100==0)
            {
                if(y%400)
                {
                    if(d==29)
                    {
                        cout<<"wrong date!"<<endl;
                        continue;
                    }
                }
            }
            else if(y%4)
            {
                if(d==29)
                {
                    cout<<"wrong date!"<<endl;
                    continue;
                }
            }
        }
        if(y/1000==0)
            cout<<0;
        if(y/100==0)
            cout<<0;
        if(y/10==0)
            cout<<0;
        cout<<y<<"-";
        if(m/10==0)
            cout<<0;
        cout<<m<<"-";
        if(d/10==0)
            cout<<0;
        cout<<d<<endl;
    }
    return 0;
}
