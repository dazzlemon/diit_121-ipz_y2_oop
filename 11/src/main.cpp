#include "oop11v1.h"
#include "oop11v2.h"
#include "sort.h"
#include <iostream>
#include <vector>

auto main() -> int {
	const double MAX = 10.0;
	std::function<double(double)> f = [] (double x) {return x;};
	std::function<double(double)>	g = [MAX] (double x) {return cos(x) * MAX;};
	auto range_ = std::make_pair(1.0, MAX);

	std::cout << "f(x) = x" << std::endl;
	std::cout << "g(x) = 10 * cos(x)" << std::endl;
	std::cout << "f = g on range [0, 10] for xs: ";
	auto xs = v2::intersections(f, g, range_);
	for (auto x : xs) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::vector<std::string> strings = {
		"aersnteiarnso",
		"aenrstoiar",
		"snh",
		"hnniertdhihtsdri",
		"98243--20c83-c3428htdtlur",
		"j7gtc54k3",
		"j35luy46"
	};
	std::cout << "Strings before sort:" << std::endl;
	for (auto str : strings) {
		std::cout << str << std::endl;
	}
	std::cout << std::endl;
	quicksort(strings, 0, strings.size() - 1);
	std::cout << "Strings after sort:" << std::endl;
	for (auto str : strings) {
		std::cout << str << std::endl;
	}
}
