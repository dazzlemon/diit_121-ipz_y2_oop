#include "gazetteer_multi_tests.h"
#include "gazetteer_multi.h"
#include <iostream>

const std::string UA_SHORT1 = "Country of Eastern Europe.";
const std::string UA_SHORT2 = "Second-largest country in Europe after Russia.";

const std::string CHINA_SHORT1 = "Most populous country in the world.";
const std::string CHINA_SHORT2 = "Third-largest(by area) country in the world.";
//cert-err58-cpp

void testGazetteerMultiGood() {
	auto gazetteer = GazetteerMulti();
	auto pairs = std::vector {
		std::make_pair("Ukraine", &UA_SHORT1),
		std::make_pair("Ukraine", &UA_SHORT2),
		std::make_pair("China", &CHINA_SHORT1),
		std::make_pair("China", &CHINA_SHORT2),
	};

	std::cout << "GazetteerMulti tests with correct input:" << std::endl;
	for (auto& p : pairs) {
		gazetteer.insertInfo(p.first, *p.second);
		std::cout << "\t" << "insertInfo(\"" << p.first << "\", \"" << *p.second << "\");" << std::endl;
	}
	std::cout << std::endl;
	
	auto countries = std::vector { "Ukraine", "China" };
	auto print_countries = [&] () {
		for (const auto* country : countries) {
			auto values = gazetteer.getInfo(country);
			std::cout << "\tCountry: " << country << std::endl;
			std::cout << "\tValues:" << std::endl;
			for (size_t i = 0; i < values.size(); i++) {
				std::cout << "\t\t" << i + 1 << ". " << values[i] << std::endl;
			}
		}
	};
	print_countries();
	std::cout << "\t" << R"(removeCountry("China");)" << std::endl;
	gazetteer.removeCountry("China");
	print_countries();
}


void testGazetteerMultiBad() {
	auto gazetteer = GazetteerMulti();
	std::cout << "GazetteerMulti tests with incorrect input: " << std::endl;
	auto values = gazetteer.getInfo("China");
	std::cout << "\t" << R"(getInfo("China"); -> [)";
	for (auto value : values) {
		std::cout << value;// actually doesn't print anything, just to check that it in fact doesn't
	}
	std::cout << "]" << std::endl;
}
