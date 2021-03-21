#pragma once
#include <iostream>
#include <string>

class Complex
{
private:
	int re;
	int im;
public:
	Complex();
	Complex(int _re, int _im);
	std::string getComplex();
	std::ostream& operator<<(std::ostream& outstream);
	bool operator == (const Complex& other);
	bool operator != (const Complex& other);
	bool operator > (const Complex& other);
	bool operator < (const Complex& other);
};