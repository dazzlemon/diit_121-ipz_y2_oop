#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <cstddef>
#include <iostream>
#include "print.h"

template<class T, size_t ROWS, size_t COLS>
class Matrix {
	T __matrix[ROWS][COLS];
public:
	T get(size_t x, size_t y) const {return __matrix[x][y];}

	T& at(size_t x, size_t y) {return __matrix[x][y];}
};

/* SEPARETE FUNCTION BECAUSE PARTIAL TEMPLATE SPECIFICATION ISNT ALLOWED FOR FUNCTIONS */
template<class T, size_t ROWS, size_t COLS>
void print_matrix(const Matrix<T, ROWS, COLS>& m) {
	std::cout << "[ ";
	for (size_t i = 0; i < ROWS - 1; i++) {
		_print_row(m, i);
    		std::cout << " ], ";
  	}
  	_print_row(m, ROWS - 1);
	std::cout << " ] ]";
}

template<class T, size_t ROWS, size_t COLS>
void _print_row(const Matrix<T, ROWS, COLS>& m, size_t i) {
	std::cout << "[ ";
	for (size_t j = 0; j < COLS - 1; j++) {
		print(m.get(i, j));
      		std::cout << ", ";
   	}
    	print(m.get(i, COLS - 1));
}
#endif
