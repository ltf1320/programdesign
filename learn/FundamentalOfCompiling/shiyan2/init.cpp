#include "shiyan2.h"
extern WordTree WordTreeStack[Max_Stack_num];
extern FunTree *FunTreeStack[Max_Stack_num];
extern int Stack_p;
extern FunTree FunTreeHead;

void init()
{
    char tmp[10];
    Stack_p=0;
    WordTree_init(&WordTreeStack[0]);
    FunTreeStack[0]=NULL;
    FunTree *ft;
    strcpy(tmp,"input");
    ft=FunTree_insert(tmp);
    ft->type=_Type_Int;
    strcpy(tmp,"output");
    ft=FunTree_insert(tmp);
    ft->type=_Type_Void;
    ft->para=(FunParaNode*)malloc(sizeof(FunParaNode));
    ft->para->type=_Type_Int;
    ft->para->next=0;
}
