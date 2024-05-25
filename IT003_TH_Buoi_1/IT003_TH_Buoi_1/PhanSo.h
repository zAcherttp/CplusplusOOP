#pragma once
class PhanSo
{
public:
	int tu;
	int mau;

public:
	PhanSo(const int x = 1, const int y = 1);
	~PhanSo();

	void Nhap();
	void Xuat() const;
	PhanSo rutGon();

	PhanSo operator+(const PhanSo& ps) const;
	PhanSo operator+=(const PhanSo& ps);

	PhanSo operator-(const PhanSo& ps) const;
	PhanSo operator-=(const PhanSo& ps);

	PhanSo operator*(const PhanSo& ps) const;
	PhanSo operator*=(const PhanSo& ps);

	PhanSo operator/(const PhanSo& ps) const;
	PhanSo operator/=(const PhanSo& ps);

	double getValue() const;
};

