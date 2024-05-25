#pragma once
#include <iostream>
using namespace std;

class CTimeSpan
{
private:
	int sec;
	int min;
	int hour;
public:
	CTimeSpan(int _hour = 0, int _minute = 0, int _second = 0);
	~CTimeSpan();

	int getSpan() const;
	void setHour(int _h);
	void setMin(int _m);
	void setSec(int _s);

	friend istream& operator>>(istream &is, CTimeSpan& dur);
	friend ostream& operator<<(ostream &os, const CTimeSpan& dur);
	CTimeSpan operator+(const CTimeSpan& dur);
	CTimeSpan operator-(const CTimeSpan& dur);
	bool operator==(const CTimeSpan& dur);
	bool operator!=(const CTimeSpan& dur);
	bool operator>(const CTimeSpan & dur);
	bool operator>=(const CTimeSpan& dur);
	bool operator<(const CTimeSpan& dur);
	bool operator<=(const CTimeSpan& dur);
};

