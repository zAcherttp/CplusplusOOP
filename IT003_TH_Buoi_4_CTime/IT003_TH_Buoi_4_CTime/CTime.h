#pragma once
#include "CTimeSpan.h"
#include <time.h>
#include <iostream>
using namespace std;

class CTime
{
private:
	int sec;
	int min;
	int hour;
public:
	CTime(int _hour = 0, int _minute = 0, int _second = 0);
	~CTime();

	int getSeconds() const;

	friend istream& operator>>(istream& is, CTime& time);
	friend ostream& operator<<(ostream& os, const CTime& time);
	CTime operator+(const CTimeSpan& time);
	CTime operator+(const int& time);
	CTimeSpan operator-(const CTime& time);
	CTime operator-(const int& time);
	CTime& operator++();
	CTime operator++(int);
	CTime& operator--();
	CTime operator--(int);
};

