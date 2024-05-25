#pragma once

#include <iostream>
using namespace std;

class monomial
{
private:
    int coefficient;
    int exponent;

public:
    monomial(int _coefficient = 1, int _exponent = 1) : coefficient(_coefficient), exponent(_exponent) {}

    friend ostream& operator<<(ostream& os, const monomial& m);
    friend istream& operator>>(istream& is, monomial& m);

    int getCoefficient() const;
    int getExponent() const;
    void setCoefficient(int _c);
    void setExponent(int _e);
    double getValue(double _x);

    monomial getDerivative() const;
    monomial operator+(const monomial& mn) const;
    monomial operator+=(const monomial& mn);
    monomial operator-(const monomial& mn) const;
    monomial operator-=(const monomial& mn);
};

