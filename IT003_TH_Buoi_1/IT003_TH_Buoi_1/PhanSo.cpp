#include "PhanSo.h"
#include <iostream>

PhanSo::PhanSo(const int x, const int y) : tu(x), mau(y)
{
	if (mau == 0) {
		mau = 1;
	}
}
PhanSo::~PhanSo() {}

void PhanSo::Nhap()
{
	std::cout << "nhap tu: "; std::cin >> this->tu;
	std::cout << "nhap mau: "; std::cin >> this->mau;


}
void PhanSo::Xuat() const
{
	std::cout << this->tu << "/" << this->mau;
}

PhanSo PhanSo::rutGon()
{
	int gcd = abs(tu);
	int temp = abs(mau);

	while (temp != 0)
	{
		int remainder = gcd % temp;
		gcd = temp;
		temp = remainder;
	}

	if (gcd != 0)
	{
		return PhanSo(this->tu /= gcd, mau /= gcd);
	}
	return PhanSo(tu, mau);
}

double PhanSo::getValue() const
{
	return (double)this->tu / this->mau;
}

PhanSo PhanSo::operator+(const PhanSo &ps) const
{
	return PhanSo(tu * ps.mau + mau * ps.tu, mau * ps.mau);
}
PhanSo PhanSo::operator+=(const PhanSo &ps)
{
	this->tu *= ps.mau;
	this->tu += mau * ps.tu;
	this->mau *= ps.mau;
	return this->rutGon();
}

PhanSo PhanSo::operator-(const PhanSo &ps) const
{
	return PhanSo(tu * ps.mau - mau * ps.tu, mau * ps.mau);
}
PhanSo PhanSo::operator-=(const PhanSo &ps)
{
	this->tu *= ps.mau;
	this->tu -= mau * ps.tu;
	this->mau *= ps.mau;
	return this->rutGon();
}

PhanSo PhanSo::operator*(const PhanSo &ps) const
{
	return PhanSo(tu * ps.tu, mau * ps.mau);
}
PhanSo PhanSo::operator*=(const PhanSo &ps)
{
	this->tu *= ps.tu;
	this->mau *= ps.mau;
	return this->rutGon();
}

PhanSo PhanSo::operator/(const PhanSo &ps) const
{
	return PhanSo(tu * ps.mau, mau * ps.tu);
}
PhanSo PhanSo::operator/=(const PhanSo& ps)
{
	this->tu *= ps.mau;
	this->mau *= ps.tu;
	return this->rutGon();
}

