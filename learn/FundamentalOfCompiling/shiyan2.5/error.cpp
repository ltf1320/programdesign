#include "shiyan2.h"

extern char row[Max_row_num+HEADSPACE];//the present row of inputfile
extern int row_num;
extern int now_row;
extern char ch;
extern char now[Max_word_length+HEADSPACE];//the present word or number or symbol
extern FILE* OUTPUT_FILE;
int Error_Num;

void error(enum ERROR_TYPE et)
{
    if(et>Num_Toolarge)
        Error_Num++;
    fprintf(OUTPUT_FILE,"\n");
    switch(et)
    {
    case Id_TooLong:
        fprintf(OUTPUT_FILE,"Warning in row %d: the identifier is too long\n",now_row);
        break;
    case Num_Toolarge:
        fprintf(OUTPUT_FILE,"Warning in row %d: the number is too large\n",now_row);
        break;
    case Id_NoFound:
        fprintf(OUTPUT_FILE,"Error in row %d: stray %c in program\n",now_row,ch);
        break;
    case Exp_declaration:
        fprintf(OUTPUT_FILE,"Error in row %d: expected declaration\n",now_row);
        break;
    case Exp_Id:
        fprintf(OUTPUT_FILE,"Error in row %d: expected Identifier\n",now_row);
        break;
    case Exp_Constant:
        fprintf(OUTPUT_FILE,"Error in row %d: expected constant\n",now_row);
        break;
    case Exp_Sem:
        fprintf(OUTPUT_FILE,"Error in row %d: expected ';'\n",now_row);
        break;
    case Unexp_Sem:
        fprintf(OUTPUT_FILE,"Error in row %d: unexpected ';'\n",now_row);
        break;
    case Exp_Br_Sq_Right:
        fprintf(OUTPUT_FILE,"Error in row %d: expected ']'\n",now_row);
        break;
    case Exp_Comma:
        fprintf(OUTPUT_FILE,"Error in row %d: expected ','\n",now_row);
        break;
    case Exp_Br_Sm_Left:
        fprintf(OUTPUT_FILE,"Error in row %d: expected '('\n",now_row);
        break;
    case Exp_Digit:
        fprintf(OUTPUT_FILE,"Error in row %d: expected digit\n",now_row);
        break;
    case Unexp_End:
        fprintf(OUTPUT_FILE,"Error in row %d: unexpected end\n",now_row);
        break;
    case Re_declared:
        fprintf(OUTPUT_FILE,"Error in row %d: %s is declared\n",now_row,now);
        break;
    case Void_Variable:
        fprintf(OUTPUT_FILE,"Error in row %d: cannot define void variable(s)",now_row);
        break;
    case Word_NoFound:
        fprintf(OUTPUT_FILE,"Error in row %d: variable %s is not declared\n",now_row,now);
        break;
    case Use_var_to_arr:
        fprintf(OUTPUT_FILE,"Error in row %d: %s is declared variable but used as array\n",now_row,now);
        break;
    case Use_arr_to_var:
        fprintf(OUTPUT_FILE,"Error in row %d: %s is declared array but used as variable\n",now_row,now);
        break;
    case Global_Return:
        fprintf(OUTPUT_FILE,"Error in row %d: return at no function\n",now_row);
        break;
    case Fun_NoFound:
        fprintf(OUTPUT_FILE,"Error in row %d: function %s is not declared\n",now_row,now);
        break;
    case Exp_Br_Sm_Right:
        fprintf(OUTPUT_FILE,"Error in row %d: expected ')'\n",now_row);
        break;
    case Exp_Br_Big_Left:
        fprintf(OUTPUT_FILE,"Error in row %d: expected '{'\n",now_row);
        break;
    case Exp_Br_Big_Right:
        fprintf(OUTPUT_FILE,"Error in row %d: expected '}'\n",now_row);
        break;
    case Fun_Type_NotMatched:
        fprintf(OUTPUT_FILE,"Error in row %d: the return type of function is not int or void\n",now_row);
        break;
    case Fun_InFun:
        fprintf(OUTPUT_FILE,"Error in row %d: define function in function\n",now_row);
        break;
    case Eql_Void:
    case Com_Void:
    case Op_Void:
        fprintf(OUTPUT_FILE,"Error in row %d: the expression after operator is void\n",now_row);
        break;
    case Br_Void:
        fprintf(OUTPUT_FILE,"Error in row %d: the expression between brackes is void\n",now_row);
        break;
    case Eql_DigitOrFunction:
        fprintf(OUTPUT_FILE,"Error in row %d: assign to digit or function\n",now_row);
        break;
    case Fun_Return:
        fprintf(OUTPUT_FILE,"Error in row %d: the return type is not matched\n",now_row);
        break;
    case Fun_ParaNoMatch:
        fprintf(OUTPUT_FILE,"Error in row %d: the function type is not matched\n",now_row);
        break;
    case Invalid_Assignment:
        fprintf(OUTPUT_FILE,"Error in row %d: invalid assignment\n",now_row);
        break;
    case Unexp_err:
    default:
        fprintf(OUTPUT_FILE,"Error int row %d: unexpected error\n",now_row);
    }
    Suojin();
}

