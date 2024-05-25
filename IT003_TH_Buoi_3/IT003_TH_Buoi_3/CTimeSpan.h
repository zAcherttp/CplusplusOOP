#pragma once

#include <iostream>
using namespace std;

class CTime;

class CTimeSpan
{
private:
	long span;
public:
	CTimeSpan(long _span = 0) : span(_span) {}

	long getSpan() const;
	void setSpan(long span);

	void xuat() const;
	void nhap();

	CTimeSpan cong(CTimeSpan &span);
	CTimeSpan tru(CTimeSpan &span);

	bool isEqual(CTimeSpan &span);
	bool isNotEqual(CTimeSpan &span);
	bool largerThan(CTimeSpan &span);
	bool largerOrEqual(CTimeSpan &span);
	bool smallerThan(CTimeSpan &span);
	bool smallerOrEqual(CTimeSpan &span);
};

