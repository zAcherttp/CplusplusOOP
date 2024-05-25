#include "CTime.h"
#include <iomanip>

CTime::CTime(int _hour, int _minute, int _second)
{
	int second = ((_hour * 3600) + (_minute * 60) + (_second)) % 86400;
	this->hour = second / 3600;
	this->min = (second / 60) % 60;
	this->sec = second % 60;
}

CTime::~CTime()
{
}

int CTime::getSeconds() const
{
	return (this->hour * 3600) + (this->min * 60) + (this->sec);
}

CTime CTime::operator+(const CTimeSpan& time)
{
	CTime temp;
	int second = (this->getSeconds() + time.getSpan()) % 86400;
	temp.hour = second / 3600;
	temp.min = (second / 60) % 60;
	temp.sec = second % 60;
	return temp;
}

CTime CTime::operator+(const int& time)
{
	CTime temp;
	int second = (this->getSeconds() + time) % 86400;
	temp.hour = second / 3600;
	temp.min = (second / 60) % 60;
	temp.sec = second % 60;
	return temp;
}

CTimeSpan CTime::operator-(const CTime& time)
{
	CTimeSpan temp;
	int second = (this->getSeconds() - time.getSeconds()) % 86400;
	temp.setHour(second / 3600);
	temp.setMin((second / 60) % 60);
	temp.setSec(second % 60);
	return temp;
}

CTime CTime::operator-(const int& time)
{
	CTime temp;
	int second = (this->getSeconds() - time) % 86400;
	temp.hour = second / 3600;
	temp.min = (second / 60) % 60;
	temp.sec = second % 60;
	return temp;
}

CTime& CTime::operator++()
{
	*this = *this + 1;
	return *this;
}

CTime CTime::operator++(int)
{
	CTime time = *this;
	*this = *this + 1;
	return time;
}

CTime& CTime::operator--()
{
	*this = *this - 1;
	return *this;
}

CTime CTime::operator--(int)
{
	CTime time = *this;
	*this = *this - 1;
	return time;
}

istream& operator>>(istream& is, CTime& time)
{
	cout << "time (24h):\n";
	cout << "hours: ";
	is >> time.hour;
	cout << "minutes: ";
	is >> time.min;
	cout << "seconds: ";
	is >> time.sec;
	return is;
}

ostream& operator<<(ostream& os, const CTime& time)
{
	os << setw(2) << setfill('0') << time.hour << ':'
		<< setw(2) << setfill('0') << time.min << ':'
		<< setw(2) << setfill('0') << time.sec;
	return os;
}
