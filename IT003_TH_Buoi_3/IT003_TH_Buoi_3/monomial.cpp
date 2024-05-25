#include "monomial.h"


ostream& operator<<(ostream& os, const monomial& m)
{
    os << m.coefficient << "x^" << m.exponent;
    return os;
}

istream& operator>>(istream& is, monomial& m)
{
    is >> m.coefficient >> m.exponent;
    return is;
}

int monomial::getCoefficient() const
{
    return coefficient;
}

int monomial::getExponent() const
{
    return exponent;
}

void monomial::setCoefficient(int _c)
{
    coefficient = _c;
}

void monomial::setExponent(int _e)
{
    exponent = _e;
}

double monomial::getValue(double _x)
{
    return (double)coefficient != 0 ? coefficient * pow(_x, exponent) : 0.0;
}

monomial monomial::getDerivative() const
{
    return monomial(coefficient * exponent, exponent - 1);
}

monomial monomial::operator+(const monomial& mn) const
{
    if (exponent == mn.exponent)
    {
        return monomial(coefficient + mn.coefficient, exponent);
    }
    else
    {
        throw invalid_argument("cannot add monomials with different powers");
    }
}
monomial monomial::operator+=(const monomial& mn)
{
    if (exponent == mn.exponent)
    {
        coefficient += mn.coefficient;
        return *this;
    }
    else
    {
        throw invalid_argument("cannot add monomials with different powers");
    }
}
monomial monomial::operator-(const monomial& mn) const
{
    if (exponent == mn.exponent)
    {
        return monomial(coefficient - mn.coefficient, exponent);
    }
    else
    {
        throw invalid_argument("cannot subtract monomials with different powers");
    }
}
monomial monomial::operator-=(const monomial& mn)
{
    if (exponent == mn.exponent)
    {
        coefficient -= mn.coefficient;
        return *this;
    }
    else
    {
        throw invalid_argument("cannot subtract monomials with different powers");
    }
}
