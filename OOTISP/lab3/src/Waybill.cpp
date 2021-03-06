#include "Waybill.h"
#include <iostream>

Waybill::Waybill(std::string date, int number, std::string sender,
	std::string recipient, std::string productName) : Document(date, number){
	
	this->sender = sender;
	this->recipient = recipient;
	this->productName = productName;
}

Waybill::Waybill() {
	this->sender = "tuesdaydude";
	this->recipient = "tuesdaydude";
	this->productName = "coursework";
}

void Waybill::setSender(std::string sender) {
	this->sender = sender;
}

void Waybill::setRecipient(std::string recipient) {
	this->recipient = recipient;
}

void Waybill::setProductName(std::string productName) {
	this->productName = productName;
}

std::string Waybill::getSender() {
	return this->sender;
}

std::string Waybill::getRecipient() {
	return this->recipient;
}

std::string Waybill::getProductName() {
	return this->productName;
}

void Waybill::print() {
	std::cout << "Waybill" << std::endl;
	std::cout << "Number: " << this->number << std::endl;
	std::cout << "Sender: " << this->sender << std::endl;
	std::cout << "Recipient: " << this->recipient << std::endl;
	std::cout << "Product Name: " << this->productName << std::endl;
	std::cout << "Date: " << this->date << std::endl << std::endl;
}

Waybill::~Waybill() {

}