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

	gazetteer.removeCountry("China");
	std::cout << "\t" << R"(removeCountry("China");)" << std::endl;
	for (auto country : countries) {
		auto values = gazetteer.getInfo(country);
		std::cout << "\tCountry: " << country << std::endl;
		std::cout << "\tValues: " << std::endl;
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
	auto gazetteer = Gazetteer();
	gazetteer.insert("Ukraine", "Ukraine is a country in Eastern Europe. It is bordered by Russia to the east and north-east; Belarus to the north; Poland, Slovakia and Hungary to the west; and Romania, Moldova, Crimea, and the Black Sea to the south. Including Crimea, Ukraine has an area of 603,628 km², and is the second-largest country in Europe after Russia.");
	gazetteer.insert("USA", "The United States—officially the United States of America, commonly known as America—is a country primarily located in North America, consisting of 50 states, a federal district, five major self-governing territories, 326 reservations, and various possessions.");

		auto countries = std::vector {
		"Ukraine",
		"USA"
	};
	
	std::cout << "Gazetteer tests with correct input:" << std::endl;
	std::cout << "\t" << R"(insert("Ukraine", "...");)" << std::endl;
	std::cout << "\t" << R"(insert("USA", "...");)" << std::endl;
	for (auto country : countries) {
		std::cout << "\t\t" << country << ": " << gazetteer.getInfo(country) << std::endl;
	}

	auto ret = gazetteer.insert_force("Ukraine", "New info about Ukraine.");
	std::cout << "\t" << R"(insert_force("Ukraine", "New info about Ukraine.");)" << " -> " << std::boolalpha << ret << std::endl;
	for (auto country : countries) {
		std::cout << "\t\t" << country << ": " << gazetteer.getInfo(country) << std::endl;
	}
}


void testGazetteerBad() {
	auto gazetteer = Gazetteer();
	gazetteer.insert("Ukraine", "Ukraine is a country in Eastern Europe. It is bordered by Russia to the east and north-east; Belarus to the north; Poland, Slovakia and Hungary to the west; and Romania, Moldova, Crimea, and the Black Sea to the south. Including Crimea, Ukraine has an area of 603,628 km², and is the second-largest country in Europe after Russia.");
	gazetteer.insert("USA", "The United States—officially the United States of America, commonly known as America—is a country primarily located in North America, consisting of 50 states, a federal district, five major self-governing territories, 326 reservations, and various possessions.");

	auto countries = std::vector {
		"Ukraine",
		"USA",
		"Spain",
		"China",
		"India"
	};
	
	std::cout << "Gazetteer tests with incorrect input:" << std::endl;
	std::cout << "\t" << R"(insert("Ukraine", "...");)" << std::endl;
	std::cout << "\t" << R"(insert("USA", "...");)" << std::endl;
	for (auto country : countries) {
		std::cout << "\t\t" << country << ": " << gazetteer.getInfo(country) << std::endl;
	}

	auto ret = gazetteer.insert("Ukraine", "New info about Ukraine.");
	std::cout << "\t" << R"(insert("Ukraine", "New info about Ukraine.");)" << " -> " << std::boolalpha << ret << std::endl;
	for (auto country : countries) {
		std::cout << "\t\t" << country << ": " << gazetteer.getInfo(country) << std::endl;
	}
}


auto main() -> int {
	testGazetteerGood(); std::cout << std::endl;
	testGazetteerBad(); std::cout << std::endl;
	testGazetteerDynamicGood(); std::cout << std::endl;
	testGazetteerDynamicBad();
}	
