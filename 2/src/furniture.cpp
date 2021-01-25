#include "furniture.h"
#include <iostream>

Furniture::Furniture() {
    name = "furniture";
    price = 0;
    dimensions = {0, 0, 0};
}

Furniture::Furniture(const std::string& name, const int& price, const Dimensions& dimensions) {
    this->name = name;
    this->price = price;
    this->dimensions = dimensions;
}

Furniture::Furniture (const Furniture& other) {
    this->name = other.name;
    this->price = other.price;
    this->dimensions = other.dimensions;
}

Furniture::~Furniture() {
    //no custom dynamic memory allocated so empty destructor will do
}

void Furniture::print() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Price: " << price << "cents\n";
    dimensions.print();
}

void Furniture::Dimensions::print() const {
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";
    std::cout << "z = " << z << "\n";
}

Furniture& Furniture::operator+= (const int& price_increment) {
    price += price_increment;
    return *this;
}

Furniture Furniture::operator- (const int& price_decrement) {
    if ((price -= price_decrement) < 1)
        price = 1;
    return *this;
}

bool operator== (const Furniture& lhs, const Furniture& rhs) {
    return lhs.name == rhs.name;
}
