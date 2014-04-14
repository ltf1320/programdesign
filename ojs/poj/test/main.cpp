#include <iostream>
#include <stdio.h>

using namespace std;
int f(int n)
{
    if(n==1||n==2) return 1;
    return f(n-1)+f(n-2);
}
int main()
{
    printf("%d\n",f(45));
    return 0;
}
