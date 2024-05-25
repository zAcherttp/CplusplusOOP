#pragma once
#include <string>
using namespace std;

class CDate
{
private:
	int day;
	int month;
	int year;
public:
	CDate(int _d, int _m, int _y) {}

	CDate getDate() const;
	void setDate(int _d, int _m, int _y);

	void nhap();
	void xuat() const;

	CDate cong(int day = 1, int month = 0, int year = 0);
	int tru(CDate &date);
	CDate tru(int day = 1, int month = 0, int year = 0);

	CDate increment(string s);
};

