#ifndef _INFO_H_
#define _INFO_H_

#include "includes.h"

namespace zhcosin
{

using namespace std;


void showBanner();				
void showNote();				
void showPrompt();			
void showHelpInfo(const string &cmd);			
void showProgramInfo(const string &cmd);			
void showOperatorsInfo(const string &cmd);		
void showFunctionsInfo(const string &cmd);		
void CutSpaceInString(string& str);		
}

#endif // _INFO_H_
