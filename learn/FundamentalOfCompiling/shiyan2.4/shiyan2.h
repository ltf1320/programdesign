#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _SHIYAN2
#define _SHIYAN2

#define Max_row_num 1000
#define Max_word_length 20
#define Key_words_num 6
#define FILEEOF -1
#define HEADSPACE 10
#define Max_Stack_num 5
#define TreeNextN 60
#define CifaNum 23
enum ERROR_TYPE
{
    Id_TooLong,
    Id_NoFound,
    Num_Toolarge,
    Exp_declaration,
    Exp_Id,
    Exp_Constant,
    Exp_Br_Sq_Right,
    Exp_Comma,
    Exp_Digit,
    Exp_Br_Sm_Right,
    Exp_Br_Big_Right,
    Exp_Br_Sm_Left,
    Exp_Br_Big_Left,
    Exp_Sem,
    Unexp_End,
    Unexp_Sem,
    Re_declared,
    Eql_Void,
    Eql_DigitOrFunction,
    Com_Void,
    Op_Void,
    Br_Void,
    Fun_NoFound,
    Word_NoFound,
    Fun_Return,
    Fun_Type_NotMatched,
    Void_Variable,
    Use_var_to_arr,
    Use_arr_to_var,
    Fun_ParaNoMatch,
    Unexp_err,
    Fun_InFun,
    Global_Return,
    Invalid_Assignment
};


enum Syn_Type
{
    _Int=0,
    _Void,
    _If,
    _Else,
    _Return,
    _While,
    _Id,
    _Digit,
    _Op_Mul,
    _Op_Add,
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

enum Grammar_Type
{
    _Global_Var_Declare=0,
    _Global_Arr_Declar,
    _Fun_Declare,
    _AssignMent,
    _CompareMent,
    _IfMent,
    _RepetitionMent,
    _ReturnMent,
    _Local_Var_Declare,
    _Local_Arr_Declare,
    _Fun_Call,
    _EmptyMent
};

enum Type
{
    _Type_Int,
    _Type_Int_arr,
    _Type_Void
};



struct WordTree
{
    WordTree* next[TreeNextN];
    bool end;
    enum Type type;
    int num;
};
void WordTree_init(WordTree *a);
void WordTree_reset(WordTree *a);
struct FunParaNode
{
    enum Type type;
    FunParaNode *next;
};
void FunParaNode_init(FunParaNode *a);

struct FunTree
{
    FunTree* next[TreeNextN];
    bool end;
    enum Type type;
    FunParaNode *para;
};
void FunTree_init(FunTree *a);


int getNextSyn();
int getNextSyn_Noend();
void error(enum ERROR_TYPE et);
void IO();
void Word_insert(char *str,enum Type dtype,int num=0);
WordTree* WordTree_insert(char *str);
WordTree* WordTree_find(char *str);
void Fun_insert(enum Syn_Type ftype);
FunTree* FunTree_find(char *str);
FunTree* FunTree_insert(char *str);
WordTree* WordFind(char *str);
WordTree* WordFind_now(char *str);
void grammar();
void global_declare(enum Syn_Type deType);
enum Type expression();
enum Type ReadFunction();
void ReadExprssions(enum Grammar_Type GType);
enum Type ReadAnExpression(enum Grammar_Type GType);
void init();
enum Type NextExpression();
void ExplainGrammar(enum Grammar_Type gt);
void CifaOutput();
int getNextSyn_Noend_NoOut();
void PutLine();
void PrintTable();
#endif
