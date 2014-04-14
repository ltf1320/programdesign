#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "result.h"
#include "find.h"


int main()
{
    char filename[100];
    char key[100];
    printf("Please input the file name\n");
    scanf("%s",filename);
    printf("please input the key word\n");
    scanf("%s",key);
    find(filename,key);
    system("pause");
    return 0;
}
