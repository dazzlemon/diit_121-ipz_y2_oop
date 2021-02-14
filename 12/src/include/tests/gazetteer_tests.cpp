#include "gazetteer_tests.h"
#include "gazetteer.h"
#include <iostream>
#include <vector>

const std::string UA_LONG = "Ukraine is a country in Eastern Europe. It is bordered by Russia to the east and north-east; Belarus to the north; Poland, Slovakia and Hungary to the west; and Romania, Moldova, Crimea, and the Black Sea to the south. Including Crimea, Ukraine has an area of 603,628 km², and is the second-largest country in Europe after Russia.";
const std::string USA_LONG = "The United States—officially the United States of America, commonly known as America—is a country primarily located in North America, consisting of 50 states, a federal district, five major self-governing territories, 326 reservations, and various possessions.";
//cert-err58-cpp

void testGazetteerGood() {
	auto gazetteer = Gazetteer();
	
	gazetteer.insert("Ukraine", UA_LONG);
	gazetteer.insert("USA", USA_LONG);
	std::cout << "Gazetteer tests with correct input:" << std::endl;
	std::cout << "\t" << R"(insert("Ukraine", "...");)" << std::endl;
	std::cout << "\t" << R"(insert("USA", "...");)" << std::endl;

	auto countries = std::vector { "Ukraine", "USA" };
	auto print_countries = [&] () {
		for (const auto* country : countries) {
			std::cout << "\t\t" << country << ": " << gazetteer.getInfo(country) << std::endl;
		}
	};
	
	print_countries();
	auto ret = gazetteer.insert_force("Ukraine", "New info about Ukraine.");
	std::cout << "\t" << R"(insert_force("Ukraine", "New info about Ukraine.");)" << " -> " << std::boolalpha << ret << std::endl;
	print_countries();
}


void testGazetteerBad() {
	auto gazetteer = Gazetteer();
	gazetteer.insert("Ukraine", UA_LONG);
	gazetteer.insert("USA", USA_LONG);

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
	for (const auto* country : countries) {
		std::cout << "\t\t" << country << ": " << gazetteer.getInfo(country) << std::endl;
	}

	auto ret = gazetteer.insert("Ukraine", "New info about Ukraine.");
	std::cout << "\t" << R"(insert("Ukraine", "New info about Ukraine.");)" << " -> " << std::boolalpha << ret << std::endl;
	for (const auto* country : countries) {
		std::cout << "\t\t" << country << ": " << gazetteer.getInfo(country) << std::endl;
	}
}
