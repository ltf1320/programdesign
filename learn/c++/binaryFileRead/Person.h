#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include <string>
#include <cstring>
#include <conio.h>

using std::string;

#include <iostream>

using std::istream;
using std::ostream;
using std::cout;


class Person
{
	friend ostream &operator<<(ostream &, const Person &);
	friend istream &operator>>(istream &, Person &);

public:
	Person();     //默认构造函数
    void input();
    void print() const;
	bool inputArray(char*, size_t);
private:
	char Num[6];
	char name[10];
	char sex[2];
	Date birthDate;
	char ID[19];
};


Person::Person()    //默认构造函数
{
	strcpy(Num,"");
	strcpy(name,"");
	strcpy(sex,"");
	strcpy(ID,"");
}


void Person::print() const
{
	cout<<"\n编号: "<<Num
		<<"\n姓名: "<<name;

	if(!strcmp(sex, "0"))
		cout<<"\n性别: 男";
	else if(!strcmp(sex,"1"))
		cout<<"\n性别: 女";
	else
		cout<<"\n性别: 不详";

	cout<<"\n出生日期: "<<birthDate           //Date类需重载 <<
		<<"\n身份证号: "<<ID;
}

void Person::input()
{
	cout<<"\n编号: ";
	while( !inputArray(Num, 6) )
		cout<<"编号：";


	cout<<"姓名: ";
	while( !inputArray(name, 10))
		cout<<"姓名: ";

	cout<<"性别(男-0,女-1): ";
	while( !inputArray(sex,2) )
		cout<<"性别(男-0,女-1): ";

	cout<<"出生日期: ";
	cin>>birthDate;

	cout<<"身份证号: ";
	while( !inputArray(ID, 19))
		cout<<"身份证号: ";
}


//inputArray(char* ,size_t)的功能是向指定数组输入字符窜，当无输入或者输入长度超过数组长度时，返回false
//否则返回true(这个函数写的有点乱，但逻辑是正确的~~）

bool Person::inputArray(char *array, size_t size)
{
	int i=0;
    char temp;
	while( (temp=getch()) != '\r')
	{
		if(temp == '\b')          //输入Backspace处理,将输入计数减一
		{
			if(i>0)
			{
				cout<<temp<<' '<<temp;
				i--;
			}
			else          //无输入时按backspace，将响铃
				cout<<char(7);
		}
		else
		{
			if(i<size-1)                 //当输入字符数小于数组容量时，将输入写入数组
				array[i]=temp;
            //输出刚输入的字符，并将输入计数加一
			cout<<temp;
			i++;
		}
	}

	cout<<'\n';

	if(i<size && i>0)
	{
		array[i]='\0';
		return true;
	}
	else if(i==0)
	{
		array[i]='\0';
		return false;
	}
	else
	{
		cout<<"输入超过本字段可容纳最大字符数"<<size-1<<",请重新输入."<<endl;
		strcpy(array,"");
		return false;
	}
}


ostream &operator<<(ostream &output, const Person &personObj)
{
	personObj.print();

	return output;

}

istream &operator>>(istream &input, Person &personObj )
{
	personObj.input();

	return input;
}

#endif
