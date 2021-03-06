#include <iostream>
#include "Receipt.h"

Receipt::Receipt(std::string date, int number, float price,
	std::string bank) : Document(date, number) {

	this->bank = bank;
	this->price = price;
}

Receipt::Receipt() : Document() {
	this->bank = "Tinkoff bank";
	this->price = NULL;
}

void Receipt::setBank(std::string bank) {
	this->bank = bank;
}

void Receipt::setPrice(float price) {
	this->price = price;
}

std::string Receipt::getBank() {
	return this->bank;
}

float Receipt::getPrice() {
	return this->price;
}

void Receipt::print() {
	std::cout << "Receipt" << std::endl;
	std::cout << "Number: " << this->number << std::endl;
	std::cout << "Bank: " << this->bank << std::endl;
	std::cout << "Price: " << this->price << std::endl;
	std::cout << "Date: " << this->date << std::endl << std::endl;
}

Receipt::~Receipt() {

}



