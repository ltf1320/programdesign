#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_row_num 1000
#define Max_now_num 20
#define Key_words_num 6

char row[Max_row_num];//the present row of inputfile
int row_num;
char now[Max_now_num];//the present word or number or symbol
FILE* INPUT_FILE;
char INPUT_FILE_NAME[Max_row_num];
char Key_words[Key_words_num][Max_now_num]={"begin" ,"if"  , "then" ,  "while" , "do","end"};
char ch;
int p;

int analyse()
{
    int np=0,i,syn=0;
    while(row[p]==' '||row[p]==9) p++;
    ch=row[p++];
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
    {
        now[np++]=ch;
        ch=row[p];
        while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
        {
            p++;
            if(np==Max_now_num) return -1;
            now[np++]=ch;
            ch=row[p];
        }
        now[np]=0;
        syn=10;
        for(i=0;i<Key_words_num;i++)
            if(strcmp(now,Key_words[i])==0)
            {
                syn=i+1;
                break;
            }
    }
    else if(ch>='0'&&ch<='9')
    {
        now[np++]=ch;
        ch=row[p];
        while(ch>='0'&&ch<='9')
        {
            if(np==Max_now_num) return -1;
            now[np++]=ch;
            ch=row[p++];
        }
        now[np]=0;
        syn=11;
    }
    else
    {
        now[0]=ch;now[1]=0;
        switch(ch)
        {
            case '*':syn=13;break;
            case '/':syn=14;break;
            case '+':syn=15;break;
            case '-':syn=16;break;
            case ':':
                ch=row[p];
                if(ch=='=')
                {
                    now[1]=ch;
                    now[2]=0;
                    syn=18;
                    p++;
                }
                else syn=17;
                break;
            case '>':
                ch=row[p];
                if(ch=='=')
                {
                    now[1]=ch;
                    now[2]=0;
                    syn=24;
                    p++;
                }
                else syn=20;
                break;
            case '<':
                ch=row[p];
                if(ch=='=')
                {
                    now[1]=ch;
                    now[2]=0;
                    syn=22;
                    p++;
                }
                else if(ch=='>')
                {
                    now[1]=ch;
                    now[2]=0;
                    syn=21;
                    p++;
                }
                else syn=23;
                break;
            case '=':
                syn=25;break;
            case ';':
                syn=26;break;
            case '(':syn=27;break;
            case ')':syn=28;break;
            case '#':syn=0;break;
            default :return -1;
        }
    }
    return syn;
}

void Aword()
{
    int syn,r=0;
    while(fgets(row,Max_row_num,INPUT_FILE)!=NULL)
    {
        r++;
        row_num=strlen(row);
        p=0;
        while(p<row_num-1) //the last one is'\n'
        {
            syn=analyse();
            if(syn==-1)
                printf("Error in row %d!\n",r);
            else printf("(%d,%s)\n",syn,now);
        }
    }

}

int main()
{
    while(INPUT_FILE==NULL)
    {
        printf("please input the input file name\n");
        scanf("%s",INPUT_FILE_NAME);
        INPUT_FILE=fopen(INPUT_FILE_NAME,"r");
        if(!INPUT_FILE)
            printf("Open file error\n");
        else
        {
            Aword();
            break;
        }
    }
    return 0;
}
