#include "Complex.h"

Complex::Complex()
{
	re = 0;
	im = 0;
}

Complex::Complex(int _re, int _im)
{
	re = _re;
	im = _im;
}

string Complex::getComplex()
{
	string complex;
	complex += to_string(re);
	if (im >= 0) {
		complex += ('+' + to_string(im) + 'i');
	}
	else {
		complex += (to_string(im) + 'i');
	}
	return complex;
}

bool Complex::operator==(const Complex& other)
{
	return(re == other.re && im == other.im);
}

bool Complex::operator!=(const Complex& other)
{
	return !(re == other.re && im == other.im);
}

bool Complex::operator<(const Complex& other)
{
	return (re < other.re);
}

bool Complex::operator>(const Complex& other)
{
	return (re > other.re);
}
