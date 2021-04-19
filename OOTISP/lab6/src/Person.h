#ifndef SRC_PERSON_H
#define SRC_PERSON_H

#include <string>
#include <iostream>
#include <utility>

class Person {
private:
    std::string name;
    int age;
public:
    Person(std::string _name, int _age);

    void setName(std::string _name);
    void setAge(int _age);

    std::string getName();
    int getAge() const;

    ~Person();
};

#endif //SRC_PERSON_H
