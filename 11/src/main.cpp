#include "oop11.h"
#include <iostream>

auto main() -> int {
	const double MAX = 10.0;
	std::function<double(double)> f = [] (double x) {return x;};
	std::function<double(double)>	g = [MAX] (double x) {return cos(x) * MAX;};
	auto range_ = std::make_pair(0.0, MAX);

	auto xs = intersections(f, g, range_);
	for (auto x : xs) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
