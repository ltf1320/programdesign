#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int i=0;
    while((ch=getchar())!=EOF)
    {
        if(ch=='\"')
        {
            if(i%2)
                printf("%c%c",'\'','\'');
            else
                printf("%c%c",'`','`');
            i++;
        }
        else printf("%c",ch);
    }
    return 0;
}
