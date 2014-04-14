#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char ch,lc;
    bool f=0,st=0;
    lc=getchar();
    while((ch=getchar())!='\n')
    {
        st=1;
        if(lc=='0'&&!f)
        {
            f=1;
            lc=ch;
            continue;
        }
        putchar(lc);
        lc=ch;
    }
    if(!st) printf("0\n");
    else if(f==0) putchar('\n');
    else printf("%c\n",lc);
    printf("%d",6*5*4*3*2*2);
    return 0;
}
