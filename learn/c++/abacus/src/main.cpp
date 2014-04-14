#include <cstdio>
#include <iostream>
#include <iomanip>
#include "Express.h"
#include "ExpressPart.h"
#include "Logger.h"
#include "parser.h"
#include "info.h"
#include "Session.h"
#include "UserFunctor.h"
#include "shell.h"

using namespace zhcosin;
using namespace std;

typedef void (*pfDo)(const string &cmd);

enum CmdType
{
	expStr,
	defVariable,
	defFunction,
	undefVariable,
	assignVariable,
	undefFunction,
	showUserFun,
	getHelpInfo,
	getProgramInfo,
	getOptsInfo,
	getFunsInfo,
	quit
};

bool BracketsIsMatch(const char *str)
{
	if (str == NULL || *str == '\0')
		return true;

	int level = 0;
	for (const char *p = str; *p != '\0'; p++)
	{
		if (*p == '(')
			level++;
		else if (*p == ')')
		{
			if (--level < 0)
				return false;
		}
	}

	return level == 0;
}

bool IsIdentifier(const char *str)
{
	if (str == NULL)
		return false;

	if (isalpha(*str) == 0 && *str != '_')
		return false;

	for(const char *p = str + 1; *p != '\0'; p++)
	{
		if (*p == '_' || isalnum(*p) != 0)
			continue;
		else
			return false;
	}

	return true;
}

bool IsDefVariableCmd(const string &cmd)
{
	char buf[256];
	int i = sscanf(cmd.c_str(), "var%*[ ]%[^,=]", buf);
	if (i != 1)
		return false;

	return true;
}

bool IsUndefCmd(const string &cmd)
{
	char buf[256];
	int i = sscanf(cmd.c_str(), "undef%*[ ]%s", buf);
	if (i != 1)
	{
		return false;
	}
	
	return true;
}

bool IsAssignVariableCmd(const string &cmd)
{
	char buf[256];
	int i = sscanf(cmd.c_str(), "%s", buf);
	if (i != 1)
		return false;

	return strcmp(buf, "let") == 0;
}
bool IsDefFunctionCmd(const string &cmd)
{
	char funName[64];
	char args[64];
	string mode = "func%*[ ]%[^(](%[^)]%*[^=]=%*s";
	int i = sscanf(cmd.c_str(), mode.c_str(), funName, args);
	if (i != 2)
		return false;

	return true;
}

bool IsShowUserFun(const string &cmd)
{
	char buf[64];
	int i = sscanf(cmd.c_str(), "show%*[ ]%s", buf);
	if (i != 1)
	{
		return false;
	}
	
	return true;
}

int GetCmdType(const string &cmd)
{
	if (cmd=="h"||cmd=="help") 
		return getHelpInfo;
	else if (cmd=="p"||cmd=="program") 
		return getProgramInfo;
	else if (cmd=="lo"||cmd=="list operators") 
		return getOptsInfo;
	else if (cmd=="lf"||cmd=="list functions") 
		return getFunsInfo;
	else if (cmd=="q"||cmd=="quit") 
		return quit;
	else if (IsDefVariableCmd(cmd))
		return defVariable;
	else if (IsAssignVariableCmd(cmd))
		return assignVariable;
	else if (IsDefFunctionCmd(cmd))
		return defFunction;
	else if (IsUndefCmd(cmd))
		return undefVariable;
	else if (IsShowUserFun(cmd))
		return showUserFun;
	else 
		return expStr;
}


double Compute(const string &expression)
{
	Express a;	

	string logInfo = "====================================\n";
	logInfo += "Create a express with the string: ";
	logInfo += expression + "\n\n";
	LogService::GetInstance()->GetLogger()->WriteLog(logInfo);

	logInfo = "Begin word parse......\n";
	LogService::GetInstance()->GetLogger()->WriteLog(logInfo);

	if(0 != 
		a.WordParse(expression, Session::GetInstance()->GetUserVariables(), Session::GetInstance()->GetUserFunctions()))	
	{
		logInfo = "The express is destroyed for some error in word parse.\n\n";
		LogService::GetInstance()->GetLogger()->WriteLog(logInfo);

		a.Destroy();

		return -1;
	}
	else
	{
		logInfo = "Word parse complete.\n\n";
		LogService::GetInstance()->GetLogger()->WriteLog(logInfo);
	}

	logInfo = "Begin syntax parse......\n";
	LogService::GetInstance()->GetLogger()->WriteLog(logInfo);

	if(0 != a.SyntaxParse())	 
	{
		logInfo = "The express is destroyed for some error in syntax parse.\n\n";
		LogService::GetInstance()->GetLogger()->WriteLog(logInfo);

		a.Destroy();

		return -2;
	}
	else
	{
		logInfo = "Syntax parse complete.\n\n";
		LogService::GetInstance()->GetLogger()->WriteLog(logInfo);
	}

	logInfo = "Compute result......\n";
	LogService::GetInstance()->GetLogger()->WriteLog(logInfo);

	double value = a.Value();

	char buf[64];
	memset(buf, 0, 64);
	sprintf(buf, "%lf", value);
	logInfo = "The value of this express is: "; 
	logInfo += buf;
	logInfo += "\n\n";
	LogService::GetInstance()->GetLogger()->WriteLog(logInfo);

	return value;
}

void DoCompute(const string &cmd)
{
	ErrorManager::GetInstance()->ClearErrorInfo();

	double value = Compute(cmd);

	if (ErrorManager::GetInstance()->IsErrorOccur())
	{
		cout << " Error: " << ErrorManager::GetInstance()->GetLastError() << endl;
	}
	else
	{
		cout << " result = " << value << endl;
	}

	ErrorManager::GetInstance()->ClearErrorInfo();
}

bool AddUserVariable(const string &cmd)
{
	string errMsg;

	char buf[256];
	int i = sscanf(cmd.c_str(), "var%*[ ]%[^@]", buf);
	if (i != 1)
	{
		errMsg = string("It is not a right cmd of define user variables.");
		ErrorManager::GetInstance()->PushErrorInfo(errMsg);
		return false;
	}
	
	char *pBeg = buf;
	char *pEnd = buf;
	char *sepator = NULL;
	bool isLoop = true;
	char id[32];
	char id_temp[32];
	char valueStr[256];
	bool hasValue = false;
	double value = 0;
	ExpNumber *newVar = NULL;
	while (isLoop)
	{
		// split every variable define statement.
		bool hasFindAVariable = false;
		do 
		{
			char stament_buf[128];
			pEnd = strchr(pEnd + 1, ',');
			if (pEnd == NULL)
				break;
			strncpy(stament_buf, pBeg, pEnd - pBeg);
			stament_buf[pEnd - pBeg] = '\0';
			if (BracketsIsMatch(stament_buf))
				hasFindAVariable = true; // find ',' but not in function call.
		} while (!hasFindAVariable);
		
		
		if (pEnd == NULL)
		{
			pEnd = pBeg + strlen(pBeg);
			isLoop = false;
		}

		sepator = strchr(pBeg, '=');
		if (sepator != NULL && sepator >= pEnd)
			sepator = NULL;
		hasValue = (sepator != NULL);
		
		// parse out the name of the variable.
		size_t id_len = (sepator ? sepator : pEnd) - pBeg;
		strncpy(id_temp, pBeg, id_len);
		id_temp[id_len] = '\0';
		i = sscanf(id_temp, "%s", id);
		if (i != 1)
		{
			errMsg = string("\"") + string(id_temp) + "\" is not a legal name of a variable.";
			ErrorManager::GetInstance()->PushErrorInfo(errMsg);
			return false;
		}
		if (!IsIdentifier(id))
		{
			errMsg = string("\"") + string(id) + "\" is not a legal name of a variable.";
			ErrorManager::GetInstance()->PushErrorInfo(errMsg);
			return false;
		}

		if (sepator != NULL)
		{
			strncpy(valueStr, sepator + 1, pEnd - sepator - 1);
			valueStr[pEnd - sepator - 1] = '\0';
			
			// TODO: compute the value of 'valueStr'.
			value = Compute(valueStr); // If error occur.....how to process?
			hasValue = true;	
		}

		// Add user variable.
		if (hasValue)
		{
			newVar = new ExpNumber(id, value);
		} 
		else
		{
			newVar = new ExpNumber(id);
		}
		Session::GetInstance()->AddUserVariable(newVar);
		delete newVar;
		newVar = NULL;

		pBeg = pEnd + 1;
	}
	
	return true;
}

void DoAddUserVariable(const string &cmd)
{
	ErrorManager::GetInstance()->ClearErrorInfo();

	AddUserVariable(cmd);
	if (ErrorManager::GetInstance()->IsErrorOccur())
	{
		cout<< " Error: " << ErrorManager::GetInstance()->GetLastError() << endl;
	}
	else
	{
		cout << " Defined user variables, ok." << endl;
	}

	ErrorManager::GetInstance()->ClearErrorInfo();
}

bool SetValueOfVariable(const string &cmd)
{
	string errMsg;

	char buf[256];
	int i = sscanf(cmd.c_str(), "let%*[ ]%[^@]", buf);
	if (i != 1)
	{
		errMsg = string("It is not a right cmd of set value of variables.");
		ErrorManager::GetInstance()->PushErrorInfo(errMsg);
		return false;
	}

	char *pBeg = buf;
	char *pEnd = buf;
	char *sepator = NULL;
	bool isLoop = true;
	char id[32];
	char id_temp[32];
	char valueStr[256];
	double value = 0;
	ExpNumber *newVar = NULL;
	while (isLoop)
	{
		// split every variable define statement.
		bool hasFindAVariable = false;
		do 
		{
			char stament_buf[128];
			pEnd = strchr(pEnd + 1, ',');
			if (pEnd == NULL)
				break;
			strncpy(stament_buf, pBeg, pEnd - pBeg);
			stament_buf[pEnd - pBeg] = '\0';
			if (BracketsIsMatch(stament_buf))
				hasFindAVariable = true; // find ',' but not in function call.
		} while (!hasFindAVariable);


		if (pEnd == NULL)
		{
			pEnd = pBeg + strlen(pBeg);
			isLoop = false;
		}

		sepator = strchr(pBeg, '=');
		if (sepator == NULL || sepator >= pEnd)
		{
			char statment[128];
			strncpy(statment, pBeg, pEnd - pBeg);
			statment[pEnd - pBeg] = '\0';
			errMsg = string("The express \"") + statment + "\" is not a right format for set value of a variable.";
			ErrorManager::GetInstance()->PushErrorInfo(errMsg);
			return false;
		}

		// parse out the name of the variable.
		size_t id_len = sepator - pBeg;
		strncpy(id_temp, pBeg, id_len);
		id_temp[id_len] = '\0';
		i = sscanf(id_temp, "%s", id);
		if (i != 1)
		{
			errMsg = string("\"") + string(id_temp) + "\" is not a legal name of a variable.";
			ErrorManager::GetInstance()->PushErrorInfo(errMsg);
			return false;
		}
		if (!IsIdentifier(id))
		{
			errMsg = string("\"") + string(id) + "\" is not a legal name of a variable.";
			ErrorManager::GetInstance()->PushErrorInfo(errMsg);
			return false;
		}

		// create the value of variable.
		strncpy(valueStr, sepator + 1, pEnd - sepator - 1);
		valueStr[pEnd - sepator - 1] = '\0';
		value = Compute(valueStr); // If error occur.....how to process?

		// set user variable.
		if (!Session::GetInstance()->SetValueOfVariable(id, value))
		{
			errMsg = string("Failed to set the value of variable \"") + id + "\" to " + valueStr;
			ErrorManager::GetInstance()->PushErrorInfo(errMsg);
			return false;
		}

		pBeg = pEnd + 1;
	}

	return true;
}

void DoSetValueOfVariable(const string &cmd)
{
	ErrorManager::GetInstance()->ClearErrorInfo();

	SetValueOfVariable(cmd);

	if (ErrorManager::GetInstance()->IsErrorOccur())
	{
		cout << ErrorManager::GetInstance()->GetLastError() << endl;
	}
	else
	{
		cout << "Set value of variable, ok." << endl;
	}

	ErrorManager::GetInstance()->ClearErrorInfo();
}

bool AddUserFun(const string &cmd)
{
	string funName;
	vector<string> args;
	string funbody;
	string errMsg;

	// parse out the name and the arguments string of function.
	char argsBuf[64];
	char funBuf[64];
	char funBodyBuf[128];
	string mode = "func%*[ ]%[^ (]%*[ (]%[^)]%*[^=]=%[^@]";
	int i = sscanf(cmd.c_str(), mode.c_str(), funBuf, argsBuf, funBodyBuf);
	if (i != 3)
	{
		return false;
	}
	funName = funBuf;
	if (funName.empty() || !IsIdentifier(funName.c_str()))
	{
		errMsg = string("The name of the function \"") + funName + "\" is not legal.";
		ErrorManager::GetInstance()->PushErrorInfo(errMsg);
		return false;
	}

	// split format arguments from string.
	char argbuf[64];
	char *p = NULL;
	char *pBeg = argsBuf;
	char *pEnd = NULL;
	bool isLoop = true;
	while (isLoop)
	{
		while (*pBeg == ' ')
		{
			pBeg++;
		}
		
		pEnd = strchr(pBeg, ',');
		if (pEnd == NULL)
		{
			pEnd = argsBuf + strlen(argsBuf);
			isLoop = false;
		}

		i = sscanf(pBeg, "%[^ ,]", argbuf);
		if (i != 1)
		{
			return false;
		}
		
		if (!IsIdentifier(argbuf))
		{
			errMsg += string("The argument \"") + argbuf + "\" is not a legal identifier.";
			ErrorManager::GetInstance()->PushErrorInfo(errMsg);
			return false;
		}
		
		args.push_back(string(argbuf));	

		pBeg = pEnd + 1;	
	}

	// parse out the body of the function.
	funbody = funBodyBuf;
	CutSpaceInString(funbody);
	if (funbody.empty())
	{
		errMsg = "The body of the function \"" + funName + "\" is empty.";
		ErrorManager::GetInstance()->PushErrorInfo(errMsg);
		return false;
	}

	operator_functor *newUserFun = new user_functor(funName, funbody, args);

	ExpOperator *newOpt = new ExpOperator(funName, args.size(), 100, newUserFun);
	Session::GetInstance()->AddUserFunction(newOpt);
	delete newOpt;
	newOpt = NULL;

	return true;
}

void DoAddUserFun(const string &cmd)
{
	ErrorManager::GetInstance()->ClearErrorInfo();

	AddUserFun(cmd);
	if (ErrorManager::GetInstance()->IsErrorOccur())
	{
		cout << " Error: " << ErrorManager::GetInstance()->GetLastError() << endl;
	}
	else
	{
		cout << " Defined a user function, ok." << endl;
	}

	ErrorManager::GetInstance()->ClearErrorInfo();
}
string GetUserFunInfo(const string &cmd)
{
	string errMsg;
	char buf[64];
	sscanf(cmd.c_str(), "show%*[ ]%s",  buf);
	string info = Session::GetInstance()->GetFunString(string(buf));
	if (info.empty())
	{
		errMsg = string("The function \"") + buf + "\" has not be found.";
		ErrorManager::GetInstance()->PushErrorInfo(errMsg);
	}
	
	return info;
}

void DoShowUserFunInfo(const string &cmd)
{
	ErrorManager::GetInstance()->ClearErrorInfo();

	string info = GetUserFunInfo(cmd);

	if (ErrorManager::GetInstance()->IsErrorOccur())
	{
		cout << " Error: " << ErrorManager::GetInstance()->GetLastError() << endl;
	}
	else
	{
		cout << info << endl;
	}

	ErrorManager::GetInstance()->ClearErrorInfo();
}


void InitShell()
{
	Shell::GetInstance()->InsertMapItem(defVariable,	DoAddUserVariable	);
	Shell::GetInstance()->InsertMapItem(assignVariable,	DoSetValueOfVariable);
	Shell::GetInstance()->InsertMapItem(defFunction,	DoAddUserFun		);
	Shell::GetInstance()->InsertMapItem(undefVariable,	NULL				);
	Shell::GetInstance()->InsertMapItem(undefFunction,	NULL				);
	Shell::GetInstance()->InsertMapItem(getHelpInfo,	showHelpInfo		);
	Shell::GetInstance()->InsertMapItem(getProgramInfo,	showProgramInfo		);
	Shell::GetInstance()->InsertMapItem(getOptsInfo,	showOperatorsInfo	);
	Shell::GetInstance()->InsertMapItem(getFunsInfo,	showFunctionsInfo	);
	Shell::GetInstance()->InsertMapItem(expStr,			DoCompute			);
}

void UnInitShell()
{
	Shell::DestroyInstance();
}

int Init()
{
	LogService::GetInstance()->StartService();
	WordParseService::GetInstance()->StartService();
	SyntaxParseService::GetInstance()->StartService();
	ComputeService::GetInstance()->StartService();
	Session::GetInstance()->LoadPreDefindVariables();
	Session::GetInstance()->LoadPreDefindFunctions();
	InitShell();

	return 0;
}

int UnInit()
{
	LogService::GetInstance()->StopService();
	WordParseService::GetInstance()->StopService();
	SyntaxParseService::GetInstance()->StopService();
	ComputeService::GetInstance()->StopService();
	Session::GetInstance()->DestroyInstance();
	UnInitShell();

	return 0;
}


int main()
{
	showBanner();
	//showNote();

	Init();

	string cmd;
	char cmdbuf[128];
	int cmdType;
	pfDo callBackFun = NULL;
	while(true)
	{
		do
		{
			cout<<"> ";
			flush(cout);
			getline(cin, cmd);
			memset(cmdbuf, 0, 128);
			sscanf(cmd.c_str(), "%s", cmdbuf);	// Must have a non-blank character
		}while(strlen(cmdbuf) == 0);

		CutSpaceInString(cmd);

		cmdType = GetCmdType(cmd);
		if (cmdType == quit)
			break;

		callBackFun = Shell::GetInstance()->GetFun(cmdType);
		if (callBackFun != NULL)
		{
			callBackFun(cmd);
		}
	}

	UnInit();

	return 0;
}


