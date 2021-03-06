#pragma once

#include "Document.h"

class Check : public Document {

private:
	float price;

public:

	Check(std::string date, int number, float price);
	Check();
	
	void print() override;

	void setPrice(float price);

	float getPrice();

	~Check() override;

};