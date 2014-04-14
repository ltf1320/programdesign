#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=100;
const char is[10][10]= {"void", "byte", "char", "int", "long", "float", "double" , "__int64"};
char tmp[maxn];


int main()
{
    bool flag;
    while(true)
    {
        gets(tmp);
        if(tmp[0]=='e') break;
        flag=0;
        for(int i=0; i<8; i++)
            if(!strcmp(is[i],tmp))
            {
                flag=1;
            }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
