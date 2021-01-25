#include <iostream>
#include "furniture.h"

int main() {
    Furniture f1{"f1", 100};
    char* cp = f1;
    int i = f1;
    float f = f1;

    std::cout << "char*: " << cp << "\n";
    std::cout << "int: " << i << "\n";
    std::cout << "float: " << f << "\n";
}
