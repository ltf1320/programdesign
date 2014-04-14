#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using std::ostream;
using std::istream;
using std::cout;

#include "Person.h"

class Student : virtual public Person
{
	friend ostream &operator<<(ostream &, const Student &);
	friend istream &operator>>(istream &, Student &);
public:
	Student();
    void input();
	void print() const;
private:
	char classNum[6];
};

Student::Student()
: Person()
{
	strcpy(classNum, "");
}



void Student::print() const
{
	Person::print();
	cout<<"\n°àºÅ: "<<classNum;
}

void Student::input()
{
	Person::input();

	cout<<"°àºÅ: ";
	while( !inputArray(classNum, 6))
		cout<<"°àºÅ: ";
}


ostream &operator<<(ostream &output, const Student &stuObj)
{
	stuObj.print();
	return output;
}

istream &operator>>(istream &input, Student &stuObj)
{
	stuObj.input();
	return input;
}

#endif
