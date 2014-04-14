#include "info.h"

namespace zhcosin
{

using std::cout;
using std::endl;
using std::string;

void showBanner()
{
	//cout<<"                                                     "<<endl;
	//cout<<"   +-------------------< abacus >-------------------+"<<endl;
	//cout<<"   |                                                |"<<endl;
	//cout<<"   |   Abacus is a powerful, extensible, simple,    |"<<endl;
	//cout<<"   |          and open-source caculator.            |"<<endl;
	//cout<<"   |                                                |"<<endl;
	//cout<<"   |  Written by zhcosin, version 1.0, 2012-09-04.  |"<<endl;
	//cout<<"   |                                                |"<<endl;
	//cout<<"   +------------------------------------------------+"<<endl;
	//cout<<"                                                     "<<endl;
	cout << "Abacus 2 http://www.oschina.net/code/snippet_736932_13725" << endl;
	cout << "Copyright (C) 2013 zhcosin. All rights reserved." << endl;
}

void showNote()
{
	cout<<"[NOTE]: -> If you need any help, input 'h' or 'help' please."<<endl;
	cout<<"        -> If you want to exit this program, input 'q' or \n"
	      "           'quit' please."<<endl;
	cout<<endl;
}

void showPrompt()
{
	cout<<" /--------------------< help >--------------------\\"<<endl;
	cout<<"What do you want to do?"<<endl;

	cout<<"  <1>  a math expression"<<endl;
        cout<<"\t\t--> Compute a expression."<<endl;

	cout<<"  <2>  \"h\" or \"help\" "<<endl;
	cout<<"\t\t--> Show this information. "<<endl;

	cout<<"  <3>  \"p\" or \"program\" "<<endl;
	cout<<"\t\t--> Show information about abacus. "<<endl;

	cout<<"  <4>  \"lo\" or \"list operator\" "<<endl;
        cout<<"\t\t--> Get information about operator available. "<<endl;

	cout<<"  <5>  \"lf\" or \"list function\" "<<endl;
        cout<<"\t\t--> Get information about functions available. "<<endl;

	cout<<"  <6>  \"q\" or \"quit\" "<<endl;
	cout<<"\t\t--> Quit this program."<<endl;

	cout<<endl;

	showNote();

	cout<<"Please input your expression or command:"<<endl;
}

void showHelpInfo(const string &cmd)
{
	showPrompt();
}

void showProgramInfo(const string &cmd)
{
	cout<<" /------------------< about me >------------------\\"<<endl;

	cout<<"+ Abacus is a powerful, extensible, simple, and open source caculator."<<endl;
	cout<<"+ Written by zhcosin in 2012-09-04, and the current version is 1.0."<<endl;
	cout<<"+ Welcome to use this caculator in your work, and I will glad that"<<endl;
	cout<<"  you report some bugs in this program to me."<<endl;
	cout<<"+ For more information, you can visit the page:"<<endl;
        cout<<"               www.oschina.net/code/snippet_736932_13725"<<endl;
	cout<<"+ If you have any problem about this program, email to me please."<<endl;
	cout<<"\tEmail: zhoucosin@163.com"<<endl;
	cout<<"\tQQ:    532319166"<<endl;
	cout<<endl;

	showNote();
}

void showOperatorsInfo(const string &cmd)
{
	cout<<" /------------------< operator >------------------\\"<<endl;

	cout<<" <1> a + b \treturn the sum of a and b."<<endl;
	cout<<" <2> a - b \treturn the difference of a and b."<<endl;
	cout<<" <3> a * b \treturn the product of a and b."<<endl;
	cout<<" <4> a / b \treturn the quotien of a and b."<<endl;
	cout<<" <5> a % b \treturn the remainder of a divided by b."<<endl;
	cout<<"\tbut a and b must both are integer."<<endl;
	cout<<" <6> a ^ b \treturn the power of a and b."<<endl;
	cout<<" <7> n!\treturn the factorial of n, n must be"<<endl;
	cout<<"\ta integer."<<endl;
	cout<<endl;

	showNote();
}

void showFunctionsInfo(const string &cmd)
{
	cout<<" /------------------< function >------------------\\"<<endl;

	cout<<" <1> abs(x)\treturn absolute value of x."<<endl;
	cout<<" <2> pow(x, y)\tis same to x^y."<<endl;
	cout<<" <3> exp(x)\treturn e^x, where e is the base of the Natural"<<endl;
    cout<<"\t\tlogarithm."<<endl;
	cout<<" <4> log(x, y)\treturn the logarithm of x to the base y."<<endl;
	cout<<" <5> ln(x)\treturn the logarithm of x to the base e, where"<<endl;
	cout<<"\t\te is the base of the Natural logarithm."<<endl;
	cout<<" <6> sqrt(x)\treturn the arithmetic square root of x."<<endl;
	cout<<" <7> sin(x)\treturn the sine of x."<<endl;
	cout<<" <8> cos(x)\treturn the cosine of x."<<endl;
	cout<<" <9> tan(x)\treturn the tangent of x."<<endl;
	cout<<" <10> arcsin(x)\treturn the arc-sine of x."<<endl;
	cout<<" <11> arccos(x)\treturn the arc-cosine of x."<<endl;
	cout<<" <12> arctan(x)\treturn the arc-tangent of x."<<endl;
	cout<<" <13> factorial(n)\treturn the factorial of n. where n must"<<endl;
	cout<<"\t\tbe a integer."<<endl;
	cout<<" <14> cb(m, n)\treturn the number of methods of select"<<endl;
	cout<<"\t\tm objects from n bojects. 0<= m<= n needed."<<endl;
	cout<<" <15> max(x1, x2, ..., xn)\treturn the maximum number"<<endl;
	cout<<"\t\tin x1, x2, ..., xn."<<endl;
	cout<<" <16> min(x1, x2, ..., xn)\treturn the minimum number"<<endl;
	cout<<"\t\tin x1, x2, ..., xn."<<endl;
	cout<<" <17> ceil(x)\treturn the ceil integer of x."<<endl;
	cout<<" <18> floor(x)\treturn the floor integer of x."<<endl;
	cout<<endl;
		
	showNote();
}

void CutSpaceInString(string& str)
{
	string::size_type ix = str.find_first_not_of(' ');
	string::size_type jx = str.find_last_not_of(' ') + 1;

	if (ix == string::npos || jx == string::npos)
		return;

	str = str.substr(ix, jx-ix);
}

} // namespace
