#include "matrix.h"
#include "print.h"
#include <iostream>

int main() {
	const size_t r = 3,
	      	     c = 3;
	Matrix<int, r, c> m;
	
	for (size_t i = 0; i < r; i++)
		for (size_t j = 0; j < c; j++)
			m.at(i, j) = i * j;

	print(m);
	print_matrix(m);
	std::cout << std::endl;
}
