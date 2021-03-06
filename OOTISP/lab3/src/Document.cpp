#include "Document.h"

Document::ListOfDocuments* Document::head = NULL;

Document::Document(std::string date, int number) {
	this->date = date;
	this->number = number;
	this->push();
}

Document::Document() {
	this->date = "01.01.1970";
	this->number = NULL;
	this->push();
}

void Document::setDate(std::string date) {
	this->date = date;
}

void Document::setNumber(int number) {
	this->number = number;
}

std::string Document::getDate() {
	return this->date;
}

int Document::getNumber() {
	return this->number;
}

void Document::push() {
	ListOfDocuments* listItem = new ListOfDocuments;
	listItem->document = this;
	listItem->nextItem = head;
	head = listItem;
}

void Document::printListOfDocuments() {
	ListOfDocuments* listItem = head;
	while (listItem != NULL) {
		listItem->document->print();
		listItem = listItem->nextItem;
	}
}

Document::~Document() {
	delete this->head;
}



