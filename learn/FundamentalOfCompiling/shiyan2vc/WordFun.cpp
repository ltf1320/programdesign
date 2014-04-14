#include "shiyan2.h"

/*
For insert word or function to the table
*/
extern enum Syn_Type syn;
extern char now[Max_word_length+HEADSPACE];
int getTreeN(char ch)
{
    if(ch>='a'&&ch<='z')
        return ch-'a';
    if(ch>='A'&&ch<='Z')
        return ch-'A'+26;
    if(ch=='_')
        return 53;
    return -1;
}

void FunParaNode_init(FunParaNode *a)
{
    a->next=0;
}

void FunTree_init(FunTree *a)
{
    memset(a->next,0,sizeof(a->next));
    a->end=0;
    a->para=0;
}
void WordTree_init(WordTree *a)
{
    memset(a->next,0,sizeof(a->next));
    a->end=0;
}

WordTree WordTreeStack[Max_Stack_num];
FunTree *FunTreeStack[Max_Stack_num];
int Stack_p;
FunTree FunTreeHead;

FunTree* FunTree_insert(char *str)
{
    int len=strlen(str);
    FunTree *now=&FunTreeHead;
    for(int i=0; i<len; i++)
    {
        if(!now->next[getTreeN(str[i])])
        {
            now->next[getTreeN(str[i])]=(FunTree*)malloc(sizeof(FunTree));
            FunTree_init(now->next[getTreeN(str[i])]);
        }
        now=now->next[getTreeN(str[i])];
    }
    now->end=1;
    return now;
}

FunTree* FunTree_find(char *str)
{
    int len=strlen(str);
    FunTree *now=&FunTreeHead;
    for(int i=0; i<len; i++)
    {
        if(!now->next[getTreeN(str[i])])
            return NULL;
        now=now->next[getTreeN(str[i])];
    }
    if(now->end) return now;
    else return NULL;
}

void Fun_insert(enum Syn_Type ftype)
{
    FunTree *ft;
    FunParaNode *pa=0;
    ft=FunTree_find(now);
    if(ft)
    {
        error(Re_declared);
        return;
    }
    ft=FunTree_insert(now);
    switch(ftype)
    {
    case _Int:
        ft->type=_Type_Int;
        break;
    case _Void:
        ft->type=_Type_Void;
        break;
    default:
        error(Fun_Type_NotMatched);
        return;
    }
    Stack_p++;
    FunTreeStack[Stack_p]=ft;
    WordTree_reset(&WordTreeStack[Stack_p]);
    while(1)
    {
        if(!getNextSyn_Noend()) return;
        if(syn==_Br_Sm_Right)
        {
            if(!getNextSyn_Noend()) return;
            break;
        }
        if(syn==_Void)
        {
            if(!getNextSyn_Noend()) return;
            if(syn!=_Br_Sm_Right)
                error(Exp_Br_Sm_Right);
            else if(!getNextSyn_Noend()) return;
            break;
        }
        if(syn==_Int)
        {
            if(!pa)
            {
                ft->para=(FunParaNode*)malloc(sizeof(FunParaNode));
                pa=ft->para;
            }
            else
            {
                pa->next=(FunParaNode*)malloc(sizeof(FunParaNode));
                FunParaNode_init(pa->next);
                pa=pa->next;
            }
            pa->type=_Type_Int;
            if(!getNextSyn_Noend()) return;
            if(syn!=_Id)
                error(Exp_Id);
            else
                Word_insert(now,_Type_Int);
        }
        if(!getNextSyn_Noend()) return;
        if(syn==_Br_Sm_Right)
        {
            if(!getNextSyn_Noend()) return;
            break;
        }
        if(syn!=_Comma)
        {
            error(Exp_Comma);
            return;
        }
    }
    if(syn!=_Br_Big_Left)
    {
        error(Exp_Br_Big_Left);
        return;
    }
    ReadExprssions();
    Stack_p--;
}

void WordTree_reset(WordTree *a)
{
    int i;
    for(i=0;i<TreeNextN;i++)
        if(a->next[i])
        {
            WordTree_reset(a->next[i]);
            a->next[i]=0;
        }
    a->end=0;
    a->num=0;
}

WordTree* WordTree_find(WordTree *head,char *str)
{
    int len=strlen(str);
    WordTree *now=head;
    for(int i=0; i<len; i++)
    {
        if(!now->next[getTreeN(str[i])])
            return NULL;
        now=now->next[getTreeN(str[i])];
    }
    if(now->end) return now;
    else return NULL;
}

WordTree* WordTree_insert(char *str)
{
    int len=strlen(str);
    WordTree *now=&WordTreeStack[Stack_p];
    for(int i=0; i<len; i++)
    {
        if(!now->next[getTreeN(str[i])])
        {
            now->next[getTreeN(str[i])]=(WordTree*)malloc(sizeof(WordTree));
            WordTree_init(now->next[getTreeN(str[i])]);
        }
        now=now->next[getTreeN(str[i])];
    }
    now->end=1;
    return now;
}

void Word_insert(char *str,enum Type dtype,int num)
{
    WordTree *now;
    now=WordTree_insert(str);
    now->type=dtype;
    if(dtype==_Type_Int_arr)
        now->num=num;
}

WordTree* WordFind(char *str)
{
    int i;
    WordTree *tmp;
    for(i=Stack_p;i>=0;i--)
    {
        tmp=WordTree_find(&WordTreeStack[i],str);
        if(tmp)
            return tmp;
    }
    return NULL;
}

WordTree* WordFind_now(char *str)
{
    WordTree *tmp;
    tmp=WordTree_find(&WordTreeStack[Stack_p],str);
    if(tmp)
        return tmp;
    return NULL;
}
