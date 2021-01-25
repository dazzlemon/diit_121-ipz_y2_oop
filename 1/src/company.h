#ifndef __COMPANY_H__
#define __COMPANY_H__

#include <vector>
#include "employee.h"//already has string included

class Company {
    std::string name;
    std::vector<Employee> employees;
    int capital;
public:
    Company();
    Company(const std::string& name, const std::vector<Employee>& employees, const int& capital);
    Company(const Company& other);
    ~Company();
    void print();
};
#endif
