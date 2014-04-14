#include <iostream>
#include<ctime>
#include <set>
using namespace std;



int main()
{
    time_t ti;
    struct tm ft;
    ft.tm_year=100;
    ft.tm_mon=11;
    ft.tm_mday=1;
    ft.tm_hour=10;
    ft.tm_min=1;
    ft.tm_sec=10;
    ti=mktime(&ft);
    time(&ti);
    cout<<ctime(&ti)<<endl;

    return 0;
}
