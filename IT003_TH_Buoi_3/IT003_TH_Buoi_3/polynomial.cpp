#include "polynomial.h"


polynomial::polynomial(int _degree) : degree(_degree), constant(0)
{
    if (_degree == 0)
    {
        array = new monomial[1];
        array[0].setCoefficient(0);
    }
    else
    {
        array = new monomial[_degree];
    }
}

polynomial::~polynomial()
{
    delete[] array;
}

ostream& operator<<(ostream& os, const polynomial& p)
{
    bool isFirst = true;
    for (int i = 0; i < p.degree; i++)
    {
        if (p.array[i].getCoefficient() != 0)
        {
            if (!isFirst && p.array[i].getCoefficient() > 0)
                os << "+";

            if (p.array[i].getCoefficient() != 1 && p.array[i].getCoefficient() != -1 && p.array[i].getExponent() != 0)
                os << p.array[i].getCoefficient();

            if (p.array[i].getCoefficient() == -1 && p.array[i].getExponent() != 0)
                os << "-";

            if (p.array[i].getExponent() != 0)
                os << "x";

            if (p.array[i].getExponent() != 1 && p.array[i].getExponent() != 0)
                os << "^" << p.array[i].getExponent();

            if (p.array[i].getExponent() == 0)
                os << p.array[i].getCoefficient();

            if (isFirst)
                isFirst = false;
        }
    }
    if (p.constant < 0)
        os << p.constant;
    else
        os << "+" << p.constant;
    return os;
}

istream& operator>>(istream& is, polynomial& p)
{
    int temp = 0;
    for (int i = 0; i < p.degree; i++)
    {
        is >> temp;
        p.array[i].setCoefficient(temp);
        p.array[i].setExponent(p.degree - i);
    }
    is >> p.constant;
    return is;
}

int polynomial::getDegree() const
{
    return degree;
}

monomial* polynomial::getMonomialsArray() const
{
    return array;
}

int polynomial::getConstant() const
{
    return constant;
}

void polynomial::setConstant(int _c)
{
    constant = _c;
}

double polynomial::getValue(double _x)
{
    double value = constant;
    for (int i = 0; i < degree; i++)
    {
        value += array[i].getValue(_x);
    }
    return value;
}

polynomial polynomial::operator+(const polynomial& p) const
{
    int h_deg, l_deg;
    monomial* h_ptr, * l_ptr;

    if (p.getDegree() > this->getDegree())
    {
        h_deg = p.getDegree();
        h_ptr = p.array;
    }
    else
    {
        h_deg = this->getDegree();
        h_ptr = this->array;
    }
    l_deg = p.getDegree() + this->getDegree() - h_deg;
    l_ptr = h_ptr == p.array ? this->array : p.array;

    polynomial result(h_deg);
    result.setConstant(this->constant + p.constant);

    int delta = h_deg - l_deg;
    if (delta > 0)
    {
        for (int i = 0; i < delta; i++)
        {
            result.array[i] = h_ptr[i];
        }
    }
    for (int i = delta; i < h_deg; i++)
    {
        result.array[i] = h_ptr[i] + l_ptr[i - delta];
    }

    return result;
}

polynomial polynomial::operator-(const polynomial& p) const
{
    int h_deg, l_deg;
    monomial* h_ptr, * l_ptr;

    if (p.getDegree() > this->getDegree())
    {
        h_deg = p.getDegree();
        h_ptr = p.array;
    }
    else
    {
        h_deg = this->getDegree();
        h_ptr = this->array;
    }
    l_deg = p.getDegree() + this->getDegree() - h_deg;
    l_ptr = h_ptr == p.array ? this->array : p.array;

    polynomial result(h_deg);
    result.setConstant(this->constant + p.constant);

    int delta = h_deg - l_deg;
    if (delta > 0)
    {
        for (int i = 0; i < delta; i++)
        {
            result.array[i] = h_ptr[i];
        }
    }
    for (int i = delta; i < h_deg; i++)
    {
        result.array[i] = h_ptr[i] - l_ptr[i - delta];
    }

    return result;
}