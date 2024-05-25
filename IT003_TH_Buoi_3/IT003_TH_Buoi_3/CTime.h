#pragma once
#include <string>
using namespace std;
class CTimeSpan;

class CTime
{
private:
	int hour;
	int minute;
	int second;
public:
	CTime(int _h, int _m, int _s) {};

	CTime getTime() const;
	void setTime(int _h, int _m, int _s);

	void nhap();
	void xuat() const;

	CTime cong(CTimeSpan &span);
	CTime cong(int hour = 0, int minute = 0, int second = 1);
	CTimeSpan tru(CTime &time);
	CTimeSpan tru(int hour = 0, int minute = 0, int second = 1);

	CTime increment(string s);
};

