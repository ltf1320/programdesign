#include <iostream.h>
#include <string.h>
class CPerson
{
	friend istream& operator>>(istream &in,CPerson &a);
	friend ostream& operator<<(ostream &out,CPerson &b);
public:
	CPerson();
	CPerson(const char* name,const int &id,const bool sex);
	static const bool MAN;
	static const bool WOMAN;
	char* getName();
	void setName(const char* name);
	int getId();
	void setId(const int id);
	bool getSex();
	void setSex(const bool sex);
private:
	char name[50];
	int id;
	bool sex;
};
istream& operator>>(istream &in,CPerson &a);
ostream& operator<<(ostream &out,CPerson &b);

class CStudent: public CPerson
{
	friend istream& operator>>(istream &in,CStudent &a);
	friend ostream& operator<<(ostream &out,CStudent &b);
public:
	CStudent();
	CStudent(const char* name,const int id,const bool sex);
	CStudent(const char* name,const int id,const bool sex,int s1,int s2,int s3);
	void setScores(int a,int b,int c);
	void getScores(int &a,int& b,int &c);
private:
	int scores[3];
};

istream& operator>>(istream &in,CStudent &a);
ostream& operator<<(ostream &out,CStudent &b);

class CTeacher: public CPerson
{
	friend istream& operator>>(istream &in,CTeacher &a);
	friend ostream& operator<<(ostream &out,CTeacher &b);
public:
	CTeacher();
	CTeacher(const char* name,const int id,const bool sex);
	CTeacher(const char* name,const int id,const bool sex,const int teachYears);
	int getTeachYears();
	void setTeachYears(const int n);
private:
	int teachYears;
};

istream& operator>>(istream &in,CTeacher &a);
ostream& operator<<(ostream &out,CTeacher &b);