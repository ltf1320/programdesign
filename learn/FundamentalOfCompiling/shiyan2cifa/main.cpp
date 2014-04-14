#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_row_num 1000
#define Max_word_length 20
#define Key_words_num 6
#define FILEEOF -1
#define HEADSPACE 10

char row[Max_row_num+HEADSPACE];//the present row of inputfile
int row_num;
int now_row;
char now[Max_word_length+HEADSPACE];//the present word or number or symbol
FILE* INPUT_FILE;
FILE* OUTPUT_FILE;
char INPUT_FILE_NAME[Max_row_num+HEADSPACE];
char OUTPUT_FILE_NAME[Max_row_num+HEADSPACE];
char Key_words[Key_words_num][Max_word_length]= {"int","void","if","else","return","while"};
char ch;
int p;

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

enum ERROR_TYPE
{
    Id_TooLong,Num_Toolarge,Id_NoFound
};
int Error_Num;
void error(enum ERROR_TYPE et)
{
    Error_Num++;
    switch(et)
    {
    case Id_TooLong:
        fprintf(OUTPUT_FILE,"Warning in row %d: the identifier is too long\n",now_row);
        break;
    case Num_Toolarge:
        fprintf(OUTPUT_FILE,"Warning in row %d: the number is too large\n",now_row);
        break;
    case Id_NoFound:
        fprintf(OUTPUT_FILE,"Error in row %d: stray %s in program\n",now_row,now);
        break;
    }
}

enum Syn_Type
{
    _Int=0,
    _Void,
    _If,
    _Else,
    _Rrturn,
    _While,
    _Id,
    _Digit,
    _Op,
    _Br_Sq_Right,
    _Br_Big_Right,
    _Str,
    _Comma,
    _Compare,
    _Eql,
    _Sem,
    _Br_Sm_Left,
    _Br_Sm_Right,
    _Br_Sq_Left,
    _Br_Big_Left,
    _Comment,
    WORDERROR
};
enum Syn_Type syn;
int analyse()  //-1 for error -2 for EOF
{
    syn=WORDERROR;
    int np=0,i;
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
            error(Id_TooLong);//!
        now[np]=0;
        syn=_Id;
        for(i=0; i<Key_words_num; i++)
            if(strcmp(now,Key_words[i])==0)
            {
                syn=(enum Syn_Type)i;
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
                error(Num_Toolarge); //!
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
        syn=_Digit;
    }
    else
    {
        now[np++]=ch;
        now[np]=0;
        switch(ch)
        {
        case '*':
            syn=_Op;
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
                syn=_Comment;
            }
            else syn=_Op;
            break;
        case '+':
            syn=_Op;
            break;
        case '-':
            syn=_Op;
            break;
        case ',':
            syn=_Comma;
            break;
        case '>':
            ch=row[p];
            if(ch=='=')
            {
                now[1]=ch;
                now[2]=0;
                syn=_Compare;
                p++;/*бн*/
            }
            else syn=_Compare;
            break;
        case '!':
            ch=row[p];
            now[np++]=ch;
            now[np]=0;
            if(ch=='=')
            {
                now[1]=ch;
                now[2]=0;
                syn=_Compare;
                p++;
            }
            else
            {
                error(Id_NoFound);
                return WORDERROR;
            }
        case '<':
            ch=row[p];
            if(ch=='=')
            {
                now[1]=ch;
                now[2]=0;
                syn=_Compare;
                p++;
            }
            else syn=_Compare;
            break;
        case '=':
            ch=row[p];
            if(ch=='=')
            {
                now[1]=ch;
                now[2]=0;
                syn=_Compare;
                p++;
            }
            else syn=_Eql;
            break;
        case ';':
            syn=_Sem;
            break;
        case '(':
            syn=_Br_Sm_Left;
            break;
        case ')':
            syn=_Br_Sm_Right;
            break;
        case '[':
            syn=_Br_Sq_Left;
            break;
        case ']':
            syn=_Br_Sq_Right;
            break;
        case '{':
            syn=_Br_Big_Left;
            break;
        case '}':
            syn=_Br_Big_Right;
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
            syn=_Str;
            break;
        default :
            error(Id_NoFound);
            return WORDERROR;
        }
    }
    return syn;
}


void Aword()
{
    int tmp;
    now_row=0;
    tmp=analyse();
    while(tmp!=FILEEOF)
    {
        if(syn==WORDERROR)
            //fprintf(OUTPUT_FILE,"Error in row %d!\n",now_row);
            ;
        else fprintf(OUTPUT_FILE,"(%d,%s)\n",syn,now);
        tmp=analyse();
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
}

int main()
{
    //  freopen("out.txt","w",stdout);
    IO();
    Aword();
    return 0;
}
