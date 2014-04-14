#include "shiyan2.h"
extern char now[Max_word_length+HEADSPACE];//the present word or number or symbol
extern enum Syn_Type syn;
extern FunTree *FunTreeStack[Max_Stack_num];
extern FILE* OUTPUT_FILE;
extern int Stack_p;
int NeedSem;
extern int end;
void JudgePara(FunParaNode *para)
{
    int tNDS=NeedSem;
    while(1)
    {
        if(!getNextSyn_Noend()) return;
        if(syn==_Br_Sm_Right) break;
        NeedSem=0;
        if(!para)
        {
            error(Fun_ParaNoMatch);
            break;
        }
        if(expression()!=para->type)
            error(Fun_ParaNoMatch);
        if(para)
            para=para->next;
        else error(Fun_ParaNoMatch);
        if(syn==_Br_Sm_Right) break;
        if(syn!=_Comma) error(Exp_Comma);
    }
    if(para) error(Fun_ParaNoMatch);
    NeedSem=tNDS;
//   if(!getNextSyn_Noend()) return;
    if(syn!=_Br_Sm_Right)
    {
        error(Exp_Br_Sm_Right);
    }
    else getNextSyn();
}
enum Type NextExpression()
{
    enum Type rType;
    if(!getNextSyn_Noend()) return _Type_Void;
    rType=expression();
    return rType;
}

enum Type judgeNext()
{
    enum Type rType;
    switch(syn)
    {
    case _Eql:
        rType=NextExpression();
        if(rType==_Type_Void)
            error(Eql_Void);
        break;
    case _Compare:
        rType=NextExpression();
        if(rType==_Type_Void)
            error(Com_Void);
        break;
    case _Op_Add:
    case _Op_Mul:
        rType=NextExpression();
        if(rType==_Type_Void)
            error(Op_Void);
        break;
    case _Sem:
        if(!NeedSem) error(Unexp_Sem);
        else getNextSyn();
        break;
    default:
        if(NeedSem) error(Exp_Sem);
        break;
    }
    return rType;
}

void ReadExprssions()
{
    fprintf(OUTPUT_FILE,"\n");
    if(!getNextSyn_Noend()) return;
    while(1)
    {
        NeedSem=1;
        expression();
        if(end) return;
        if(syn==_Br_Big_Right) break;
    }
}



enum Type expression()
{
    WordTree* wdt;
    FunTree* ft;
    char tmp[Max_word_length];
    int tNDS,len;
    enum Type rType;
    switch(syn)
    {
    case _Id:
        if(!getNextSyn_Noend())
            return _Type_Void;
        switch(syn)
        {
        case _Br_Sq_Left:// array
            wdt=WordFind(now);
            if(wdt==NULL)
                error(Word_NoFound);
            if(wdt&&wdt->type!=_Type_Int_arr)
                error(Use_var_to_arr);
            if(!getNextSyn_Noend()) return _Type_Void;
            tNDS=NeedSem;
            NeedSem=0;
            rType=expression();
            NeedSem=tNDS;
            if(rType==_Type_Void)
                error(Br_Void);
            if(syn!=_Br_Sq_Right)
                error(Exp_Br_Sq_Right);
            else if(!getNextSyn_Noend()) return _Type_Int;
            judgeNext();
            rType=_Type_Int;
            break;
        case _Eql: //assignment
            wdt=WordFind(now);
            if(wdt==NULL)
                error(Word_NoFound);
            if(wdt&&wdt->type!=_Type_Int)
                error(Use_arr_to_var);
            rType=NextExpression();
            if(rType==_Type_Void)
                error(Eql_Void);
            ExplainGrammar(_AssignMent);
            break;
        case _Compare:
            wdt=WordFind(now);
            if(wdt==NULL)
                error(Word_NoFound);
            if(wdt&&wdt->type!=_Type_Int)
                error(Use_arr_to_var);
            rType=NextExpression();
            if(rType==_Type_Void)
                error(Com_Void);
            ExplainGrammar(_CompareMent);
            break;
        case _Op_Add:
        case _Op_Mul:
            wdt=WordFind(now);
            if(wdt==NULL)
                error(Word_NoFound);
            if(wdt&&wdt->type!=_Type_Int)
                error(Use_arr_to_var);
            rType=NextExpression();
            if(rType==_Type_Void)
                error(Op_Void);
            break;
        case _Br_Sm_Left: //function
            ft=FunTree_find(now);
            if(ft==NULL)
            {
                rType=_Type_Void;
                error(Fun_NoFound);
                while(getNextSyn_Noend())
                    if(syn==_Br_Sm_Right)
                        break;
            }
            else
            {
                JudgePara(ft->para);
                rType=ft->type;
            }
//           if(getNextSyn_Noend()) return rType;
            judgeNext();
            ExplainGrammar(_Fun_Call);
            break;
        case _Sem: //end expression
            wdt=WordFind(now);
            if(wdt)
                rType=wdt->type;
            else
            {
                error(Word_NoFound);
                rType=_Type_Void;
            }
            if(!NeedSem) error(Unexp_Sem);
            else getNextSyn();
            break;
        default:
            if(NeedSem)error(Exp_Sem);
            wdt=WordFind(now);
            if(wdt)
                rType=wdt->type;
            else
            {
                error(Word_NoFound);
                rType=_Type_Void;
            }
            break;
        }
        break;
    case _Digit:
        if(!getNextSyn_Noend()) return _Type_Int;
        rType=_Type_Int;
        judgeNext();
        break;
    case _If:
        if(!getNextSyn_Noend()) return _Type_Void;
        if(syn!=_Br_Sm_Left)
            error(Exp_Br_Sm_Left);
        else if(!getNextSyn_Noend()) return _Type_Void;
        tNDS=NeedSem;
        NeedSem=0;
        rType=expression();
        NeedSem=tNDS;
        if(rType==_Type_Void)
            error(Br_Void);
        if(syn!=_Br_Sm_Right)
            error(Exp_Br_Sm_Right);
        else if(!getNextSyn_Noend()) return _Type_Void;
        if(syn==_Br_Big_Left)
        {
            ReadExprssions();
            if(!getNextSyn_Noend()) return _Type_Void;
        }
        else
        {
            expression();
            //          if(!getNextSyn_Noend()) return _Type_Void;
        }
        if(syn==_Else)
        {
            if(!getNextSyn_Noend()) return _Type_Void;
            if(syn==_Br_Big_Left)
            {
                ReadExprssions();
                if(!getNextSyn_Noend()) return _Type_Void;
            }
            else
            {
                expression();
//                if(!getNextSyn_Noend()) return _Type_Void;
            }
        }
        ExplainGrammar(_IfMent);
        rType=_Type_Void;
        break;
    case _While:
        if(!getNextSyn_Noend()) return _Type_Void;
        if(syn!=_Br_Sm_Left)
            error(Exp_Br_Sm_Left);
        else if(!getNextSyn_Noend()) return _Type_Void;
        tNDS=NeedSem;
        NeedSem=0;
        rType=expression();
        NeedSem=tNDS;
        if(rType==_Type_Void)
            error(Br_Void);
        if(syn!=_Br_Sm_Right)
            error(Exp_Br_Sm_Right);
        else if(!getNextSyn_Noend()) return _Type_Void;
        if(syn==_Br_Big_Left)
        {
            ReadExprssions();
            if(!getNextSyn_Noend()) return _Type_Void;
        }
        else expression();
        rType=_Type_Void;
        ExplainGrammar(_RepetitionMent);
        break;
    case _Return:
        if(!getNextSyn_Noend()) return _Type_Void;
        rType=expression();
        if(Stack_p==0)
            error(Global_Return);
        else if(rType!=FunTreeStack[Stack_p]->type)
            error(Fun_Return);
        rType=_Type_Void;
        ExplainGrammar(_ReturnMent);
        break;
    case _Int: //local defination
        if(!getNextSyn_Noend())
            return _Type_Void;
        if(syn!=_Id)
            error(Exp_Id);
        if(!getNextSyn_Noend())
            return _Type_Void;
        switch(syn)
        {
        case _Sem:
            if(WordFind(now))
                error(Re_declared);
            else
                Word_insert(now,_Type_Int);
            if(!getNextSyn_Noend()) return _Type_Void;
            ExplainGrammar(_Local_Var_Declare);
            break;
        case _Br_Sq_Left:
            if(WordFind_now(now))
            {
                error(Re_declared);
                do
                {
                    if(!getNextSyn_Noend())
                        return _Type_Void;
                }
                while(syn!=_Br_Sq_Right);
            }
            else
            {
                strcpy(tmp,now);
                if(!getNextSyn_Noend())
                    return _Type_Void;
                if(syn!=_Digit)
                    error(Exp_Constant);
                else
                {
                    sscanf(now,"%d",&len);
                    Word_insert(tmp,_Type_Int_arr,len);
                    if(!getNextSyn_Noend())
                        return _Type_Void;
                    if(syn!=_Br_Sq_Right)
                        error(Exp_Br_Sq_Right);
                }
                if(!getNextSyn_Noend())
                    return _Type_Void;
                if(syn!=_Sem)
                    error(Exp_Sem);
                else getNextSyn();
                ExplainGrammar(_Local_Arr_Declare);
            }
            break;
        case _Br_Sm_Left:
            error(Fun_InFun);
            while(syn!=_Br_Sm_Right)
                if(!getNextSyn_Noend()) return _Type_Void;
            break;
        default :
            error(Exp_Sem);
            break;
        }
        break;
    case _Br_Sm_Left:
        if(!getNextSyn_Noend()) return _Type_Void;
        tNDS=NeedSem;
        NeedSem=0;
        rType=expression();
        NeedSem=tNDS;
        if(rType!=_Type_Int)
            error(Br_Void);
        if(syn!=_Br_Sm_Right)
            error(Exp_Br_Sm_Right);
        else if(!getNextSyn_Noend()) return _Type_Void;
        judgeNext();
        break;
    default:
        error(Unexp_err);
        getNextSyn_Noend();
        rType=_Type_Void;
    }
    return rType;
}


