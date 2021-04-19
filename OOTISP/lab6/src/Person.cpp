#include "Person.h"

Person::Person(std::string _name, int _age) {
    this->name = std::move(_name);
    this->age = _age;
}

void Person::setName(std::string _name) {
    this->name = std::move(_name);
}

void  Person::setAge(int _age) {
    this->age = _age;
}

std::string Person::getName() {
    return name;
}

int Person::getAge() const {
    return age;
}

Person::~Person() {
    std::cout << "\nPerson destructor\n";
}