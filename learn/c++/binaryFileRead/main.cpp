#include<iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;
using std::ifstream;

using std::ios;

#include "Date.h"
#include "Person.h"
#include "Student.h"

#define TYPE  Student
#define fileName "student.dat"


int main()
{
	TYPE obj1;
	TYPE obj2;

	//把以下代码注释掉
    /*
	ofstream outStrm(fileName, ios::binary | ios::app);

	if( !outStrm)
	{
		cout<<"\ncan not open file.\n";
		exit(1);
	}

	for(int i=0;i<2;i++)
	{
		cin>>obj1;

		outStrm.write( reinterpret_cast<char*>(&obj1), sizeof(TYPE));
	}

	outStrm.close();
	*/
	//把以上代码注释掉


	ifstream inStrm(fileName, ios::binary | ios::in);

	if( !inStrm)
	{
		cout<<"\ncan not open file.\n";
		exit(1);
	}

	inStrm.read( reinterpret_cast<char*>(&obj2), sizeof(TYPE));

	while( inStrm && !inStrm.eof())
	{
		obj2.print();
		inStrm.read( reinterpret_cast<char*>(&obj2), sizeof(TYPE));

	}
	inStrm.close();

	return 0;
}

