#pragma once

#include "Check.h"
#include <string>

class Receipt : public Document {

private:
	std::string bank;
	float price;

public:

	Receipt(std::string date, int number, float price, std::string bank);
	Receipt();

	void print() override;

	void setPrice(float price);

	float getPrice();

	void setBank(std::string bank);

	std::string getBank();

	~Receipt() override;
};