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

std::string Complex::getComplex()
{
	std::string complex;
	complex += std::to_string(re);
	if (im >= 0) {
		complex += ('+' + std::to_string(im) + 'i');
	}
	else {
		complex += (std::to_string(im) + 'i');
	}
	return complex;
}

std::ostream& Complex::operator<<(std::ostream& outstream)
{
	outstream << getComplex();
	return outstream;
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