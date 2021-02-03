#ifndef FURNITURE_H
#define FURNITURE_H

#include <string>

class Furniture {
  class Dimensions {
  public:
    double x;
    double y;
    double z;
    void print() const;
  };

  std::string name;
  int price;
  Dimensions dimensions;

public:
  Furniture();
  Furniture(const std::string& name, const int& price, const Dimensions& dimensions);
  Furniture (const Furniture& other);
  ~Furniture();

  void print() const;

  Furniture& operator+= (const int& price_increment);//price +=
  Furniture operator- (const int& price_decrement);//price -

  friend bool operator== (const Furniture& lhs, const Furniture& rhs);
};
bool operator== (const Furniture& lhs, const Furniture& rhs);//generates != too(c++2a)
#endif
