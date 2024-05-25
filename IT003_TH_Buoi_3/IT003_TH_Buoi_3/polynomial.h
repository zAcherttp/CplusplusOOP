#pragma once

#include <iostream>
#include "monomial.h"
using namespace std;

class polynomial
{
private:
    int degree;
    monomial* array;
    int constant;

public:
    polynomial(int _degree);

    ~polynomial();

    friend ostream& operator<<(ostream& os, const polynomial& p);
    friend istream& operator>>(istream& is, polynomial& p);

    int getDegree() const;

    monomial* getMonomialsArray() const;

    int getConstant() const;
    void setConstant(int _c);
    double getValue(double _x);

    polynomial operator+(const polynomial& p) const;
    polynomial operator-(const polynomial& p) const;
};

