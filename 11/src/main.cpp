#include "oop11v1.h"
#include "oop11v2.h"
#include <iostream>

auto main() -> int {
	const double MAX = 10.0;
	std::function<double(double)> f = [] (double x) {return x;};
	std::function<double(double)>	g = [MAX] (double x) {return cos(x) * MAX;};
	auto range_ = std::make_pair(0.0, MAX);

	std::cout << "f(x) = x" << std::endl;
	std::cout << "g(x) = 10 * cos(x)" << std::endl;
	std::cout << "f = g on range [0, 10] for xs: ";
	auto xs = v1::intersections(f, g, range_);
	for (auto x : xs) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
