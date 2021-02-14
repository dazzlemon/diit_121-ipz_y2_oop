#include "gazetteer.h"
#include <iostream>
#include <vector>

void testGazetteerGood() {
	auto countries = std::vector {
		"Ukraine",
		"USA"
	};
	
	std::cout << "Gazetteer tests with correct input:" << std::endl;
	for (auto country : countries) {
		std::cout << country << ": " << Gazetteer::getInfo(country) << std::endl;
	}
	std::cout << std::endl;
}

void testGazetteerBad() {
	auto countries = std::vector {
		"Spain",
		"China",
		"India"
	};
	
	std::cout << "Gazetteer tests with incorrect input:" << std::endl;
	for (auto country : countries) {
		std::cout << country << ": " << Gazetteer::getInfo(country) << std::endl;
	}
}

auto main() -> int {
	testGazetteerGood();
	testGazetteerBad();
}	
