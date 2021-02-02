#ifndef __PRINT_H__
#define __PRINT_H__

#include <iostream>

template<class T>
void print(const T& obj) {
	std::cout << "<" << typeid(obj).name() << " instance at " << std::hex << &obj << ">" << std::endl;
}

template<>
void print<int>(const int& obj) {
	std::cout << obj;
}
#endif
