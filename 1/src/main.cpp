#include "employee.h"

int main() {
    Employee employee1;
	Employee employee2("employee2", 18, 0);
    Employee employee3(employee2);
    return 0;
}

