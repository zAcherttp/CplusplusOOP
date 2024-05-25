#include "CTimeSpan.h"
#include <iomanip>

CTimeSpan::CTimeSpan(int _hour, int _minute, int _second)
{
	int second = (_hour * 3600) + (_minute * 60) + (_second);
	this->hour = second / 3600;
	this->min = (second / 60) % 60;
	this->sec = second % 60;
}

CTimeSpan::~CTimeSpan()
{
}

int CTimeSpan::getSpan() const
{
	return this->getSpan();
}

void CTimeSpan::setHour(int _h)
{
	this->hour = _h;
}

void CTimeSpan::setMin(int _m)
{
	this->min = _m;
}

void CTimeSpan::setSec(int _s)
{
	this->sec = _s;
}

CTimeSpan CTimeSpan::operator+(const CTimeSpan& dur)
{
	CTimeSpan temp;
	int second = this->getSpan() + dur.getSpan();
	temp.hour = second / 3600;
	temp.min = (second / 60) % 60;
	temp.sec = second % 60;
	return temp;
}

CTimeSpan CTimeSpan::operator-(const CTimeSpan& dur)
{
	CTimeSpan temp;
	int second = this->getSpan() - dur.getSpan();
	temp.hour = second / 3600;
	temp.min = (second / 60) % 60;
	temp.sec = second % 60;
	return temp;
}

bool CTimeSpan::operator==(const CTimeSpan& dur)
{
	return (this->hour == dur.hour) && (this->min == dur.min) && (this->sec == dur.sec);
}

bool CTimeSpan::operator!=(const CTimeSpan& dur)
{
	return (this->hour != dur.hour) || (this->min != dur.min) || (this->sec != dur.sec);
}

bool CTimeSpan::operator>(const CTimeSpan& dur)
{
	int result = this->getSpan() - dur.getSpan();
	return result > 0;
}

bool CTimeSpan::operator>=(const CTimeSpan& dur)
{
	int result = this->getSpan() - dur.getSpan();
	return result >= 0;
}

bool CTimeSpan::operator<(const CTimeSpan& dur)
{
	int result = this->getSpan() - dur.getSpan();
	return result < 0;
}

bool CTimeSpan::operator<=(const CTimeSpan& dur)
{
	int result = this->getSpan() - dur.getSpan();
	return result <= 0;
}

istream& operator>>(istream& is, CTimeSpan& dur)
{
	cout << "time span:\n";
	cout << "hours: ";
	is >> dur.hour;
	cout << "minutes: ";
	is >> dur.min;
	cout << "seconds: ";
	is >> dur.sec;
	return is;
}

ostream& operator<<(ostream& os, const CTimeSpan& dur)
{
	os << setw(2) << setfill('0') << dur.hour << ':'
		<< setw(2) << setfill('0') << dur.min << ':'
		<< setw(2) << setfill('0') << dur.sec;
	return os;
}
