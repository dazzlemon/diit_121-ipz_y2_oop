#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <cstddef>

template<class T, size_t ROWS, size_t COLS>
class Matrix {
	T __matrix[ROWS][COLS];
public:
	T get(size_t x, size_t y) const {return __matrix[x][y];}

	T& at(size_t x, size_t y) {return __matrix[x][y];}
};
#endif
