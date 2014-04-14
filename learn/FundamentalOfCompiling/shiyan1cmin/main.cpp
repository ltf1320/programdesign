#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_row_num 1000
#define Max_word_length 20
#define Key_words_num 6
#define FILEEOF -2
#define WORDERROR -1
#define HEADSPACE 10

char row[Max_row_num+HEADSPACE];//the present row of inputfile
int p;
int row_num;
int now_row;
char now[Max_word_length+HEADSPACE];//the present word or number or symbol
FILE* INPUT_FILE;
FILE* OUTPUT_FILE;
char INPUT_FILE_NAME[Max_row_num+HEADSPACE];
char OUTPUT_FILE_NAME[Max_row_num+HEADSPACE];
char Key_words[Key_words_num][Max_word_length]= {"int","void","if","else","return","while"};
char ch;


int isChar(char ch)
{
    if(ch>='A'&&ch<='Z') return 1;
    if(ch>='a'&&ch<='z') return 1;
    return 0;
}

int isNum(char ch)
{
    if(ch>='0'&&ch<='9') return 1;
    return 0;
}

int getNextLine()
{
    if(fgets(row,Max_row_num,INPUT_FILE)==NULL) return FILEEOF;
    now_row++;
    p=0;
    row_num=strlen(row);
    return 0;
}

int analyse()  //-1 for error -2 for EOF
{
    int np=0,i,syn=0;
    while(p>=row_num-1)
        if(getNextLine()==FILEEOF)
            return FILEEOF;
    while(row[p]==' '||row[p]==9)
    {
        p++;
        while(p>=row_num-1)
            if(getNextLine()==FILEEOF) return FILEEOF;
    }
    ch=row[p++];
    if(isChar(ch))
    {
        now[np++]=ch;
        ch=row[p];
        while(isChar(ch)||isNum(ch))
        {
            p++;
            if(np<Max_word_length)
                now[np++]=ch;
            ch=row[p];
        }
        if(np>=Max_word_length)
            fprintf(OUTPUT_FILE,"Warning in row %d: the identifier is too long\n",now_row); //!
        now[np]=0;
        syn=10;
        for(i=0; i<Key_words_num; i++)
            if(strcmp(now,Key_words[i])==0)
            {
                syn=i+1;
                break;
            }
    }
    else if(isNum(ch))
    {
        now[np++]=ch;
        ch=row[p];
        while(isNum(ch))
        {
            p++;
            if(np==Max_word_length)
            {
                fprintf(OUTPUT_FILE,"Warning in row %d: the number is too large\n",now_row); //!
                while(isNum(ch))
                    ch=row[p++];
                now[0]='0';
                np=1;
                break;
            }
            now[np++]=ch;
            ch=row[p];
        }
        now[np]=0;
        syn=11;
    }
    else
    {
        now[np++]=ch;
        now[np]=0;
        switch(ch)
        {
        case '*':
            syn=13;
            break;
        case '/':
            ch=row[p];
            if(ch=='*')
            {
                strcpy(now,"omitted");
                p++;
                while(true)
                {
                    if(row[p]=='*'&&row[p+1]=='/')
                    {
                        p=p+2;
                        break;
                    }
                    p++;
                    if(p>=row_num-1)
                        if(getNextLine()==FILEEOF) return WORDERROR;
                }
                syn=35;
            }
            else syn=14;
            break;
        case '+':
            syn=15;
            break;
        case '-':
            syn=16;
            break;
        case ',':
            syn=17;
            break;
        case '>':
            ch=row[p];
            if(ch=='=')
            {
                now[1]=ch;
                now[2]=0;
                syn=24;
                p++;/*бн*/
            }
            else syn=20;
            break;
        case '!':
            ch=row[p];
            if(ch=='=')
            {
                now[1]=ch;
                now[2]=0;
                syn=21;
                p++;
            }
            else return WORDERROR;
        case '<':
            ch=row[p];
            if(ch=='=')
            {
                now[1]=ch;
                now[2]=0;
                syn=22;
                p++;
            }
            else syn=23;
            break;
        case '=':
            ch=row[p];
            if(ch=='=')
            {
                now[1]=ch;
                now[2]=0;
                syn=18;
                p++;
            }
            else syn=25;
            break;
        case ';':
            syn=26;
            break;
        case '(':
            syn=27;
            break;
        case ')':
            syn=28;
            break;
        case '[':
            syn=29;
            break;
        case ']':
            syn=30;
            break;
        case '{':
            syn=31;
            break;
        case '}':
            syn=32;
            break;
        case '&':
            syn=33;
            break;
        case '"':
            while(true)
            {
                now[np++]=row[p];
                if(row[p]=='"')
                {
                    now[np]=0;
                    p++;
                    break;
                }
                p++;
                while(p>=row_num-1)
                    if(getNextLine()==FILEEOF) return FILEEOF;
            }
            syn=34;
            break;
        default :
            return WORDERROR;
        }
    }
    return syn;
}


void Aword()
{
    int syn;
    now_row=0;
    syn=analyse();
    while(syn!=FILEEOF)
    {
        if(syn==WORDERROR)
            fprintf(OUTPUT_FILE,"Error in row %d!\n",now_row);
        else fprintf(OUTPUT_FILE,"(%d,%s)\n",syn,now);
        syn=analyse();
    }

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
        else
        {
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
        }
    }
}

int main()
{
    //  freopen("out.txt","w",stdout);
    IO();
    Aword();
    return 0;
}
