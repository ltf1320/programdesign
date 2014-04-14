#include <iostream>
#include<cstdio>
using namespace std;

const int maxn=110;

int main()
{
 //   freopen("in.txt","r",stdin);
    char s1[maxn];
    int end=-1;
    string s2;
    char ch;
    while(cin>>ch)
    {
        if(ch=='('||ch=='[')
        {
            s1[++end]=ch;
            s2.push_back(ch);
        }
        else
        {
            if(ch==')')
            {
                while(1)
                {
                    if(end==-1)
                    {
                        s2.push_back('(');
                        s2.push_back(')');
                        break;
                    }
                    else if(s1[end]=='(')
                    {
                        s2.push_back(')');
                        --end;
                        break;
                    }
                    else
                    {
                        s2.push_back(']');
                        --end;
                    }
                }
            }
            else if(ch==']')
            {
                while(1)
                {
                    if(end==-1)
                    {
                        s2.push_back('[');
                        s2.push_back(']');
                        break;
                    }
                    else if(s1[end]=='[')
                    {
                        s2.push_back(']');
                        --end;
                        break;
                    }
                    else
                    {
                        s2.push_back(')');
                        --end;
                    }
                }
            }
        }
    }
    for(; end>=0; --end)
        if(s1[end]=='(')
            s2.push_back(')');
        else s2.push_back(']');
    printf("%s\n",s2.c_str());
    return 0;
}
