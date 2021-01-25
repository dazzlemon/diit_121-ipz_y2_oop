#include "employee.h"
#include <iostream>

Employee::Employee() {
    std::cout << "default constructor called\n";
    name = "default_name";
    age = 0;
    experience = 0;
}

Employee::Employee(const std::string& name, const int& age, const int& experience) {
    std::cout << "argumented constructor called\n";
    this->name = name;
    this->age = age;
    this->experience = experience;
}

Employee::Employee(const Employee& other) {
    std::cout << "copy constructor called\n";
    this->name = other.name;
    this->age = other.age;
    this->experience = other.experience;
}

Employee::~Employee() {/*pass, because all property vars can delete themselves with their destructor*/}

void Employee::print() {
    std::cout << "My name is " << name << "\n";
    std::cout << "My experience = " << experience << "\n";
    std::cout << "I'm " << age << " y.o.\n";
}
