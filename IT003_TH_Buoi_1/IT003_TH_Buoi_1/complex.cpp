#include "complex.h"
#include <iostream>

complex::complex(float _real, float _im) : r(_real), i(_im) {}
complex::~complex() {}

void complex::Nhap()
{
	std::cout << "nhap phan thuc: "; std::cin >> this->r;
	std::cout << "nhap phan ao: "; std::cin >> this->i;
}
void complex::Xuat() const
{
	std::cout << this->r << " + " << this->i << "i";
}

const float complex::getReal()
{
	return this->r;
}

const float complex::getIm()
{
	return this->i;
}

complex complex::operator+(const complex &c)
{
	return complex(r + c.r, i + c.i);
}

complex complex::operator-(const complex &c)
{
	return complex(r - c.r, i - c.i);
}

complex complex::operator*(const complex &c)
{
	return complex(r * i - c.r * c.i, r * c.i + c.r * i);
}

complex complex::operator/(const complex &c)
{
	return complex((r * i + c.r * c.i) / (i * i + c.i * c.i), (c.r * i - r * c.i) / (i * i + c.i * c.i));
}