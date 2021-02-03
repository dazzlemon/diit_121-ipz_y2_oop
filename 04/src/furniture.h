#ifndef FURNITURE_H
#define FURNITURE_H

#include <string>

class Furniture {
  std::string name;
  int price;
public:
  Furniture(const std::string& name, const int& price) : name{name}, price{price} {};
  Furniture(const Furniture& other) : name{other.name}, price{other.price} {};
  operator char*() {return const_cast<char*>(name.c_str());}
  operator int() {return price;}
  operator float() {return price / 100;}
};
#endif
