#include "matrix.h"
#include "print.h"
#include <iostream>

int main() {
	const size_t R = 4,
	      	     C = 3;
	Matrix<int, R, C> m;
	
	for (size_t i = 0; i < R; i++)
		for (size_t j = 0; j < C; j++)
			m.at(i, j) = i * j;

	print(m);
	print_matrix(m);
	std::cout << std::endl;
}
