#include "company.h"
#include <iostream>

Company::Company() {
    name = "default_name";
    capital = 0;
}

Company::Company(const std::string& name, const std::vector<Employee>& employees, const int& capital) {
    this->name = name;
    this->employees = employees;
    this->capital = capital;
}

Company::Company(const Company& other) {
    this->name = other.name;
    this->employees = other.employees;
    this->capital = other.capital;
}

Company::~Company() {/*pass, because all property vars can delete themselves with their destructor*/}

void Company::print() {
    std::cout << "Company " << name << "\n";
    std::cout << "capital = " << capital << "\n";
    std::cout << "employees\n";
    for (auto& employee : employees)
        employee.print();
}
