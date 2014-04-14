#include "shiyan2.h"
extern char now[Max_word_length+HEADSPACE];//the present word or number or symbol
extern enum Syn_Type syn;
extern FunTree* FunPoint[Max_Stack_num];
extern int Fun_Num;
extern FILE* OUTPUT_FILE;
extern int Stack_p;
int NeedSem;
extern int end;
extern int Grammar_Level;

enum Grammar_Type NowGType;

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
enum Type NextExpression(int GtNext)
{
    enum Type rType;
    if(!getNextSyn_Noend()) return _Type_Void;
    rType=expression(GtNext);
    return rType;
}

enum Type judgeNext(int GtNext)
{
    enum Type rType;
    switch(syn)
    {
    case _Compare:
        rType=NextExpression(GtNext);
        if(rType==_Type_Void)
            error(Com_Void);
        break;
    case _Op_Add:
    case _Op_Mul:
        rType=NextExpression(GtNext);
        if(rType==_Type_Void)
            error(Op_Void);
        break;
    case _Sem:
        ExplainGrammar(NowGType);
        if(!NeedSem) error(Unexp_Sem);
        else if(GtNext) getNextSyn();
        break;
    default:
        if(NeedSem) error(Exp_Sem);
        break;
    }
    return rType;
}

void ReadExprssions(enum Grammar_Type GType)
{
    PutLine();
    Suojin();
    if(!getNextSyn_Noend()) return;
    while(1)
    {
        NeedSem=1;
        NowGType=_EmptyMent;
        expression();
        if(end) return;
        if(syn==_Br_Big_Right) break;
    }
    Grammar_Level--;
    ExplainGrammar(GType);

}

enum Type ReadAnExpression(enum Grammar_Type GType)
{
    enum Type rType;
    //  if(!getNextSyn_Noend()) return _Type_Void;
    NowGType=_EmptyMent;
    rType=expression(0);
    Grammar_Level--;
    ExplainGrammar(GType);
    getNextSyn();
    return rType;
}

enum Type expression(int GtNext)
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
            rType=expression(GtNext);
            NeedSem=tNDS;
            if(rType==_Type_Void)
                error(Br_Void);
            if(syn!=_Br_Sq_Right)
                error(Exp_Br_Sq_Right);
            else if(!getNextSyn_Noend()) return _Type_Int;
            if(syn==_Eql)
            {
                if(!getNextSyn_Noend()) return _Type_Void;
                NowGType=_AssignMent;
                rType=expression(GtNext);
                if(rType==_Type_Void)
                    error(Eql_Void);
  //              ExplainGrammar(_AssignMent);
            }
            else judgeNext(GtNext);
            rType=_Type_Int;
            break;
        case _Eql: //assignment
            wdt=WordFind(now);
            if(wdt==NULL)
                error(Word_NoFound);
            if(wdt&&wdt->type!=_Type_Int)
                error(Use_arr_to_var);
            NowGType=_AssignMent;
            rType=NextExpression(GtNext);
            if(rType==_Type_Void)
                error(Eql_Void);
            break;
        case _Compare:
            wdt=WordFind(now);
            if(wdt==NULL)
                error(Word_NoFound);
            if(wdt&&wdt->type!=_Type_Int)
                error(Use_arr_to_var);
            //        NowGType=_CompareMent;
            rType=NextExpression(GtNext);
            if(rType==_Type_Void)
                error(Com_Void);
            break;
        case _Op_Add:
        case _Op_Mul:
            wdt=WordFind(now);
            if(wdt==NULL)
                error(Word_NoFound);
            if(wdt&&wdt->type!=_Type_Int)
                error(Use_arr_to_var);
            rType=NextExpression(GtNext);
            if(rType==_Type_Void)
                error(Op_Void);
            break;
        case _Br_Sm_Left: //function
            if(NowGType==_EmptyMent)
                NowGType=_Fun_Call;
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
            if(syn==_Eql)
            {
                error(Invalid_Assignment);
            }
            else judgeNext(GtNext);
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
            ExplainGrammar(NowGType);
            if(!NeedSem) error(Unexp_Sem);
            else if(GtNext) getNextSyn();
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
        if(syn==_Eql)
        {
            error(Invalid_Assignment);
        }
        else judgeNext(GtNext);
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
        PutLine();
        Grammar_Level++;
        if(syn!=_Br_Sm_Right)
            error(Exp_Br_Sm_Right);
        else{
            Suojin();
            if(!getNextSyn_Noend()) return _Type_Void;
        }
        if(syn==_Br_Big_Left)
        {
            ReadExprssions(_IfMent);
            if(!getNextSyn_Noend()) return _Type_Void;
        }
        else
        {
            ReadAnExpression(_IfMent);
  //          if(!getNextSyn_Noend()) return _Type_Void;
        }
  //      Grammar_Level--;
        if(syn==_Else)
        {
            PutLine();
            Grammar_Level++;
            Suojin();
            if(!getNextSyn_Noend()) return _Type_Void;
            if(syn==_Br_Big_Left)
            {
                ReadExprssions(_IfMent);
                if(!getNextSyn_Noend()) return _Type_Void;
            }
            else
            {
                ReadAnExpression(_IfMent);
//                if(!getNextSyn_Noend()) return _Type_Void;
            }
    //        Grammar_Level--;
        }
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
        Grammar_Level++;
        if(syn!=_Br_Sm_Right)
            error(Exp_Br_Sm_Right);
        else{
            Suojin();if(!getNextSyn_Noend()) return _Type_Void;
        }
        if(syn==_Br_Big_Left)
        {
            ReadExprssions(_RepetitionMent);
            if(!getNextSyn_Noend()) return _Type_Void;
        }
        else ReadAnExpression(_RepetitionMent);
   //     Grammar_Level--;
        rType=_Type_Void;
     //   ExplainGrammar(_RepetitionMent);
        break;
    case _Return:
        if(!getNextSyn_Noend()) return _Type_Void;
        NowGType=_ReturnMent;
        rType=expression(GtNext);
        if(Stack_p==0)
            error(Global_Return);
        else if(rType!=FunPoint[Fun_Num]->type)
            error(Fun_Return);
        rType=_Type_Void;
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
            ExplainGrammar(_Local_Var_Declare);
            if(!getNextSyn_Noend()) return _Type_Void;
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
                ExplainGrammar(_Local_Arr_Declare);
                if(syn!=_Sem)
                    error(Exp_Sem);
                else if(GtNext) getNextSyn();
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
        rType=expression(GtNext);
        NeedSem=tNDS;
        if(rType!=_Type_Int)
            error(Br_Void);
        if(syn!=_Br_Sm_Right)
            error(Exp_Br_Sm_Right);
        else if(!getNextSyn_Noend()) return _Type_Void;
        if(syn==_Eql)
        {
            error(Invalid_Assignment);
        }
        else judgeNext(GtNext);
        break;
    default:
        error(Unexp_err);
        getNextSyn_Noend();
        rType=_Type_Void;
    }
    return rType;
}


