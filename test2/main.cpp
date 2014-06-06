#include <iostream>
#include <cstdio>
#include <windows.h>
using namespace std;

int main(int argc,char **argv)
{
    if(argc==0)
        return 0;
    int cnt;
    sscanf(argv[0],"%d",&cnt);
    for(int i=0;i<cnt*10000000;i++)
    {
        int j;
    }
    return 0;
}
