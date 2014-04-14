#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    for(int i=1;i>=0;--i)
        for(int j=30;j>=0;--j)
            for(int k=59;k>=0;--k)
            {
                cout<<j<<"分"<<k<<"秒后关闭酷我"<<endl;
                Sleep(1000);
                system("cls");
            }
    system("taskkill /im kwmusic.exe");
    return 0;
}
