#include "Check.h"
#include <iostream>

Check::Check(std::string date, int number, float price) 
	: Document(date, number) {

	this->price = price;
}

Check::Check() : Document() {
	this->price = NULL;
}

void Check::setPrice(float price) {
	this->price = price;
}

float Check::getPrice() {
	return this->price;
}

void Check::print() {
	std::cout << "Check" << std::endl;
	std::cout << "Number: " << this->number << std::endl;
	std::cout << "Price: " << this->price << std::endl;
	std::cout << "Date: " << this->date << std::endl << std::endl;
}

Check::~Check() {

}



