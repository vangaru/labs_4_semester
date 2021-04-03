#pragma once
#include <iostream>
#include <string>

using namespace std;

class Complex
{
private:
	int re;
	int im;
public:
	Complex();
	Complex(int _re, int _im);
	string getComplex();
	bool operator == (const Complex& other);
	bool operator != (const Complex& other);
	bool operator > (const Complex& other);
	bool operator < (const Complex& other);

	friend ostream &operator<<(ostream &out, const Complex &complex) {
    out << complex.getComplex();
    return out;
  }

};
