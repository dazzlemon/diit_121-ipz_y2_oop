#include "oop11v1.h"
#include "oop11v2.h"
#include <iostream>

namespace v = v1;//v2

auto main() -> int {
	const double MAX = 10.0;
	std::function<double(double)> f = [] (double x) {return x;};
	std::function<double(double)>	g = [MAX] (double x) {return cos(x) * MAX;};
	auto range_ = std::make_pair(0.0, MAX);

	auto xs = v::intersections(f, g, range_);
	for (auto x : xs) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
