#include <iostream>
#include "matrix.h"

template<class T>
void print(const T& obj) {
  std::cout << "<" << typeid(obj).name() << " instance at " << std::hex << &obj << ">" << std::endl;
}

template<>
void print<int>(const int& obj) {
  std::cout << obj;
}

/* SEPARETE FUNCTION BECAUSE PARTIAL TEMPLATE SPECIFICATION ISNT ALLOWED FOR FUNCTIONS */
template<class T, size_t ROWS, size_t COLS>
void print_matrix(const Matrix<T, ROWS, COLS>& obj) {
	std::cout << "[ ";
	for (size_t i = 0; i < ROWS - 1; i++) {
		std::cout << "[ ";
		for (size_t j = 0; j < COLS - 1; j++) {
			print(obj.get(i, j));
      			std::cout << ", ";
    		}
    	print(obj.get(i, COLS - 1));
    	std::cout << " ], ";
  	}
  	std::cout << "[ ";
	for (size_t j = 0; j < ROWS - 1; j++) {
    		print(obj.get(ROWS - 1, j));
    		std::cout << ", ";
  	}
	print(obj.get(ROWS - 1, COLS - 1));
  	std::cout << " ] ]";
}
