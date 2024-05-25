#pragma once
#include <string>
struct date
{
	int day;
	int month;
	int year;
};
struct score
{
	float Toan;
	float Van;
	float Anh;
};
class candidate
{
private:
	int Ma;
	std::string HoTen;
	date NgaySinh;
	score Diem;
public:
	candidate();
	~candidate();

	void Nhap();
	void Xuat() const;

	int getMaHocSinh() const;

	float getScoreSum() const;

	float getMathScore() const;
	float getLiteratureScore() const;
	float getEnglishScore() const;

	void printName() const;
	void printBirthDate() const;
};

