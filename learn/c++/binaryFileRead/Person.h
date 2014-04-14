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
	Person();     //Ĭ�Ϲ��캯��
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


Person::Person()    //Ĭ�Ϲ��캯��
{
	strcpy(Num,"");
	strcpy(name,"");
	strcpy(sex,"");
	strcpy(ID,"");
}


void Person::print() const
{
	cout<<"\n���: "<<Num
		<<"\n����: "<<name;

	if(!strcmp(sex, "0"))
		cout<<"\n�Ա�: ��";
	else if(!strcmp(sex,"1"))
		cout<<"\n�Ա�: Ů";
	else
		cout<<"\n�Ա�: ����";

	cout<<"\n��������: "<<birthDate           //Date�������� <<
		<<"\n���֤��: "<<ID;
}

void Person::input()
{
	cout<<"\n���: ";
	while( !inputArray(Num, 6) )
		cout<<"��ţ�";


	cout<<"����: ";
	while( !inputArray(name, 10))
		cout<<"����: ";

	cout<<"�Ա�(��-0,Ů-1): ";
	while( !inputArray(sex,2) )
		cout<<"�Ա�(��-0,Ů-1): ";

	cout<<"��������: ";
	cin>>birthDate;

	cout<<"���֤��: ";
	while( !inputArray(ID, 19))
		cout<<"���֤��: ";
}


//inputArray(char* ,size_t)�Ĺ�������ָ�����������ַ��ܣ���������������볤�ȳ������鳤��ʱ������false
//���򷵻�true(�������д���е��ң����߼�����ȷ��~~��

bool Person::inputArray(char *array, size_t size)
{
	int i=0;
    char temp;
	while( (temp=getch()) != '\r')
	{
		if(temp == '\b')          //����Backspace����,�����������һ
		{
			if(i>0)
			{
				cout<<temp<<' '<<temp;
				i--;
			}
			else          //������ʱ��backspace��������
				cout<<char(7);
		}
		else
		{
			if(i<size-1)                 //�������ַ���С����������ʱ��������д������
				array[i]=temp;
            //�����������ַ����������������һ
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
		cout<<"���볬�����ֶο���������ַ���"<<size-1<<",����������."<<endl;
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
