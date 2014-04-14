#include"CPersons.h"


const bool CPerson::MAN=1;
const bool CPerson::WOMAN=0;
CPerson::CPerson()
{
	id=-1;
	strcpy(name,"unkown");
	sex=CPerson::MAN;
}

CPerson::CPerson(const char* name,const int &id,const bool sex)
{
	strcpy(this->name,name);
	this->id=id;
	this->sex=sex;
}

int CPerson::getId()
{
	return id;
}

char* CPerson::getName()
{
	return name;
}

bool CPerson::getSex()
{
	return sex;
}

void CPerson::setId(const int id)
{
	this->id=id;
}

void CPerson::setName(const char* name)
{
	strcpy(this->name,name);
}

void CPerson::setSex(const bool sex)
{
	this->sex=sex;
}

istream& operator>>(istream &in,CPerson &a)
{
	int sextmp;
	in>>a.name>>a.id>>sextmp;
	if(sextmp) a.sex=1;
	else a.sex=0;
	return in;
}
ostream& operator<<(ostream &out,CPerson &b)
{
	out<<"name:"<<b.name<<endl
		<<"id:"<<b.id<<endl
		<<"sex:";
	if(b.sex==CPerson::MAN)
		out<<"Man"<<endl;
	else out<<"Woman"<<endl;
	return out;
}


CStudent::CStudent():CPerson()
{
	memset(scores,0,sizeof(scores));
}
CStudent::CStudent(const char *name,const int id,const bool sex):CPerson(name,id,sex)
{
	memset(scores,0,sizeof(scores));
}
CStudent::CStudent(const char* name,const int id,const bool sex,int s1,int s2,int s3):CPerson(name,id,sex)
{
	scores[0]=s1;
	scores[1]=s2;
	scores[2]=s3;
}

void CStudent::getScores(int &a,int &b,int &c)
{
	a=scores[0];
	b=scores[1];
	c=scores[2];
}
void CStudent::setScores(int a,int b,int c)
{
	scores[0]=a;
	scores[1]=b;
	scores[2]=c;
}

istream& operator>>(istream &in,CStudent &a)
{
	cin>>(CPerson)a;
	cin>>a.scores[0]>>a.scores[1]>>a.scores[2];
	return in;
}

ostream& operator<<(ostream &out,CStudent &b)
{
	out<<(CPerson)b;
	cout<<"scores:"<<b.scores[0]<<" "<<b.scores[1]<<" "<<b.scores[2]<<endl; 
	return out;
}

int CTeacher::getTeachYears()
{
	return teachYears;
}

void CTeacher::setTeachYears(const int n)
{
	teachYears=n;
}

istream& operator>>(istream &in,CTeacher &a)
{
	cin>>(CPerson)a;
	cin>>a.teachYears;
	return in;
}

ostream& operator<<(ostream &out,CTeacher &b)
{
	out<<(CPerson)b;
	cout<<"teachYears:"<<b.getTeachYears()<<endl; 
	return out;
}