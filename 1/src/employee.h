#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <string>

class Employee {
	std::string name;
	int age;
	int experience;
public:
    Employee();
    Employee(const std::string& name, const int& age, const int& experience);
    Employee(const Employee& other);
    ~Employee();
    void print();
	friend class Company;
};
#endif
