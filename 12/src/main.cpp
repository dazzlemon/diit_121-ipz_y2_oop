#include "gazetteer.h"
#include "gazetteer_dynamic.h"
#include <iostream>
#include <vector>

void testGazetteerDynamicGood() {
	auto gazetteer = GazetteerDynamic();
	gazetteer.insertInfo("Ukraine", "Country of Eastern Europe.");
	gazetteer.insertInfo("Ukraine", "Second-largest country in Europe after Russia.");
	gazetteer.insertInfo("China", "Most populous country in the world.");
	gazetteer.insertInfo("China", "Third-largest(by area) country in the world.");

	std::cout << "GazetteerDynamic tests with correct input:" << std::endl;
	std::cout << "\t" << R"(insertInfo("Ukraine", "Country of Eastern Europe.");)" << std::endl;
	std::cout << "\t" << R"(insertInfo("Ukraine", "Second-largest country in Europe after Russia.");)" << std::endl;
	std::cout << "\t" << R"(insertInfo("China", "Most populous country in the world.");)" << std::endl;
	std::cout << "\t" << R"(insertInfo("China", "Third-largest(by area) country in the world.");)" << std::endl;
	std::cout << std::endl;
	
	auto countries = std::vector {
		"Ukraine",
		"China"
	};
	for (auto country : countries) {
		auto values = gazetteer.getInfo(country);
		std::cout << "\tCountry: " << country << std::endl;
		std::cout << "\tValues:" << std::endl;
		for (size_t i = 0; i < values.size(); i++) {
			std::cout << "\t\t" << i + 1 << ". " << values[i] << std::endl;
		}
	}
}


void testGazetteerDynamicBad() {
	auto gazetteer = GazetteerDynamic();
	std::cout << "GazetteerDynamic tests with incorrect input: " << std::endl;
	auto values = gazetteer.getInfo("China");
	std::cout << "\t" << R"(gazetteer.getInfo("China"); -> [)";
	for (auto value : values) {
		std::cout << value;
	}
	std::cout << "]" << std::endl;
}


void testGazetteerGood() {
	auto countries = std::vector {
		"Ukraine",
		"USA"
	};
	
	std::cout << "Gazetteer tests with correct input:" << std::endl;
	for (auto country : countries) {
		std::cout << "\t" << country << ": " << Gazetteer::getInfo(country) << std::endl;
	}
}


void testGazetteerBad() {
	auto countries = std::vector {
		"Spain",
		"China",
		"India"
	};
	
	std::cout << "Gazetteer tests with incorrect input:" << std::endl;
	for (auto country : countries) {
		std::cout << "\t" << country << ": " << Gazetteer::getInfo(country) << std::endl;
	}
}


auto main() -> int {
	testGazetteerGood(); std::cout << std::endl;
	testGazetteerBad(); std::cout << std::endl;
	testGazetteerDynamicGood(); std::cout << std::endl;
	testGazetteerDynamicBad();
}	
