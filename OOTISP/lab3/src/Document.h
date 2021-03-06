#pragma once

#include<string>

class Document {

protected:
	
	std::string date;
	int number;

public:

	Document(std::string date, int number);
	Document();


	virtual void print() = 0;


	struct ListOfDocuments {
		Document* document;
		ListOfDocuments* nextItem;
	};

	static ListOfDocuments* head;

	static void printListOfDocuments();
	
	void push();


	void setDate(std::string date);
	void setNumber(int number);

	std::string getDate();
	int getNumber();


	virtual ~Document();

};
