#include "candidate.h"
#include <iostream>
#include <string>

struct date;
struct score;


candidate::candidate()
{
	this->Ma = 0;
	this->HoTen = "";

	this->NgaySinh.day = 1;
	this->NgaySinh.month = 1;
	this->NgaySinh.year = 1;

	this->Diem.Toan = 0.0;
	this->Diem.Van = 0.0;
	this->Diem.Anh = 0.0;
}

candidate::~candidate() {}

void candidate::Nhap()
{
	std::cout << "nhap ma hoc sinh: "; std::cin >> this->Ma;

	std::cout << "nhap ho ten: ";
	std::cin.ignore();
	getline(std::cin, this->HoTen);

	std::cout << "nhap ngay thang nam sinh (dd mm yyyy): ";
	std::cin >> this->NgaySinh.day >> this->NgaySinh.month >> this->NgaySinh.year;

	std::cout << "nhap diem Toan: "; std::cin >> this->Diem.Toan;
	std::cout << "nhap diem Van: "; std::cin >> this->Diem.Van;
	std::cout << "nhap diem Anh: "; std::cin >> this->Diem.Anh;

}
void candidate::Xuat() const
{
	std::cout << this->Ma;
	std::cout << this->HoTen;
	std::cout << this->NgaySinh.day << "/" << this->NgaySinh.month << "/" << this->NgaySinh.year;
	std::cout << "diem Toan: "; std::cout << this->Diem.Toan;
	std::cout << ", diem Van: "; std::cout << this->Diem.Van;
	std::cout << ", diem Anh: ";std::cout << this->Diem.Anh;
}

int candidate::getMaHocSinh() const
{
	return this->Ma;
}

float candidate::getScoreSum() const
{
	return this->Diem.Toan + this->Diem.Van + this->Diem.Anh;
}
float candidate::getMathScore() const
{
	return this->Diem.Toan;
}
float candidate::getLiteratureScore() const
{
	return this->Diem.Van;
}
float candidate::getEnglishScore() const
{
	return this->Diem.Anh;
}

void candidate::printName() const
{
	std::cout << this->HoTen;
}
void candidate::printBirthDate() const
{
	std::cout << this->NgaySinh.day << "/" << this->NgaySinh.month << "/" << this->NgaySinh.year;
}