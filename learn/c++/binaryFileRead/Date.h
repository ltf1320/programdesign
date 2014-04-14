#ifndef DATE_H
#define DATE_H

#include <iostream>

using std::ostream;
using std::istream;

class Date
{
	friend ostream &operator<<(ostream &, const Date &);
	friend istream &operator>>(istream &, Date &);
public:
	Date(int y=1900, int m=1, int d=1);

private:
	int year;
	int month;
	int day;
};


Date::Date(int y, int m, int d)
{
	year=y;
	month=m;
	day=d;
}

ostream &operator<<(ostream &output, const Date &date)
{
	output<<date.year<<"Äê"
		<<date.month<<"ÔÂ"
		<<date.day<<"ÈÕ";

	return output;
}

istream &operator>>(istream &input, Date &date)
{
	int y, m, d;

	input>>y>>m>>d;
	date.year=y;
	date.month=m;
	date.day=d;
	return input;
}

#endif

