#include "gazetteer_tests.h"
#include "gazetteer_multi_tests.h"
#include <iostream>

auto main() -> int {
	testGazetteerGood(); std::cout << std::endl;
	testGazetteerBad(); std::cout << std::endl;
	testGazetteerMultiGood(); std::cout << std::endl;
	testGazetteerMultiBad();
}	
