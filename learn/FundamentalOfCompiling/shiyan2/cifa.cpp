#include "shiyan2.h"
enum Syn_Type syn;
extern FILE* INPUT_FILE;
extern FILE* OUTPUT_FILE;
char row[Max_row_num+HEADSPACE];//the present row of inputfile
int row_num;
int now_row;
char now[Max_word_length+HEADSPACE];//the present word or number or symbol
char ch;
int p;
int end;

const char Key_words[Key_words_num][Max_word_length]= {"int","void","if","else","return","while"};

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

int analyse()
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
                ch=row[p];
                while(isNum(ch))
                {
                    p++;
                    ch=row[p];
                }
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
//        now[np++]=ch;
//        now[np]=0;
        switch(ch)
        {
        case '*':
            syn=_Op_Mul;
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
            else syn=_Op_Mul;
            break;
        case '+':
            syn=_Op_Add;
            break;
        case '-':
            syn=_Op_Add;
            break;
        case ',':
            syn=_Comma;
            break;
        case '>':
            ch=row[p];
            if(ch=='=')
            {
//               now[1]=ch;
//               now[2]=0;
                syn=_Compare;
                p++;/*бн*/
            }
            else syn=_Compare;
            break;
        case '!':
            ch=row[p];
//           now[np++]=ch;
//           now[np]=0;
            if(ch=='=')
            {
//               now[1]=ch;
//               now[2]=0;
                syn=_Compare;
                p++;
            }
            else
            {
                ch='!';
                error(Id_NoFound);
                return WORDERROR;
            }
        case '<':
            ch=row[p];
            if(ch=='=')
            {
//               now[1]=ch;
//               now[2]=0;
                syn=_Compare;
                p++;
            }
            else syn=_Compare;
            break;
        case '=':
            ch=row[p];
            if(ch=='=')
            {
                //              now[1]=ch;
                //              now[2]=0;
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
                //              now[np++]=row[p];
                if(row[p]=='"')
                {
                    //                  now[np]=0;
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


int getNextSyn()
{
    int tmp;
    do
    {
        tmp=analyse();
        if(tmp==FILEEOF)
        {
            end=1;
            return 0;
        }
    }
    while(syn==_Comment||syn==WORDERROR);
    return 1;
}

int getNextSyn_Noend()
{
    int tmp;
    do
    {
        tmp=analyse();
        if(tmp==FILEEOF)
        {
            end=1;
            error(Unexp_End);
            return 0;
        }
    }
    while(syn==_Comment||syn==WORDERROR);
    return 1;
}
