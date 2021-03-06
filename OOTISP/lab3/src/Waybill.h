#pragma once

#include "Document.h"
#include <string>

class Waybill : public Document {

private:

	std::string sender;
	std::string recipient;
	std::string productName;

public:

	Waybill(std::string date, int number, std::string sender, 
		std::string recipient, std::string productName);

	Waybill();

	void print() override;

	void setSender(std::string sender);
	void setRecipient(std::string recipient);
	void setProductName(std::string productName);

	std::string getSender();
	std::string getRecipient();
	std::string getProductName();

	~Waybill() override;
};