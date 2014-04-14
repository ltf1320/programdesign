#include "shiyan2.h"

FILE* INPUT_FILE;
FILE* OUTPUT_FILE;
FILE* TABLE_FILE;
char INPUT_FILE_NAME[Max_row_num+HEADSPACE];
char OUTPUT_FILE_NAME[Max_row_num+HEADSPACE];
char TABLE_FILE_NAME[Max_row_num+HEADSPACE];

void PutLine()
{
    fprintf(OUTPUT_FILE,"\n");
}

void IO()
{
    while(INPUT_FILE==NULL)
    {
        printf("Please input the input file name,single enter for standard input\n");
        gets(INPUT_FILE_NAME);
        if(INPUT_FILE_NAME[0]==0)
            INPUT_FILE=stdin;
        else INPUT_FILE=fopen(INPUT_FILE_NAME,"r");
        if(!INPUT_FILE)
            printf("Open input file error\n");
    }
    while(OUTPUT_FILE==NULL)
    {
        printf("Please input the output file name,single enter for standard output\n");
        gets(OUTPUT_FILE_NAME);
        if(OUTPUT_FILE_NAME[0]==0)
            OUTPUT_FILE=stdout;
        else OUTPUT_FILE=fopen(OUTPUT_FILE_NAME,"w");
        if(!OUTPUT_FILE)
            printf("Open output file error\n");
    }
    while(TABLE_FILE==NULL)
    {
        printf("Please input the table output file name,single enter for table.txt\n");
        gets(TABLE_FILE_NAME);
        if(TABLE_FILE_NAME[0]==0)
            TABLE_FILE=fopen("table.txt","w");
        else TABLE_FILE=fopen(TABLE_FILE_NAME,"w");
        if(!TABLE_FILE)
            printf("Open output file error\n");
    }
}
