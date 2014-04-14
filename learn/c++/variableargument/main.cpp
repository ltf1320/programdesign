#include <iostream>
#include <vector>
#include <cstdarg>
#include <cstdio>
using namespace std;
void myprintf(const char* body,...);  //支持%d,%f,%c，\n,\t等为一个字符，系统自动转换

int main()
{
    myprintf("%d\n%f\6t%c\\",32,2.0,'q');
    cout<<endl<<endl;
    return 0;
}

void myprintf(const char* body,...)
{
    size_t p(0);
    char k;
    va_list val;
    va_start(val,body);
    while((k=body[p])!=0)
    {
        switch(k)
        {
            case '%':
                k=body[++p];
                switch(k)
                {
                    case 'd':
                        cout<<va_arg(val,int);
                        break;
                    case 'f':
                        cout<<va_arg(val,double);
                        break;
                    case 'c':
                        cout<<static_cast<char>(va_arg(val,int));
                        break;
                    default:
                        cout<<k;
                        break;
                }
                break;
                default:
                    cout<<k;
        }
        ++p;
    }
    va_end(val);
}


