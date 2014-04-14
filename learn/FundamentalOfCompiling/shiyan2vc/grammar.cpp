#include "shiyan2.h"

extern char now[Max_word_length+HEADSPACE];//the present word or number
extern enum Syn_Type syn;
extern int Error_Num;
void global_declare(enum Syn_Type deType)
{
    int len;
    if(!getNextSyn_Noend())
        return;
    if(syn!=_Id)
        error(Exp_Id);
    if(!getNextSyn_Noend())
        return;
    switch(syn)
    {
    case _Sem:
        if(deType==_Void)
            error(Void_Variable);
        else
        {
            if(WordFind(now))
                error(Re_declared);
            else
                Word_insert(now,_Type_Int);
        }
        break;
    case _Br_Sq_Left:
        if(deType==_Void)
            error(Void_Variable);
        if(WordFind(now))
        {
            error(Re_declared);
            do
            {
                if(!getNextSyn_Noend())
                    return;
            }
            while(syn!=_Br_Sq_Right);
        }
        else
        {
            if(!getNextSyn_Noend())
                return;
            if(syn!=_Digit)
                error(Exp_Constant);
            else
            {
                sscanf(now,"%d",&len);
                Word_insert(now,_Type_Int_arr,len);
                if(!getNextSyn_Noend())
                    return;
                if(syn!=_Br_Sq_Right)
                    error(Exp_Br_Sq_Right);
            }
            if(!getNextSyn_Noend())
                return;
            if(syn!=_Sem)
                error(Exp_Sem);
        }
        break;
    case _Br_Sm_Left:
        Fun_insert(deType);
        break;
    default :
        error(Exp_Sem);
        break;
    }
}

void grammar()
{
    while(1)
    {
        if(!getNextSyn()) break;
        switch(syn)
        {
        case _Int:
        case _Void:
            global_declare(syn);
            break;
        default:
            error(Exp_declaration);
        }
    }
    if(Error_Num==0)
        printf("analyse successed!\n");
}

