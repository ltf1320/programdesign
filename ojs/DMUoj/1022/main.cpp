#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const char is[10][10]={"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int main()
{
    int N;
    while(~scanf("%d",&N)&&N)
    {
        printf("%s\n",is[N%7]);
    }
    return 0;
}
